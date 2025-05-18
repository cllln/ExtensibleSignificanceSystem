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
		if (bSkipMovementComponent && TempComponent->IsA(UMovementComponent::StaticClass()))
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


	TargetActor->SetActorHiddenInGame(bHideActor);
	for (UActorComponent* TempComponent : TargetActor->GetComponents())
	{
		if (USkinnedMeshComponent* MeshComponent = Cast<USkinnedMeshComponent>(TempComponent))
		{
			MeshComponent->SetVisibility(!bHideMesh);
		}
		else if (UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(TempComponent))
		{
			StaticMeshComponent->SetVisibility(!bHideMesh);
		}
		else if (UChildActorComponent* ChildActorComponent = Cast<UChildActorComponent>(TempComponent))
		{
			ChildActorComponent->SetVisibility(!bHideChildActorComp);
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
			SkinMeshComponent->VisibilityBasedAnimTickOption = VisibilityBasedAnimTickOption;

			//默认为4。当更新率（DesiredEvaluationRate）小于这个值时，允许内插，大于或等于则不允许内插。0相当于完全禁用内插。
			if (SkinMeshComponent->AnimUpdateRateParams)
			{
				SkinMeshComponent->AnimUpdateRateParams->MaxEvalRateForInterpolation = MaxEvalRateForInterpolation; 
			}
		}
	}
}

