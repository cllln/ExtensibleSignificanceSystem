// Copyright Chengll, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExtensibleSignificanceManager.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ExtensibleSignificanceSubsystem.generated.h"

/**
 * Extensible Significance subsystem, monitor the creation and Destroy of Actor objects, and add concerned Actors to the Significance Manager.
 */
UCLASS()
class EXTENSIBLESIGNIFICANCESYSTEM_API UExtensibleSignificanceSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = ExtensibleSignificance)
	static UExtensibleSignificanceSubsystem* GetSubsystem(const UObject* WorldContext);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	
	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

	virtual void Tick(float DeltaTime) override;
	
	virtual TStatId GetStatId() const override;

	const struct FSignificanceSettingForSpecifyClass* GetSignificanceSettingForSpecifyClassByTag(const FName Tag);
	
	const FSignificanceSettingForSpecifyClass* GetSignificanceSettingForSpecifyClass(const TSubclassOf<AActor>& TargetClass, int32 RecursionSuperCount = 5);

	APlayerController* GetPlayerController() const;

	class USignificanceOptimizationStrategySettings* GetSignificanceOptimizationStrategySetting();
	
protected:
	void UpdateSignificance(const float DeltaTime);
	
	UFUNCTION()
	void OnActorSpawned(AActor* SpawnedActor);

	UFUNCTION()
	void OnActorDestroyed(AActor* DestroyedActor);
	
	UFUNCTION(BlueprintCallable, Category = ExtensibleSignificance)
	void RegisterSignificance(AActor* TargetActor, const FName Tag);

	UFUNCTION(BlueprintCallable, Category = ExtensibleSignificance)
	void UnRegisterSignificance(AActor* TargetActor);

	UFUNCTION(BlueprintCallable, Category = ExtensibleSignificance)
	void UnRegisterAllSignificance();
	
protected:
	// Calculate Significance
	float CalcSignificance(USignificanceManager::FManagedObjectInfo* ObjectInfo, const FTransform& Viewpoint);

	// Handle Post Significance Change
	void HandlePostSignificanceChange(const USignificanceManager::FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bSignificanceChanged) const;

	// Handle Post Lod Change
	void HandlePostLodChange(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, int32 OldLod, int32 NewLod);

	UPROPERTY()
	USignificanceOptimizationStrategySettings* OptimizationStrategySettings; 
};
