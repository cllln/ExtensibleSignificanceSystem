// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtensibleOptimizationStrategies.h"
#include "GameFramework/MovementComponent.h"


void UExtensibleOptimizationStrategyBase::HandleOptimization(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod)
{
	OnReceiveHandleOptimization(ObjectInfo->GetObject(), OldLod, NewLod, ObjectInfo->ShouldBeLOD, ObjectInfo->GetSignificance());
}

void UTickIntervalOptimizationStrategy::HandleOptimization(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod)
{
	const float TickInterval = ActorTickInterval + FMath::FRandRange(-TickIntervalOffset, TickIntervalOffset);

	if (AActor* TargetActor = Cast<AActor>(ObjectInfo->GetObject()))
	{
		SetTargetActorTickInterval(TargetActor, TickInterval);	
	}
}

void UTickIntervalOptimizationStrategy::SetTargetActorTickInterval(AActor* TargetActor, const float TickInterval) const
{
	if (!IsValid(TargetActor))
	{
		return;
	}
	
	// Set tick interval
	TargetActor->SetActorTickInterval(TickInterval);
	for (UActorComponent* TempComponent : TargetActor->GetComponents())
	{
		// Objects in the screen, if you lower the tick, you will obviously see that the movement is not smooth
		if (bSkipMovementComponent && TargetActor->WasRecentlyRendered(0.01f) && TempComponent->IsA(UMovementComponent::StaticClass()))
		{
			TempComponent->SetComponentTickIntervalAndCooldown(0.0f);
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

void UVisibilityOptimizationStrategy::HandleOptimization(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod)
{
	if (AActor* TargetActor = Cast<AActor>(ObjectInfo->GetObject()))
	{
		SetVisibility(TargetActor);	
	}
}

void UVisibilityOptimizationStrategy::SetVisibility(AActor* TargetActor) const
{
	if (!IsValid(TargetActor))
	{
		return;
	}


	if (bShouldSetActorVisibility)
	{
		TargetActor->SetActorHiddenInGame(bHideActor);	
	}
	for (UActorComponent* TempComponent : TargetActor->GetComponents())
	{
		if (bShouldSetMeshVisibility)
		{
			if (USkinnedMeshComponent* MeshComponent = Cast<USkinnedMeshComponent>(TempComponent))
			{
				MeshComponent->SetVisibility(!bHideMesh);
			}
			else if (UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(TempComponent))
			{
				StaticMeshComponent->SetVisibility(!bHideMesh);
			}
		}

		if (bShouldSetChildActorCompVisibility)
		{
			if (UChildActorComponent* ChildActorComponent = Cast<UChildActorComponent>(TempComponent))
			{
				ChildActorComponent->SetVisibility(!bHideChildActorComp);
			}	
		}
	}
}

void UAnimationOptimizationStrategy::HandleOptimization(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const int32 OldLod, const int32 NewLod)
{
	if (AActor* TargetActor = Cast<AActor>(ObjectInfo->GetObject()))
	{
		SetAnimOptimization(TargetActor);	
	}
}

void UAnimationOptimizationStrategy::SetAnimOptimization(AActor* TargetActor) const
{
	if (!IsValid(TargetActor))
	{
		return;
	}
	
	for (UActorComponent* TempComponent : TargetActor->GetComponents())
	{
		if (USkinnedMeshComponent* SkinMeshComponent = Cast<USkinnedMeshComponent>(TempComponent))
		{
			if (USkeletalMeshComponent* SkeletalMeshComponent = Cast<USkeletalMeshComponent>(SkinMeshComponent))
			{
				SkeletalMeshComponent->bSkipKinematicUpdateWhenInterpolating = bSkipKinematicUpdateWhenInterpolating;
				SkeletalMeshComponent->bSkipBoundsUpdateWhenInterpolating = bSkipBoundsUpdateWhenInterpolating;
			}
			
			SkinMeshComponent->VisibilityBasedAnimTickOption = VisibilityBasedAnimTickOption;
			SkinMeshComponent->bComponentUseFixedSkelBounds = bComponentUseFixedSkelBounds;
			SkinMeshComponent->bConsiderAllBodiesForBounds = bConsiderAllBodiesForBounds;

#if ENGINE_MAJOR_VERSION > 5 || (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 5)
			// Code supported by UE 5.5 and above
			SkinMeshComponent->bUseScreenRenderStateForUpdate = bUseScreenRenderStateForUpdate;
#endif
			SkinMeshComponent->bEnableUpdateRateOptimizations = bEnableUpdateRateOptimizations;
			SkinMeshComponent->bRenderStatic = bRenderStatic;
			
			//The default is 4. When the update rate (DesiredEvaluationRate) is less than this value, interpolation is allowed, and if it is greater than or equal, interpolation is not allowed. 0 is equivalent to completely disabling interpolation.
			if (SkinMeshComponent->AnimUpdateRateParams)
			{
				SkinMeshComponent->AnimUpdateRateParams->MaxEvalRateForInterpolation = MaxEvalRateForInterpolation;
				SkinMeshComponent->AnimUpdateRateParams->BaseNonRenderedUpdateRate = BaseNonRenderedUpdateRate;
			}
		}
	}
}

