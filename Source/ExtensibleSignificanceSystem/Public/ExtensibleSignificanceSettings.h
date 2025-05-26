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

// Significance basic Settings, eg: tick interval, View point type.
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

// Significance settings for specify class
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

// Optimization settings
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

// Significance Optimization Setting for Maps. If you don't need to configure an optimization strategy for a specific map, just configure the default settings。
USTRUCT(Blueprintable, BlueprintType)
struct FSignificanceOptimizationSettingsWithMaps
{
	GENERATED_BODY()

	// Default Optimization settings. If you are not config Optimization for specify map in 'OptimizationStrategySettingsClassWithMap' below, we while use this default setting.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	TSoftClassPtr<USignificanceOptimizationStrategySettings> DefaultOptimizationStrategySettingsClass;
	
	// Optimization settings for specify map. key: mapName, value:USignificanceOptimizationStrategySettings
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	TMap<FString, TSoftClassPtr<USignificanceOptimizationStrategySettings>> OptimizationStrategySettingsClassWithMap;
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

	TSubclassOf<USignificanceOptimizationStrategySettings> GetSignificanceOptimizationStrategyClass(const UWorld* TargetWorld);

	// Basic setting
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	FSignificanceSystemSetting SignificanceSystemSetting;

	// Default Optimization settings. If you are not config Optimization for specify platform in 'OptimizationWithPlatform' below,we while use this default setting.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = OptimizationSettings)
	FSignificanceOptimizationSettingsWithMaps DefaultOptimization;

	// Optimization for specify platform. key: platformName, eg: Android, IOS, Windows. value FSignificanceOptimizationSettingsWithMaps
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = OptimizationSettings)
	TMap<FString, FSignificanceOptimizationSettingsWithMaps> OptimizationWithPlatform;
};
