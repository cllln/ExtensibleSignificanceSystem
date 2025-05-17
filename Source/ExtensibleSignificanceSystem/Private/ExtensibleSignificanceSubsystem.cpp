// Fill out your copyright notice in the Description page of Project Settings.


#include "ExtensibleSignificanceSubsystem.h"

#include "EngineUtils.h"
#include "ExtensibleSignificanceSystem.h"
#include "GameFramework/MovementComponent.h"
#include "Kismet/GameplayStatics.h"


DECLARE_CYCLE_STAT(TEXT("Significance Get Specify Class"), STAT_ExtensibleSignificanceManager_GetSpecifyClass, STATGROUP_SignificanceManager);

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

void UExtensibleSignificanceSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	// 对已经生成的Actor处理
	for (TActorIterator<AActor> It(World, AActor::StaticClass()); It; ++It)
	{
		OnActorSpawned(*It);
	}

	// 注册新生成的Actor的创建广播
	World->AddOnActorSpawnedHandler(FOnActorSpawned::FDelegate::CreateUObject(this, &ThisClass::OnActorSpawned));
}

void UExtensibleSignificanceSubsystem::Deinitialize()
{
	Super::Deinitialize();

	UnRegisterAllSignificance();
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

const FSignificanceSettingForSpecifyClass* UExtensibleSignificanceSubsystem::GetSignificanceSettingForSpecifyClass(const TSubclassOf<AActor>& TargetClass, int32 RecursionSuperCount)
{
	SCOPE_CYCLE_COUNTER(STAT_ExtensibleSignificanceManager_GetSpecifyClass);
	if (TargetClass == nullptr)
	{
		return nullptr;
	}
	
	const UExtensibleSignificanceSettings* ExtensibleSignificanceSettings = GetDefault<UExtensibleSignificanceSettings>();
    if (!ExtensibleSignificanceSettings)
    {
    	return nullptr;
    }

	UClass* QueryClass = TargetClass;
	for(int32 Index = 0; Index <= RecursionSuperCount; Index++)
	{
		const FSoftClassPath ClassPath(QueryClass);
		if (const FSignificanceSettingForSpecifyClass* SignificanceSettingForSpecifyClass = ExtensibleSignificanceSettings->SignificanceSettings.Find(ClassPath))
		{
			return SignificanceSettingForSpecifyClass;
		}

		QueryClass = QueryClass->GetSuperClass();
		if (QueryClass == nullptr || QueryClass == AActor::StaticClass())
		{
			break;
		}
	}

	return nullptr;
}

APlayerController* UExtensibleSignificanceSubsystem::GetPlayerController() const
{
	return UGameplayStatics::GetPlayerController(GetWorld(), 0);
}

void UExtensibleSignificanceSubsystem::UpdateSignificance(const float DeltaTime)
{
	const EViewPointType ViewPointType = UExtensibleSignificanceManager::GetSignificanceSystemSetting().ViewPointType;
	if (ViewPointType == EViewPointType::None)
	{
		return;
	}

	if (!UExtensibleSignificanceManager::GetSignificanceSystemSetting().ShouldCheck(DeltaTime))
	{
		return;
	}
		
	// 确保具有有效的世界场景和Significance Manager实例。
	if (UExtensibleSignificanceManager* Manager = UExtensibleSignificanceManager::GetExtensibleSignificanceManager(this))
	{
		if (APlayerController* PlayerController = GetPlayerController())
		{
			// Significance Manager使用ArrayView。构造单元素数组来容纳Transform。
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

			// 使用通过ArrayView传入的单元素数组来更新Significance Manager。
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
		const EViewPointType ViewPointType = UExtensibleSignificanceManager::GetSignificanceSystemSetting().ViewPointType;
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
					// Lod没有修改就不做处理了
					if (OldLod == NewLod)
					{
						return;
					}

					HandlePostLodChange(ObjectInfo, OldLod, NewLod);
				};
			
			const USignificanceManager::FManagedObjectPostSignificanceFunction PostSignificanceFunction =
				[this](USignificanceManager::FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bSignificanceChanged)
				{
					// 重要性没有修改就不做处理了
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
		const EViewPointType ViewPointType = UExtensibleSignificanceManager::GetSignificanceSystemSetting().ViewPointType;
		if (ViewPointType == EViewPointType::None)
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
	const EViewPointType ViewPointType = UExtensibleSignificanceManager::GetSignificanceSystemSetting().ViewPointType;
	if (ViewPointType == EViewPointType::None)
	{
		return;
	}
	
	if (UExtensibleSignificanceManager* Manager = UExtensibleSignificanceManager::GetExtensibleSignificanceManager(this))
	{
		Manager->UnRegisterAllSignificance();
	}
}

float UExtensibleSignificanceSubsystem::CalcSignificance(const USignificanceManager::FManagedObjectInfo* ObjectInfo, const FTransform& Viewpoint) const
{
	float OutSignificance = 0.0f;
	if (!ObjectInfo) return OutSignificance;
	
	if (const AActor* TargetActor = Cast<AActor>(ObjectInfo->GetObject()))
	{
		// if (const FSignificanceSettingForSpecifyClass* SignificanceSettingForSpecifyClass = GetSignificanceSettingForSpecifyClass(TargetActor->GetClass()))
		// {
			// 与视口的距离条件。
			OutSignificance = FVector::Dist(Viewpoint.GetLocation(), TargetActor->GetActorLocation());

			// // 是否在窗口渲染，影响因子
			// if (TargetActor->WasRecentlyRendered(0.1f))
			// {
			// 	OutSignificance -= SignificanceSettingForSpecifyClass->RenderFactor;
			// }
		// }
	}
	return OutSignificance;
}

void UExtensibleSignificanceSubsystem::HandlePostSignificanceChange(const USignificanceManager::FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bSignificanceChanged) const
{
	// 重要度变化不处理了，走LOD的变化处理。
}

void UExtensibleSignificanceSubsystem::HandlePostLodChange(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod)
{
	if (AActor* TargetActor = Cast<AActor>(ObjectInfo->GetObject()))
	{
		if (const FSignificanceSettingForSpecifyClass* SignificanceSettingForSpecifyClass = GetSignificanceSettingForSpecifyClass(TargetActor->GetClass()))
		{
			if (SignificanceSettingForSpecifyClass->BucketSettings.IsValidIndex(NewLod))
			{
				const FSignificanceBucketSetting& SignificanceBucketSetting = SignificanceSettingForSpecifyClass->BucketSettings[NewLod];

				const float TickInterval = SignificanceBucketSetting.ActorTickInterval + FMath::FRandRange(-SignificanceBucketSetting.TickIntervalOffset, SignificanceBucketSetting.TickIntervalOffset);
				SetTargetActorTickInterval(TargetActor, TickInterval, ObjectInfo->ShouldBeLOD);

				SetMeshVisibility(TargetActor, SignificanceBucketSetting.bShowMesh);
				
				SetAnimTickOptimize(TargetActor, SignificanceBucketSetting.bOptimizeAnim);
			}
		}
	}		
}

void UExtensibleSignificanceSubsystem::SetTargetActorTickInterval(AActor* TargetActor, const float TickInterval, const int32 ShouldBeLod)
{
	if (!IsValid(TargetActor))
	{
		return;
	}
	
	// 设置tick间隔
	TargetActor->SetActorTickInterval(TickInterval);
	for (UActorComponent* TempComponent : TargetActor->GetComponents())
	{
		// 原本应该在最高优先级的桶中的Actor，不要修改移动的tick了，最高优先级桶中的对象极有可能在屏幕内，如果降低tick会很明显看到移动不平滑。
		if (/*ShouldBeLod == 0 && !FMath::IsNearlyZero(TickInterval) &&*/ TempComponent->IsA(UMovementComponent::StaticClass()))
		{
			continue;
		}
		
		float FinalTickInterval = TickInterval;
		if (const UActorComponent* DefaultObject = Cast<UActorComponent>(TempComponent->GetClass()->GetDefaultObject()))
		{
			FinalTickInterval = FMath::Max(FinalTickInterval, DefaultObject->GetComponentTickInterval());
		}
		TempComponent->SetComponentTickIntervalAndCooldown(FinalTickInterval);
	}
}

void UExtensibleSignificanceSubsystem::SetAnimTickOptimize(AActor* TargetActor, const bool bOptimize)
{
	if (!IsValid(TargetActor))
	{
		return;
	}
	
	for (UActorComponent* TempComponent : TargetActor->GetComponents())
	{
		if (USkinnedMeshComponent* SkinMeshComponent = Cast<USkinnedMeshComponent>(TempComponent))
		{
			if (bOptimize)
			{
				SkinMeshComponent->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;

				//默认为4。当更新率（DesiredEvaluationRate）小于这个值时，允许内插，大于或等于则不允许内插。0相当于完全禁用内插。
				if (SkinMeshComponent->AnimUpdateRateParams)
				{
					SkinMeshComponent->AnimUpdateRateParams->MaxEvalRateForInterpolation = 0; 
				}
			}
			else
			{
				if (const USkinnedMeshComponent* DefaultObject = Cast<USkinnedMeshComponent>(SkinMeshComponent->GetClass()->GetDefaultObject()))
				{
					SkinMeshComponent->VisibilityBasedAnimTickOption = DefaultObject->VisibilityBasedAnimTickOption;
					
					if (SkinMeshComponent->AnimUpdateRateParams)
					{
						SkinMeshComponent->AnimUpdateRateParams->MaxEvalRateForInterpolation = 3; 	
					}
				}	
			}
		}
	}
}

void UExtensibleSignificanceSubsystem::SetMeshVisibility(AActor* TargetActor, const bool bVisibility)
{
	if (!IsValid(TargetActor))
	{
		return;
	}
	
	for (UActorComponent* TempComponent : TargetActor->GetComponents())
	{
		if (USkinnedMeshComponent* MeshComponent = Cast<USkinnedMeshComponent>(TempComponent))
		{
			MeshComponent->SetVisibility(bVisibility);
		}
		else if (UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(TempComponent))
		{
			StaticMeshComponent->SetVisibility(bVisibility);
		}
		else if (UChildActorComponent* ChildActorComponent = Cast<UChildActorComponent>(TempComponent))
		{
			ChildActorComponent->SetVisibility(bVisibility);
		}
	}
}

