// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExtensibleSignificanceManager.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ExtensibleSignificanceSubsystem.generated.h"

/**
 * 重要度管理子系统，监听Actor对象的创建销毁，将关心的Actor添加到重要度管理器里。
 */
UCLASS()
class EXTENSIBLESIGNIFICANCESYSTEM_API UExtensibleSignificanceSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	
	UFUNCTION(BlueprintCallable, Category = ExtensibleSignificance)
	static UExtensibleSignificanceSubsystem* GetSubsystem(const UObject* WorldContext);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	
	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

	virtual void Tick(float DeltaTime) override;
	
	virtual TStatId GetStatId() const override;

	const FSignificanceSettingForSpecifyClass* GetSignificanceSettingForSpecifyClass(const TSubclassOf<AActor>& TargetClass, int32 RecursionSuperCount = 5);

	APlayerController* GetPlayerController() const;
	
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
	// 计算重要度
	float CalcSignificance(const USignificanceManager::FManagedObjectInfo* ObjectInfo, const FTransform& Viewpoint) const;

	// 处理重要度变化
	void HandlePostSignificanceChange(const USignificanceManager::FManagedObjectInfo* ObjectInfo, float OldSignificance, float NewSignificance, bool bSignificanceChanged) const;

	// 处理Lod变化
	void HandlePostLodChange(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, int32 OldLod, int32 NewLod);

	UPROPERTY()
	USignificanceOptimizationStrategySettings* OptimizationStrategySettings; 
};
