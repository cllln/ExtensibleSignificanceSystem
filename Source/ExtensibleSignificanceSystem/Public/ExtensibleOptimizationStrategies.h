// Copyright Chengll, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkinnedMeshComponent.h"
#include "ExtensibleSignificanceManager.h"
#include "ExtensibleOptimizationStrategies.generated.h"

/**
 * Optimization Strategy Base Class
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew)
class EXTENSIBLESIGNIFICANCESYSTEM_API UExtensibleOptimizationStrategyBase : public UObject
{
	GENERATED_BODY()
	
public:

	/* Handle Optimization Strategy, Subclass inheritance override*/
	virtual void HandleOptimization(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod);

	/* Blueprint Fuc*/
	UFUNCTION(BlueprintImplementableEvent)
	void OnReceiveHandleOptimization(const UObject* TargetObject, const int32 OldLod, const int32 NewLod, const int32 ShouldBeLod, const float Significance);
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
	UPROPERTY(EditDefaultsOnly, Category = TickIntervalOptimization)
	bool bSkipMovementComponent = true;
	
	/* Tick Interval*/ 
	UPROPERTY(EditDefaultsOnly, Category = TickIntervalOptimization)
	float ActorTickInterval = 0.0f;

	/* Tick interval offset, mainly to spread out a little more*/
	UPROPERTY(EditDefaultsOnly, Category = TickIntervalOptimization)
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

	// Should Set Actor Visibility
	UPROPERTY(EditDefaultsOnly, Category = VisibilityOptimization, meta = (InlineEditConditionToggle))
	bool bShouldSetActorVisibility = false;
	
	// Whether Hide Actor
	UPROPERTY(EditDefaultsOnly, Category = VisibilityOptimization, meta = (EditCondition = "bShouldSetActorVisibility"))
	bool bHideActor = true;

	// Should Set Mesh Visibility
	UPROPERTY(EditDefaultsOnly, Category = VisibilityOptimization, meta = (InlineEditConditionToggle))
	bool bShouldSetMeshVisibility = false;
	
	// Whether Hide Mesh
	UPROPERTY(EditDefaultsOnly, Category = VisibilityOptimization, meta = (EditCondition = "bShouldSetMeshVisibility"))
	bool bHideMesh = true;

	// Should Set Child Actor Component Visibility
	UPROPERTY(EditDefaultsOnly, Category = VisibilityOptimization, meta = (InlineEditConditionToggle))
	bool bShouldSetChildActorCompVisibility = false;
	
	// Whether Hide Child Actor Component
	UPROPERTY(EditDefaultsOnly, Category = VisibilityOptimization, meta = (EditCondition = "bShouldSetChildActorCompVisibility"))
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

	/** Whether to skip UpdateKinematicBonesToAnim() when interpolating. Kinematic bones are updated to the target interpolation pose only on ticks when they are evaluated. */
	UPROPERTY(EditDefaultsOnly, Category = AnimationOptimization)
	bool bSkipKinematicUpdateWhenInterpolating = false;

	/** Whether to skip bounds update when interpolating. Bounds are updated to the target interpolation pose only on ticks when they are evaluated. */
	UPROPERTY(EditDefaultsOnly, Category = AnimationOptimization)
	bool bSkipBoundsUpdateWhenInterpolating = false;
	
	/*
	 * This is tick animation frequency option based on this component rendered or not or using montage
	 *  You can change this default value in the INI file 
	 * Mostly related with performance
	 */
	UPROPERTY(EditDefaultsOnly, Category = AnimationOptimization)
	EVisibilityBasedAnimTickOption VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;

	/** When true, skip using the physics asset etc. and always use the fixed bounds defined in the SkeletalMesh. */
	UPROPERTY(EditDefaultsOnly, Category = AnimationOptimization)
	bool bComponentUseFixedSkelBounds = false;

	/** If true, when updating bounds from a PhysicsAsset, consider _all_ BodySetups, not just those flagged with bConsiderForBounds. */
	UPROPERTY(EditDefaultsOnly, Category = AnimationOptimization)
	bool bConsiderAllBodiesForBounds = false;
	
	// Code supported by UE 5.5 and above
	/** 
	 * If set, use the screen render flag instead of the default render flag when processing offscreen-rendering optimizations 
	 * (such as VisibilityBasedAnimTickOption) that look to reduce animation work when the mesh is not rendered. 
	 * Using this option can result in meshes that are occlusion culled ceasing to perform animation work.
	 * Note that this can however result in shadows not being animated when meshes are not directly visible.
	 */
	UPROPERTY(EditDefaultsOnly, Category = AnimationOptimization)
	bool bUseScreenRenderStateForUpdate = false;

	// Update Rate
	/** if TRUE, Owner will determine how often animation will be updated and evaluated. See AnimUpdateRateTick() 
	 * This allows to skip frames for performance. (For example based on visibility and size on screen). */
	UPROPERTY(EditDefaultsOnly, Category = AnimationOptimization)
	bool bEnableUpdateRateOptimizations = false;

	/**
	 *	If true, render as static in reference pose.
	 */
	UPROPERTY(EditDefaultsOnly, Category = AnimationOptimization)
	bool bRenderStatic = false;

	/**
	 * Max Evaluation Rate allowed for interpolation to be enabled. Beyond, interpolation will be turned off.
	 */
	UPROPERTY(EditDefaultsOnly, Category = AnimationOptimization)
	int32 MaxEvalRateForInterpolation = 4;

	/** Rate of animation evaluation when non rendered (off screen and dedicated servers).
	 * a value of 4 means evaluated 1 frame, then 3 frames skipped
	 */
	UPROPERTY(EditDefaultsOnly, Category = AnimationOptimization)
	int32 BaseNonRenderedUpdateRate = 4;
};
