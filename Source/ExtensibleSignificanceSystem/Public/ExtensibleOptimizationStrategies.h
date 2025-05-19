// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExtensibleSignificanceManager.h"
#include "ExtensibleOptimizationStrategies.generated.h"

/**
 * Optimization Strategy Base Class
 */
UCLASS(Abstract, BlueprintType, EditInlineNew)
class EXTENSIBLESIGNIFICANCESYSTEM_API UExtensibleOptimizationStrategyBase : public UObject
{
	GENERATED_BODY()
	
public:

	/* Handle Optimization Strategy, Subclass inheritance override*/
	virtual void HandleOptimization(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod);

	/* Blueprint Fuc*/
	UFUNCTION(BlueprintImplementableEvent)
	void OnReceiveHandleOptimization(const UObject* TargetActor, const int32 OldLod, const int32 NewLod, const int32 ShouldBeLod, const float Significance);
};

/*
 * Tick Interval Optimization Strategy
 */
UCLASS(Blueprintable)
class EXTENSIBLESIGNIFICANCESYSTEM_API UTickIntervalOptimizationStrategy : public UExtensibleOptimizationStrategyBase
{
	GENERATED_BODY()

public:
	virtual void HandleOptimization(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod) override;

	/* Set tick frequency */
	void SetTargetActorTickInterval(AActor* TargetActor, const float TickInterval) const;
	
protected:

	/* Whether to Skill Optimize the Tick of Movement Components*/
	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	bool bSkipMovementComponent = true;
	
	/* Tick Interval*/ 
	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	float ActorTickInterval = 0.0f;

	/* Tick interval offset, mainly to spread out a little more*/
	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	float TickIntervalOffset = 0.0f;
};

/*
 * Visibility Optimization Strategy
 */
UCLASS(Blueprintable)
class EXTENSIBLESIGNIFICANCESYSTEM_API UVisibilityOptimizationStrategy : public UExtensibleOptimizationStrategyBase
{
	GENERATED_BODY()

public:
	virtual void HandleOptimization(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod) override;

	void SetVisibility(AActor* TargetActor) const;
	
protected:

	// Whether Hide Actor
	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	bool bHideActor = false;
	
	// Whether Hide Mesh
	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	bool bHideMesh = true;

	// Whether Hide Child Actor Component
	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	bool bHideChildActorComp = true;
};

/*
 * Animation Optimization Strategy
 */
UCLASS(Blueprintable)
class EXTENSIBLESIGNIFICANCESYSTEM_API UAnimationOptimizationStrategy : public UExtensibleOptimizationStrategyBase
{
	GENERATED_BODY()

public:
	virtual void HandleOptimization(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod) override;

	void SetAnimOptimization(AActor* TargetActor) const;
	
protected:

	// Whether Hide Actor
	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	bool bOptimizeAnim = true;

	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	EVisibilityBasedAnimTickOption VisibilityBasedAnimTickOption;

	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	int32 MaxEvalRateForInterpolation = 4;
};
