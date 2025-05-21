// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExtensibleSignificanceManager.h"
#include "SignificanceCalculateStrategies.generated.h"

/**
 * Significance Calculate Strategy Base
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew)
class EXTENSIBLESIGNIFICANCESYSTEM_API USignificanceCalculateStrategyBase : public UObject
{
	GENERATED_BODY()

public:
	/* The Significance Factor Calculated Under The Current Strategy*/
	virtual float CalculateSignificanceFactor(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const FTransform& Viewpoint);

	/* Blueprint Fuc*/
	UFUNCTION(BlueprintImplementableEvent)
	float OnReceiveCalculateSignificanceFactor(const UObject* TargetObject, const FTransform& Viewpoint);
};

/**
 * Calculate Significance by distance
 */
UCLASS(Blueprintable)
class EXTENSIBLESIGNIFICANCESYSTEM_API USignificanceCalculateStrategyWithDistance : public USignificanceCalculateStrategyBase
{
	GENERATED_BODY()

public:
	/* The Significance Factor Calculated Under The Current Strategy*/
	virtual float CalculateSignificanceFactor(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const FTransform& Viewpoint) override;
	
};

/**
 * Calculate Significance by Rendered
 */
UCLASS(Blueprintable)
class EXTENSIBLESIGNIFICANCESYSTEM_API USignificanceCalculateStrategyWithRendered : public USignificanceCalculateStrategyBase
{
	GENERATED_BODY()

public:
	/* The Significance Factor Calculated Under The Current Strategy*/
	virtual float CalculateSignificanceFactor(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const FTransform& Viewpoint) override;

protected:
	/* not rendered time check*/ 
	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	float RenderCheckTolerance = 0.05f;
	
	/* Reduced significance for objects that are not rendered*/ 
	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem)
	float SignificanceFactorWithNoRendered = 3000.0f;
};