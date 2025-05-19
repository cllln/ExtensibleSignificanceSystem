


#include "SignificanceCalculateStrategies.h"


float USignificanceCalculateStrategyBase::CalculateSignificanceFactor(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const FTransform& Viewpoint)
{
	return OnReceiveCalculateSignificanceFactor(ObjectInfo->GetObject(), Viewpoint);
}

float USignificanceCalculateStrategyWithDistance::CalculateSignificanceFactor(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const FTransform& Viewpoint)
{
	float OutSignificanceFactor = 0;
	if (const AActor* TargetActor = Cast<AActor>(ObjectInfo->GetObject()))
	{
		// Check Distance。
		OutSignificanceFactor = FVector::Dist(Viewpoint.GetLocation(), TargetActor->GetActorLocation());
		
	}

	return OutSignificanceFactor;
}

float USignificanceCalculateStrategyWithRendered::CalculateSignificanceFactor(const UExtensibleSignificanceManager::FExtendedManagedObject* ObjectInfo, const FTransform& Viewpoint)
{
	float OutSignificanceFactor = 0;
	if (const AActor* TargetActor = Cast<AActor>(ObjectInfo->GetObject()))
	{
		// Check rendered
		if (!TargetActor->WasRecentlyRendered(RenderCheckTolerance))
		{
			OutSignificanceFactor = SignificanceFactorWithNoRendered;
		}
	}

	return OutSignificanceFactor;
}
