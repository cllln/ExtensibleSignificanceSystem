// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtensibleSignificanceSubsystem.h"

#include "EngineUtils.h"
#include "ExtensibleOptimizationStrategies.h"
#include "ExtensibleSignificanceSettings.h"
#include "ExtensibleSignificanceSystem.h"
#include "SignificanceCalculateStrategies.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"


DECLARE_CYCLE_STAT(TEXT("Significance Get Specify Class"), STAT_ExtensibleSignificanceManager_GetSpecifyClass, STATGROUP_SignificanceManager);

UExtensibleSignificanceSubsystem* UExtensibleSignificanceSubsystem::GetSubsystem(const UObject* WorldContext)
{
	check(WorldContext);
	if (!WorldContext)
	{
		return nullptr;
	}
	
	const UWorld* World = WorldContext->GetWorld();
	if (!World)
	{
		UE_LOG(LogExtensibleSignificanceSystem, Error, TEXT("UExtensibleSignificanceSubsystem::GetSubsystem Context[%s] is not a world object!"), *WorldContext->GetFullName())
		return nullptr;
	}
	return World->GetSubsystem<UExtensibleSignificanceSubsystem>();
}

void UExtensibleSignificanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UExtensibleSignificanceSubsystem::Deinitialize()
{
	Super::Deinitialize();

	UnRegisterAllSignificance();
}

bool UExtensibleSignificanceSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	if (!Super::ShouldCreateSubsystem(Outer))
	{
		return false;
	}
	
	const UWorld* OuterWorld = Outer->GetWorld();
	check(OuterWorld);
	
	const ENetMode NetMode = OuterWorld->GetNetMode();
	return NetMode != NM_DedicatedServer;
}

void UExtensibleSignificanceSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	const UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	// Processing the Spawned actor
	for (TActorIterator<AActor> It(World, AActor::StaticClass()); It; ++It)
	{
		OnActorSpawned(*It);
	}
	
	World->AddOnActorSpawnedHandler(FOnActorSpawned::FDelegate::CreateUObject(this, &ThisClass::OnActorSpawned));
}

bool UExtensibleSignificanceSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE;
}

void UExtensibleSignificanceSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateSignificance(DeltaTime);
}

TStatId UExtensibleSignificanceSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UExtensibleSignificanceSubsystem, STATGROUP_Tickables);
}

const FSignificanceSettingForSpecifyClass* UExtensibleSignificanceSubsystem::GetSignificanceSettingForSpecifyClassByTag(const FName Tag)
{
	USignificanceOptimizationStrategySettings* RestoredOptimizationStrategySettings = GetSignificanceOptimizationStrategySetting();
	if (!OptimizationStrategySettings)
	{
		return nullptr;	
	}
	
	return RestoredOptimizationStrategySettings->GetSignificanceSettingForSpecifyClassByTag(Tag);
}

const FSignificanceSettingForSpecifyClass* UExtensibleSignificanceSubsystem::GetSignificanceSettingForSpecifyClass(const TSubclassOf<AActor>& TargetClass, const int32 RecursionSuperCount)
{
	SCOPE_CYCLE_COUNTER(STAT_ExtensibleSignificanceManager_GetSpecifyClass);
	if (TargetClass == nullptr)
	{
		return nullptr;
	}
	
	USignificanceOptimizationStrategySettings* RestoredOptimizationStrategySettings = GetSignificanceOptimizationStrategySetting();
	if (!OptimizationStrategySettings)
	{
		return nullptr;	
	}
	
	return RestoredOptimizationStrategySettings->GetSignificanceSettingForSpecifyClass(TargetClass, RecursionSuperCount);
}

APlayerController* UExtensibleSignificanceSubsystem::GetPlayerController() const
{
	return UGameplayStatics::GetPlayerController(GetWorld(), 0);
}

USignificanceOptimizationStrategySettings* UExtensibleSignificanceSubsystem::GetSignificanceOptimizationStrategySetting()
{
	if (!OptimizationStrategySettings)
	{
		const UExtensibleSignificanceSettings* ExtensibleSignificanceSettings = GetDefault<UExtensibleSignificanceSettings>();
		if (!ExtensibleSignificanceSettings || !ExtensibleSignificanceSettings->OptimizationStrategySettingsClass)
		{
			return nullptr;
		}
		
		OptimizationStrategySettings = NewObject<USignificanceOptimizationStrategySettings>(this, ExtensibleSignificanceSettings->OptimizationStrategySettingsClass, FName("OptimizationStrategySettings"));
	}
	
	return OptimizationStrategySettings;
}

void UExtensibleSignificanceSubsystem::UpdateSignificance(const float DeltaTime)
{
	const EViewPointType ViewPointType = FSignificanceSystemSetting::GetViewPointType();
	if (ViewPointType == EViewPointType::None)
	{
		return;
	}

	if (!FSignificanceSystemSetting::ShouldUpdateSignificance(DeltaTime))
	{
		return;
	}
	
	if (UExtensibleSignificanceManager* Manager = UExtensibleSignificanceManager::GetExtensibleSignificanceManager(this))
	{
		if (const APlayerController* PlayerController = GetPlayerController())
		{
			TArray<FTransform> TransformArray;
			if (ViewPointType == EViewPointType::Both || ViewPointType == EViewPointType::Camera)
			{
				FVector ViewLocation;
				FRotator ViewRotation;
				PlayerController->GetPlayerViewPoint(ViewLocation, ViewRotation);
				TransformArray.Add(FTransform(ViewRotation, ViewLocation));
			}

			if (ViewPointType == EViewPointType::Both || ViewPointType == EViewPointType::Player)
			{
				if (const APawn* ControlledPawn = PlayerController->GetPawnOrSpectator())
				{
					TransformArray.Add(ControlledPawn->GetTransform());
				}
			}
			
			Manager->Update(TArrayView<FTransform>(TransformArray));
		}
	}
}

void UExtensibleSignificanceSubsystem::OnActorSpawned(AActor* SpawnedActor)
{
	if (!SpawnedActor)
	{
		return;
	}
	
	if (const FSignificanceSettingForSpecifyClass* SignificanceSettingForSpecifyClass = GetSignificanceSettingForSpecifyClass(SpawnedActor->GetClass()))
	{
		SpawnedActor->OnDestroyed.AddUniqueDynamic(this, &ThisClass::OnActorDestroyed);
		RegisterSignificance(SpawnedActor, SignificanceSettingForSpecifyClass->Tag);
	}	
}

void UExtensibleSignificanceSubsystem::OnActorDestroyed(AActor* DestroyedActor)
{
	if (!DestroyedActor)
	{
		return;
	}
	UnRegisterSignificance(DestroyedActor);
}


void UExtensibleSignificanceSubsystem::RegisterSignificance(AActor* TargetActor, const FName Tag)
{
	if (IsValid(TargetActor))
	{
		const EViewPointType ViewPointType = FSignificanceSystemSetting::GetViewPointType();
		if (ViewPointType == EViewPointType::None)
		{
			return;
		}
		
		if (UExtensibleSignificanceManager* Manager = UExtensibleSignificanceManager::GetExtensibleSignificanceManager(this))
		{
			const USignificanceManager::FManagedObjectSignificanceFunction SignificanceFunction =
				[this](USignificanceManager::FManagedObjectInfo* ObjectInfo, const FTransform& Viewpoint)
				{
					return CalcSignificance(ObjectInfo, Viewpoint);
				};

			const UExtensibleSignificanceManager::FManagedObjectPostLodFunction PostLodFunction =
				[this](UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, int32 OldLod, int32 NewLod)
				{
					// Lod will not be processed if it is not modified.
					if (OldLod == NewLod)
					{
						return;
					}

					HandlePostLodChange(ObjectInfo, OldLod, NewLod);
				};
			
			const USignificanceManager::FManagedObjectPostSignificanceFunction PostSignificanceFunction =
				[this](USignificanceManager::FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bSignificanceChanged)
				{
					// If the Significance is not modified, it will not be dealt with.
					if (FMath::IsNearlyEqual(OldSignificance, NewSignificance))
					{
						return;
					}

					HandlePostSignificanceChange(ObjectInfo, OldSignificance, NewSignificance, bSignificanceChanged);
				};

			Manager->CustomRegisterObject(TargetActor, Tag, SignificanceFunction, PostLodFunction, USignificanceManager::EPostSignificanceType::Sequential, PostSignificanceFunction);
		}
	}
}

void UExtensibleSignificanceSubsystem::UnRegisterSignificance(AActor* TargetActor)
{
	if (IsValid(TargetActor))
	{
		if (const EViewPointType ViewPointType = FSignificanceSystemSetting::GetViewPointType(); ViewPointType == EViewPointType::None)
		{
			return;
		}
	
		if (UExtensibleSignificanceManager* Manager = UExtensibleSignificanceManager::GetExtensibleSignificanceManager(this))
		{
			Manager->UnregisterObject(TargetActor);
		}	
	}
}

void UExtensibleSignificanceSubsystem::UnRegisterAllSignificance()
{
	if (const EViewPointType ViewPointType = FSignificanceSystemSetting::GetViewPointType(); ViewPointType == EViewPointType::None)
	{
		return;
	}
	
	if (UExtensibleSignificanceManager* Manager = UExtensibleSignificanceManager::GetExtensibleSignificanceManager(this))
	{
		Manager->UnRegisterAllSignificance();
	}
}

float UExtensibleSignificanceSubsystem::CalcSignificance(USignificanceManager::FManagedObjectInfo* ObjectInfo, const FTransform& Viewpoint)
{
	float OutSignificance = 0.0f;
	const UExtensibleSignificanceManager::FExtendedManagedObject* ExtendedManagedObject = static_cast<UExtensibleSignificanceManager::FExtendedManagedObject*>(ObjectInfo);
	if (!ExtendedManagedObject) return OutSignificance;
	
	if (const FSignificanceSettingForSpecifyClass* SignificanceSettingForSpecifyClass = GetSignificanceSettingForSpecifyClassByTag(ObjectInfo->GetTag()))
	{
		for (const auto Element : SignificanceSettingForSpecifyClass->SignificanceCalculateStrategies)
		{
			OutSignificance += Element->CalculateSignificanceFactor(ExtendedManagedObject, Viewpoint);
		}
	}

	return OutSignificance;
}

void UExtensibleSignificanceSubsystem::HandlePostSignificanceChange(const USignificanceManager::FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bSignificanceChanged) const
{
	// The change of Significance is not processed, and the change of LOD is processed.。
}

void UExtensibleSignificanceSubsystem::HandlePostLodChange(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod)
{
	if (const FSignificanceSettingForSpecifyClass* SignificanceSettingForSpecifyClass = GetSignificanceSettingForSpecifyClassByTag(ObjectInfo->GetTag()))
	{
		if (SignificanceSettingForSpecifyClass->BucketSettings.IsValidIndex(NewLod))
		{
			const FSignificanceBucketSetting& SignificanceBucketSetting = SignificanceSettingForSpecifyClass->BucketSettings[NewLod]; 
			for (const auto Element : SignificanceBucketSetting.OptimizationStrategies)
			{
				Element->HandleOptimization(ObjectInfo, OldLod, NewLod);
			}
		}
	}
}
