// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtensibleSignificanceSettings.h"

FSignificanceSystemSetting* FSignificanceSystemSetting::GetSignificanceSystemSetting()
{
	if (UExtensibleSignificanceSettings* ExtensibleSignificanceSettings = GetMutableDefault<UExtensibleSignificanceSettings>())
	{
		return &(ExtensibleSignificanceSettings->SignificanceSystemSetting);	
	}

	return nullptr;
}

EViewPointType FSignificanceSystemSetting::GetViewPointType()
{
	if (const FSignificanceSystemSetting* SignificanceSystemSetting = GetSignificanceSystemSetting())
	{
		return SignificanceSystemSetting->ViewPointType;
	}

	return EViewPointType::None;
}

bool FSignificanceSystemSetting::ShouldUpdateSignificance(const float DeltaTime)
{
	if (FSignificanceSystemSetting* SignificanceSystemSetting = GetSignificanceSystemSetting())
	{
		return SignificanceSystemSetting->ShouldCheck(DeltaTime);
	}

	return false;
}

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

int32 FSignificanceSettingForSpecifyClass::GetBucketIndex(const int32 Index, const float Significance, int32& OutShouldBeLod) const
{
	int32 TotalIndex = 0;
	int32 BucketIndex = -1;
	OutShouldBeLod = BucketSettings.Num() - 1;
	for (const FSignificanceBucketSetting &Element : BucketSettings)
	{
		BucketIndex++;
		TotalIndex += Element.BucketSize;
		if (Significance <= Element.SignificanceLimit)
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

const FSignificanceSettingForSpecifyClass* USignificanceOptimizationStrategySettings::GetSignificanceSettingForSpecifyClassByTag(const FName Tag)
{
	return SignificanceSettingsByTag.Find(Tag);
}

const FSignificanceSettingForSpecifyClass* USignificanceOptimizationStrategySettings::GetSignificanceSettingForSpecifyClass(const TSubclassOf<AActor>& TargetClass, const int32 RecursionSuperCount)
{
	const UClass* QueryClass = TargetClass;
	for(int32 Index = 0; Index <= RecursionSuperCount; Index++)
	{
		const FSoftClassPath ClassPath(QueryClass);
		if (const FSignificanceSettingForSpecifyClass* SignificanceSettingForSpecifyClass = SignificanceSettings.Find(ClassPath))
		{
			if (!SignificanceSettingsByTag.Find(SignificanceSettingForSpecifyClass->Tag))
			{
				SignificanceSettingsByTag.Emplace(SignificanceSettingForSpecifyClass->Tag, *SignificanceSettingForSpecifyClass);
			}
			return SignificanceSettingForSpecifyClass;
		}

		QueryClass = QueryClass->GetSuperClass();
		if (QueryClass == nullptr || QueryClass == AActor::StaticClass())
		{
			break;
		}
	}

	return nullptr;
}

UExtensibleSignificanceSettings::UExtensibleSignificanceSettings()
{
	CategoryName = TEXT("Plugins");
}
