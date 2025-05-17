// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtensibleSignificanceManager.h"

#include "ExtensibleSignificanceSubsystem.h"

DECLARE_CYCLE_STAT(TEXT("Extensible Significance Update Total"), STAT_ExtensibleSignificanceManager_Update, STATGROUP_SignificanceManager);
DECLARE_CYCLE_STAT(TEXT("Significance Post Lod Change"), STAT_ExtensibleSignificanceManager_PostLodFunction, STATGROUP_SignificanceManager)
DECLARE_CYCLE_STAT(TEXT("Significance Lod Check"), STAT_ExtensibleSignificanceManager_LodCheck, STATGROUP_SignificanceManager);

UExtensibleSignificanceManager::UExtensibleSignificanceManager()
{
	bCreateOnServer = false;
	bSortSignificanceAscending = true;
}

void UExtensibleSignificanceManager::Update(TArrayView<const FTransform> InViewpoints)
{
	SCOPE_CYCLE_COUNTER(STAT_ExtensibleSignificanceManager_Update);
	Super::Update(InViewpoints);

	{
		SCOPE_CYCLE_COUNTER(STAT_ExtensibleSignificanceManager_PostLodFunction);
		for (const FName TempTag : RegisteredTags)
		{
			const TArray<FManagedObjectInfo*>& SortedObjects = GetManagedObjects(TempTag);
			for (int Index = 0; Index < SortedObjects.Num(); ++Index)
			{
				if (FManagedObjectInfo* ManagedObjectInfo = SortedObjects[Index]; ManagedObjectInfo && ManagedObjectInfo->GetObject())
				{
					if (const FSignificanceSettingForSpecifyClass* SignificanceSettingForSpecifyClass = UExtensibleSignificanceSubsystem::GetSignificanceSettingForSpecifyClass(ManagedObjectInfo->GetObject()->GetClass()))
					{
						if (FExtendedManagedObject* ExtObj = static_cast<FExtendedManagedObject*>(ManagedObjectInfo))
						{
							const int32 OldLOD = ExtObj->LOD;
							ExtObj->LOD = SignificanceSettingForSpecifyClass->GetBucketIndex(Index, ExtObj->GetSignificance(), ExtObj->ShouldBeLOD);

							if (ExtObj->PostLodFunction)
							{
								ExtObj->PostLodFunction(ExtObj, OldLOD, ExtObj->LOD);
							}	
						}
					}
				}
			}
		}
	}
}

void UExtensibleSignificanceManager::CustomRegisterObject(UObject* Object, FName Tag, FManagedObjectSignificanceFunction SignificanceFunction, FManagedObjectPostLodFunction InPostLodFunction, EPostSignificanceType InPostSignificanceType, FManagedObjectPostSignificanceFunction InPostSignificanceFunction)
{
	FExtendedManagedObject* ObjectInfo = new FExtendedManagedObject(Object, Tag, SignificanceFunction, InPostSignificanceType, InPostSignificanceFunction, InPostLodFunction);
	RegisterManagedObject(ObjectInfo);
	RegisteredTags.Add(Tag);
}

UExtensibleSignificanceManager* UExtensibleSignificanceManager::GetExtensibleSignificanceManager(UObject* WorldContext)
{
	check(WorldContext);
	const UWorld* World = WorldContext->GetWorld();
	if (!World)
	{
		return nullptr;
	}

	UExtensibleSignificanceManager* Manager = Get<UExtensibleSignificanceManager>(World);
	return Manager;
}

FSignificanceSystemSetting& UExtensibleSignificanceManager::GetSignificanceSystemSetting()
{
	UExtensibleSignificanceSettings* ExtensibleSignificanceSettings = GetMutableDefault<UExtensibleSignificanceSettings>();
	return ExtensibleSignificanceSettings->SignificanceSystemSetting;
}

float UExtensibleSignificanceManager::GetLod(UObject* Object) const
{
	SCOPE_CYCLE_COUNTER(STAT_ExtensibleSignificanceManager_LodCheck);
	float Significance = 0.f;
	if (const FExtendedManagedObject* Info = static_cast<const FExtendedManagedObject*>(GetManagedObject(Object)))
	{
		Significance = Info->LOD;
	}
	return Significance;
}


bool UExtensibleSignificanceManager::QueryLod(UObject* Object, int32& OutLod) const
{
	SCOPE_CYCLE_COUNTER(STAT_ExtensibleSignificanceManager_LodCheck);
	if (const FExtendedManagedObject* Info = static_cast<const FExtendedManagedObject*>(GetManagedObject(Object)))
	{
		OutLod = Info->LOD;
		return true;
	}

	OutLod = 0;
	return false;
}

void UExtensibleSignificanceManager::UnRegisterAllSignificance()
{
	for (const FName TempTag : RegisteredTags)
	{
		UnregisterAll(TempTag);
	}
	RegisteredTags.Empty();
}
