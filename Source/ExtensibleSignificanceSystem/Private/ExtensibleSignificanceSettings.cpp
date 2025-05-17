// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtensibleSignificanceSettings.h"

bool FSignificanceSystemSetting::ShouldCheck(const float DeltaTime)
{
	bool bShouldCheck = false;
	CheckRemainTime -= DeltaTime;
	if (CheckRemainTime <= 0)
	{
		bShouldCheck = true;
		CheckRemainTime = TickInterval;
	}

	return bShouldCheck;
}

int32 FSignificanceSettingForSpecifyClass::GetBucketIndex(const int32 Index, const float Dist, int32& OutShouldBeLod) const
{
	int32 TotalIndex = 0;
	int32 BucketIndex = -1;
	OutShouldBeLod = BucketSettings.Num() - 1;
	for (const FSignificanceBucketSetting &Element : BucketSettings)
	{
		BucketIndex++;
		TotalIndex += Element.BucketSize;
		if (Dist <= Element.Distance)
		{
			if (BucketIndex < OutShouldBeLod)
			{
				OutShouldBeLod = BucketIndex;
			}
			
			if (Index < TotalIndex)
			{
				return BucketIndex;
			}	
		}
	}
	
	return BucketSettings.Num() - 1;
}

UExtensibleSignificanceSettings::UExtensibleSignificanceSettings()
{
	CategoryName = TEXT("Plugins");
}
