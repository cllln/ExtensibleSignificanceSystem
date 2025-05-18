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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	int32 BucketSize = 5;

	// 在当前桶的距离限制
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	float Distance = 1500.0f;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = SignificanceSystem, Instanced)
	TArray<class UExtensibleOptimizationStrategyBase*> OptimizationStrategy;
	
	// 是否显示Mesh
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	bool bShowMesh = false;

	// 是否优化动画Tick
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	bool bOptimizeAnim = true;
	
	// Tick 间隔最小值
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	float ActorTickInterval = 0.0f;

	// Tick 间隔的偏移，主要是为了分散的更开一点
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	float TickIntervalOffset = 0.0f;
};


USTRUCT(Blueprintable, BlueprintType)
struct FSignificanceSettingForSpecifyClass
{
	GENERATED_BODY()

	// Tag
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	FName Tag;

	// // 是否显示对距离的影响因子
	// UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	// float RenderFactor = 5000.0f;
	
	// 每个等级
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	TArray<FSignificanceBucketSetting> BucketSettings;

	int32 GetBucketIndex(const int32 Index, const float Dist, int32& OutShouldBeLod) const;
};

UCLASS(Blueprintable, BlueprintType, Abstract)
class USignificanceOptimizationStrategySettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = SignificanceSystem, meta=(AllowAbstract))
	TMap<FSoftClassPath, FSignificanceSettingForSpecifyClass> SignificanceSettings;
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
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem, meta=(AllowAbstract))
	TMap<FSoftClassPath, FSignificanceSettingForSpecifyClass> SignificanceSettings;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config, Category = SignificanceSystem)
	TSubclassOf<USignificanceOptimizationStrategySettings> OptimizationStrategySettingsClass;
};
