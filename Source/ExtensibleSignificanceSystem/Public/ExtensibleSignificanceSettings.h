// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreTypes.h"
#include "ExtensibleSignificanceSettings.generated.h"

UENUM()
enum class EViewPointType : uint8
{
	// 无，不进行重要度计算
	None = 0,
	// 以摄像机为基准
	Camera,
	// 以玩家为基准
	Player,
	// 同时以摄像机和玩家为基准
	Both,
};

USTRUCT(Blueprintable, BlueprintType)
struct FSignificanceSystemSetting
{
	GENERATED_BODY()

	// 检测间隔
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystemSetting)
	float TickInterval = 0.1f;
	
	// 重要度视口
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	EViewPointType ViewPointType = EViewPointType::Player; 

	bool ShouldCheck(const float DeltaTime);
	
private:

	float CheckRemainTime = 0.f;
};

// 每个桶的具体设置
USTRUCT(BlueprintType)
struct FSignificanceBucketSetting
{
	GENERATED_BODY()

	// 容纳的最多对象个数
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = SignificanceSystem)
	int32 BucketSize = 5;

	// 在当前桶的重要度限制
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = SignificanceSystem)
	float SignificanceLimit = 1500.0f;

	// 当前桶的优化策略
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

	/* 重要度计算策略*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = SignificanceSystem, Instanced)
	TArray<class USignificanceCalculateStrategyBase*> SignificanceCalculateStrategies;
	
	// 每个等级
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
