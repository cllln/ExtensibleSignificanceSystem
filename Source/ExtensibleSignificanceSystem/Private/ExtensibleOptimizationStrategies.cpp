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
