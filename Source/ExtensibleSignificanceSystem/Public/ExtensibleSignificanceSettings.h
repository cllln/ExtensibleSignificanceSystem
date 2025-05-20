// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreTypes.h"
#include "ExtensibleSignificanceSettings.generated.h"

UENUM()
enum class EViewPointType : uint8
{
	// None，No Significance calculations
	None = 0,
	// View Point is Camera
	Camera,
	// View Point is Player
	Player,
	// View Point Both Camera and Player
	Both,
};

USTRUCT(Blueprintable, BlueprintType)
struct FSignificanceSystemSetting
{
	GENERATED_BODY()

	static FSignificanceSystemSetting* GetSignificanceSystemSetting();

	static EViewPointType GetViewPointType();

	static bool ShouldUpdateSignificance(const float DeltaTime);
	
	// Tick Interval
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystemSetting)
	float TickInterval = 0.1f;
	
	// View Point Type
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	EViewPointType ViewPointType = EViewPointType::Player; 

protected:
	bool ShouldCheck(const float DeltaTime);
	
private:

	float CheckRemainTime = 0.f;
};

// Significance Bucket Setting
USTRUCT(BlueprintType)
struct FSignificanceBucketSetting
{
	GENERATED_BODY()

	// Max Object Num in This Bucket
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = SignificanceSystem)
	int32 BucketSize = 5;

	// Current Bucket Significance Limit
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = SignificanceSystem)
	float SignificanceLimit = 1500.0f;

	// Current Bucket Optimization Strategies
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = SignificanceSystem, Instanced)
	TArray<class UExtensibleOptimizationStrategyBase*> OptimizationStrategies;
};


USTRUCT(Blueprintable, BlueprintType)
struct FSignificanceSettingForSpecifyClass
{
	GENERATED_BODY()

	// Tag
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = SignificanceSystem)
	FName Tag;

	// Significance Calculate Strategies
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = SignificanceSystem, Instanced)
	TArray<class USignificanceCalculateStrategyBase*> SignificanceCalculateStrategies;
	
	// Bucket Settings
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = SignificanceSystem)
	TArray<FSignificanceBucketSetting> BucketSettings;

	int32 GetBucketIndex(const int32 Index, const float Significance, int32& OutShouldBeLod) const;
};

UCLASS(Blueprintable, BlueprintType, Abstract)
class USignificanceOptimizationStrategySettings : public UObject
{
	GENERATED_BODY()

public:
	const FSignificanceSettingForSpecifyClass* GetSignificanceSettingForSpecifyClassByTag(const FName Tag);
	
	const FSignificanceSettingForSpecifyClass* GetSignificanceSettingForSpecifyClass(const TSubclassOf<AActor>& TargetClass, const int32 RecursionSuperCount = 5);
	
protected:
	UPROPERTY(EditAnywhere, Category = SignificanceSystem, meta=(AllowAbstract))
	TMap<FSoftClassPath, FSignificanceSettingForSpecifyClass> SignificanceSettings;

private:
	UPROPERTY(Transient)
	TMap<FName, FSignificanceSettingForSpecifyClass> SignificanceSettingsByTag;
};

/**
 * Default settings for the Extensible Significance
 */
UCLASS(config = Plugins, defaultconfig, meta = (DisplayName = "Extensible Significance Settings"))
class EXTENSIBLESIGNIFICANCESYSTEM_API UExtensibleSignificanceSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UExtensibleSignificanceSettings();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	FSignificanceSystemSetting SignificanceSystemSetting;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	TSubclassOf<USignificanceOptimizationStrategySettings> OptimizationStrategySettingsClass;
};
