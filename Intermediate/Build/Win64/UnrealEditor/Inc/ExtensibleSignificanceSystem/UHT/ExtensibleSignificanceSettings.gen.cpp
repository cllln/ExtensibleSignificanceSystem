// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ExtensibleSignificanceSystem/Public/ExtensibleSignificanceSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExtensibleSignificanceSettings() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftClassPath();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
EXTENSIBLESIGNIFICANCESYSTEM_API UClass* Z_Construct_UClass_UExtensibleSignificanceSettings();
EXTENSIBLESIGNIFICANCESYSTEM_API UClass* Z_Construct_UClass_UExtensibleSignificanceSettings_NoRegister();
EXTENSIBLESIGNIFICANCESYSTEM_API UEnum* Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType();
EXTENSIBLESIGNIFICANCESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSignificanceBucketSetting();
EXTENSIBLESIGNIFICANCESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass();
EXTENSIBLESIGNIFICANCESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSignificanceSystemSetting();
UPackage* Z_Construct_UPackage__Script_ExtensibleSignificanceSystem();
// End Cross Module References

// Begin Enum EViewPointType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EViewPointType;
static UEnum* EViewPointType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EViewPointType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EViewPointType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType, (UObject*)Z_Construct_UPackage__Script_ExtensibleSignificanceSystem(), TEXT("EViewPointType"));
	}
	return Z_Registration_Info_UEnum_EViewPointType.OuterSingleton;
}
template<> EXTENSIBLESIGNIFICANCESYSTEM_API UEnum* StaticEnum<EViewPointType>()
{
	return EViewPointType_StaticEnum();
}
struct Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Both.Comment", "// \xe5\x90\x8c\xe6\x97\xb6\xe4\xbb\xa5\xe6\x91\x84\xe5\x83\x8f\xe6\x9c\xba\xe5\x92\x8c\xe7\x8e\xa9\xe5\xae\xb6\xe4\xb8\xba\xe5\x9f\xba\xe5\x87\x86\n" },
		{ "Both.Name", "EViewPointType::Both" },
		{ "Both.ToolTip", "\xe5\x90\x8c\xe6\x97\xb6\xe4\xbb\xa5\xe6\x91\x84\xe5\x83\x8f\xe6\x9c\xba\xe5\x92\x8c\xe7\x8e\xa9\xe5\xae\xb6\xe4\xb8\xba\xe5\x9f\xba\xe5\x87\x86" },
		{ "Camera.Comment", "// \xe4\xbb\xa5\xe6\x91\x84\xe5\x83\x8f\xe6\x9c\xba\xe4\xb8\xba\xe5\x9f\xba\xe5\x87\x86\n" },
		{ "Camera.Name", "EViewPointType::Camera" },
		{ "Camera.ToolTip", "\xe4\xbb\xa5\xe6\x91\x84\xe5\x83\x8f\xe6\x9c\xba\xe4\xb8\xba\xe5\x9f\xba\xe5\x87\x86" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
		{ "None.Comment", "// \xe6\x97\xa0\xef\xbc\x8c\xe4\xb8\x8d\xe8\xbf\x9b\xe8\xa1\x8c\xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe8\xae\xa1\xe7\xae\x97\n" },
		{ "None.Name", "EViewPointType::None" },
		{ "None.ToolTip", "\xe6\x97\xa0\xef\xbc\x8c\xe4\xb8\x8d\xe8\xbf\x9b\xe8\xa1\x8c\xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe8\xae\xa1\xe7\xae\x97" },
		{ "Player.Comment", "// \xe4\xbb\xa5\xe7\x8e\xa9\xe5\xae\xb6\xe4\xb8\xba\xe5\x9f\xba\xe5\x87\x86\n" },
		{ "Player.Name", "EViewPointType::Player" },
		{ "Player.ToolTip", "\xe4\xbb\xa5\xe7\x8e\xa9\xe5\xae\xb6\xe4\xb8\xba\xe5\x9f\xba\xe5\x87\x86" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EViewPointType::None", (int64)EViewPointType::None },
		{ "EViewPointType::Camera", (int64)EViewPointType::Camera },
		{ "EViewPointType::Player", (int64)EViewPointType::Player },
		{ "EViewPointType::Both", (int64)EViewPointType::Both },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ExtensibleSignificanceSystem,
	nullptr,
	"EViewPointType",
	"EViewPointType",
	Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType()
{
	if (!Z_Registration_Info_UEnum_EViewPointType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EViewPointType.InnerSingleton, Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EViewPointType.InnerSingleton;
}
// End Enum EViewPointType

// Begin ScriptStruct FSignificanceSystemSetting
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SignificanceSystemSetting;
class UScriptStruct* FSignificanceSystemSetting::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SignificanceSystemSetting.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SignificanceSystemSetting.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSignificanceSystemSetting, (UObject*)Z_Construct_UPackage__Script_ExtensibleSignificanceSystem(), TEXT("SignificanceSystemSetting"));
	}
	return Z_Registration_Info_UScriptStruct_SignificanceSystemSetting.OuterSingleton;
}
template<> EXTENSIBLESIGNIFICANCESYSTEM_API UScriptStruct* StaticStruct<FSignificanceSystemSetting>()
{
	return FSignificanceSystemSetting::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TickInterval_MetaData[] = {
		{ "Category", "SignificanceSystemSetting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe6\xa3\x80\xe6\xb5\x8b\xe9\x97\xb4\xe9\x9a\x94\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa3\x80\xe6\xb5\x8b\xe9\x97\xb4\xe9\x9a\x94" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewPointType_MetaData[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe8\xa7\x86\xe5\x8f\xa3\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe8\xa7\x86\xe5\x8f\xa3" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TickInterval;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ViewPointType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ViewPointType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSignificanceSystemSetting>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::NewProp_TickInterval = { "TickInterval", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSignificanceSystemSetting, TickInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TickInterval_MetaData), NewProp_TickInterval_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::NewProp_ViewPointType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::NewProp_ViewPointType = { "ViewPointType", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSignificanceSystemSetting, ViewPointType), Z_Construct_UEnum_ExtensibleSignificanceSystem_EViewPointType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewPointType_MetaData), NewProp_ViewPointType_MetaData) }; // 2560377203
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::NewProp_TickInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::NewProp_ViewPointType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::NewProp_ViewPointType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ExtensibleSignificanceSystem,
	nullptr,
	&NewStructOps,
	"SignificanceSystemSetting",
	Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::PropPointers),
	sizeof(FSignificanceSystemSetting),
	alignof(FSignificanceSystemSetting),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSignificanceSystemSetting()
{
	if (!Z_Registration_Info_UScriptStruct_SignificanceSystemSetting.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SignificanceSystemSetting.InnerSingleton, Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SignificanceSystemSetting.InnerSingleton;
}
// End ScriptStruct FSignificanceSystemSetting

// Begin ScriptStruct FSignificanceBucketSetting
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SignificanceBucketSetting;
class UScriptStruct* FSignificanceBucketSetting::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SignificanceBucketSetting.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SignificanceBucketSetting.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSignificanceBucketSetting, (UObject*)Z_Construct_UPackage__Script_ExtensibleSignificanceSystem(), TEXT("SignificanceBucketSetting"));
	}
	return Z_Registration_Info_UScriptStruct_SignificanceBucketSetting.OuterSingleton;
}
template<> EXTENSIBLESIGNIFICANCESYSTEM_API UScriptStruct* StaticStruct<FSignificanceBucketSetting>()
{
	return FSignificanceBucketSetting::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe6\xaf\x8f\xe4\xb8\xaa\xe6\xa1\xb6\xe7\x9a\x84\xe5\x85\xb7\xe4\xbd\x93\xe8\xae\xbe\xe7\xbd\xae\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xaf\x8f\xe4\xb8\xaa\xe6\xa1\xb6\xe7\x9a\x84\xe5\x85\xb7\xe4\xbd\x93\xe8\xae\xbe\xe7\xbd\xae" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BucketSize_MetaData[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe5\xae\xb9\xe7\xba\xb3\xe7\x9a\x84\xe6\x9c\x80\xe5\xa4\x9a\xe5\xaf\xb9\xe8\xb1\xa1\xe4\xb8\xaa\xe6\x95\xb0\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\xb9\xe7\xba\xb3\xe7\x9a\x84\xe6\x9c\x80\xe5\xa4\x9a\xe5\xaf\xb9\xe8\xb1\xa1\xe4\xb8\xaa\xe6\x95\xb0" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Distance_MetaData[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe5\x9c\xa8\xe5\xbd\x93\xe5\x89\x8d\xe6\xa1\xb6\xe7\x9a\x84\xe8\xb7\x9d\xe7\xa6\xbb\xe9\x99\x90\xe5\x88\xb6\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x9c\xa8\xe5\xbd\x93\xe5\x89\x8d\xe6\xa1\xb6\xe7\x9a\x84\xe8\xb7\x9d\xe7\xa6\xbb\xe9\x99\x90\xe5\x88\xb6" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowMesh_MetaData[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xbaMesh\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xbaMesh" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOptimizeAnim_MetaData[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe6\x98\xaf\xe5\x90\xa6\xe4\xbc\x98\xe5\x8c\x96\xe5\x8a\xa8\xe7\x94\xbbTick\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x98\xaf\xe5\x90\xa6\xe4\xbc\x98\xe5\x8c\x96\xe5\x8a\xa8\xe7\x94\xbbTick" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorTickInterval_MetaData[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Tick \xe9\x97\xb4\xe9\x9a\x94\xe6\x9c\x80\xe5\xb0\x8f\xe5\x80\xbc\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tick \xe9\x97\xb4\xe9\x9a\x94\xe6\x9c\x80\xe5\xb0\x8f\xe5\x80\xbc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TickIntervalOffset_MetaData[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Tick \xe9\x97\xb4\xe9\x9a\x94\xe7\x9a\x84\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe4\xb8\xbb\xe8\xa6\x81\xe6\x98\xaf\xe4\xb8\xba\xe4\xba\x86\xe5\x88\x86\xe6\x95\xa3\xe7\x9a\x84\xe6\x9b\xb4\xe5\xbc\x80\xe4\xb8\x80\xe7\x82\xb9\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tick \xe9\x97\xb4\xe9\x9a\x94\xe7\x9a\x84\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe4\xb8\xbb\xe8\xa6\x81\xe6\x98\xaf\xe4\xb8\xba\xe4\xba\x86\xe5\x88\x86\xe6\x95\xa3\xe7\x9a\x84\xe6\x9b\xb4\xe5\xbc\x80\xe4\xb8\x80\xe7\x82\xb9" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_BucketSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
	static void NewProp_bShowMesh_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowMesh;
	static void NewProp_bOptimizeAnim_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOptimizeAnim;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActorTickInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TickIntervalOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSignificanceBucketSetting>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_BucketSize = { "BucketSize", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSignificanceBucketSetting, BucketSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BucketSize_MetaData), NewProp_BucketSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSignificanceBucketSetting, Distance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Distance_MetaData), NewProp_Distance_MetaData) };
void Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_bShowMesh_SetBit(void* Obj)
{
	((FSignificanceBucketSetting*)Obj)->bShowMesh = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_bShowMesh = { "bShowMesh", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSignificanceBucketSetting), &Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_bShowMesh_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowMesh_MetaData), NewProp_bShowMesh_MetaData) };
void Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_bOptimizeAnim_SetBit(void* Obj)
{
	((FSignificanceBucketSetting*)Obj)->bOptimizeAnim = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_bOptimizeAnim = { "bOptimizeAnim", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSignificanceBucketSetting), &Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_bOptimizeAnim_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOptimizeAnim_MetaData), NewProp_bOptimizeAnim_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_ActorTickInterval = { "ActorTickInterval", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSignificanceBucketSetting, ActorTickInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorTickInterval_MetaData), NewProp_ActorTickInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_TickIntervalOffset = { "TickIntervalOffset", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSignificanceBucketSetting, TickIntervalOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TickIntervalOffset_MetaData), NewProp_TickIntervalOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_BucketSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_Distance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_bShowMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_bOptimizeAnim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_ActorTickInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewProp_TickIntervalOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ExtensibleSignificanceSystem,
	nullptr,
	&NewStructOps,
	"SignificanceBucketSetting",
	Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::PropPointers),
	sizeof(FSignificanceBucketSetting),
	alignof(FSignificanceBucketSetting),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSignificanceBucketSetting()
{
	if (!Z_Registration_Info_UScriptStruct_SignificanceBucketSetting.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SignificanceBucketSetting.InnerSingleton, Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SignificanceBucketSetting.InnerSingleton;
}
// End ScriptStruct FSignificanceBucketSetting

// Begin ScriptStruct FSignificanceSettingForSpecifyClass
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SignificanceSettingForSpecifyClass;
class UScriptStruct* FSignificanceSettingForSpecifyClass::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SignificanceSettingForSpecifyClass.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SignificanceSettingForSpecifyClass.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass, (UObject*)Z_Construct_UPackage__Script_ExtensibleSignificanceSystem(), TEXT("SignificanceSettingForSpecifyClass"));
	}
	return Z_Registration_Info_UScriptStruct_SignificanceSettingForSpecifyClass.OuterSingleton;
}
template<> EXTENSIBLESIGNIFICANCESYSTEM_API UScriptStruct* StaticStruct<FSignificanceSettingForSpecifyClass>()
{
	return FSignificanceSettingForSpecifyClass::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Tag\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tag" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BucketSettings_MetaData[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe6\xaf\x8f\xe4\xb8\xaa\xe7\xad\x89\xe7\xba\xa7\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xaf\x8f\xe4\xb8\xaa\xe7\xad\x89\xe7\xba\xa7" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BucketSettings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_BucketSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSignificanceSettingForSpecifyClass>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSignificanceSettingForSpecifyClass, Tag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tag_MetaData), NewProp_Tag_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::NewProp_BucketSettings_Inner = { "BucketSettings", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSignificanceBucketSetting, METADATA_PARAMS(0, nullptr) }; // 2390447197
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::NewProp_BucketSettings = { "BucketSettings", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSignificanceSettingForSpecifyClass, BucketSettings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BucketSettings_MetaData), NewProp_BucketSettings_MetaData) }; // 2390447197
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::NewProp_Tag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::NewProp_BucketSettings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::NewProp_BucketSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ExtensibleSignificanceSystem,
	nullptr,
	&NewStructOps,
	"SignificanceSettingForSpecifyClass",
	Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::PropPointers),
	sizeof(FSignificanceSettingForSpecifyClass),
	alignof(FSignificanceSettingForSpecifyClass),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass()
{
	if (!Z_Registration_Info_UScriptStruct_SignificanceSettingForSpecifyClass.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SignificanceSettingForSpecifyClass.InnerSingleton, Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SignificanceSettingForSpecifyClass.InnerSingleton;
}
// End ScriptStruct FSignificanceSettingForSpecifyClass

// Begin Class UExtensibleSignificanceSettings
void UExtensibleSignificanceSettings::StaticRegisterNativesUExtensibleSignificanceSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UExtensibleSignificanceSettings);
UClass* Z_Construct_UClass_UExtensibleSignificanceSettings_NoRegister()
{
	return UExtensibleSignificanceSettings::StaticClass();
}
struct Z_Construct_UClass_UExtensibleSignificanceSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Default settings for the Extensible Significance\n */" },
#endif
		{ "DisplayName", "Extensible Significance Settings" },
		{ "IncludePath", "ExtensibleSignificanceSettings.h" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default settings for the Extensible Significance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SignificanceSystemSetting_MetaData[] = {
		{ "Category", "SignificanceSystem" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SignificanceSettings_MetaData[] = {
		{ "AllowAbstract", "" },
		{ "Category", "SignificanceSystem" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SignificanceSystemSetting;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SignificanceSettings_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SignificanceSettings_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_SignificanceSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UExtensibleSignificanceSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::NewProp_SignificanceSystemSetting = { "SignificanceSystemSetting", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UExtensibleSignificanceSettings, SignificanceSystemSetting), Z_Construct_UScriptStruct_FSignificanceSystemSetting, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SignificanceSystemSetting_MetaData), NewProp_SignificanceSystemSetting_MetaData) }; // 47627083
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::NewProp_SignificanceSettings_ValueProp = { "SignificanceSettings", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass, METADATA_PARAMS(0, nullptr) }; // 1948743009
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::NewProp_SignificanceSettings_Key_KeyProp = { "SignificanceSettings_Key", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSoftClassPath, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::NewProp_SignificanceSettings = { "SignificanceSettings", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UExtensibleSignificanceSettings, SignificanceSettings), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SignificanceSettings_MetaData), NewProp_SignificanceSettings_MetaData) }; // 1948743009
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::NewProp_SignificanceSystemSetting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::NewProp_SignificanceSettings_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::NewProp_SignificanceSettings_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::NewProp_SignificanceSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_ExtensibleSignificanceSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::ClassParams = {
	&UExtensibleSignificanceSettings::StaticClass,
	"Plugins",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UExtensibleSignificanceSettings()
{
	if (!Z_Registration_Info_UClass_UExtensibleSignificanceSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UExtensibleSignificanceSettings.OuterSingleton, Z_Construct_UClass_UExtensibleSignificanceSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UExtensibleSignificanceSettings.OuterSingleton;
}
template<> EXTENSIBLESIGNIFICANCESYSTEM_API UClass* StaticClass<UExtensibleSignificanceSettings>()
{
	return UExtensibleSignificanceSettings::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UExtensibleSignificanceSettings);
UExtensibleSignificanceSettings::~UExtensibleSignificanceSettings() {}
// End Class UExtensibleSignificanceSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EViewPointType_StaticEnum, TEXT("EViewPointType"), &Z_Registration_Info_UEnum_EViewPointType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2560377203U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSignificanceSystemSetting::StaticStruct, Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics::NewStructOps, TEXT("SignificanceSystemSetting"), &Z_Registration_Info_UScriptStruct_SignificanceSystemSetting, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSignificanceSystemSetting), 47627083U) },
		{ FSignificanceBucketSetting::StaticStruct, Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics::NewStructOps, TEXT("SignificanceBucketSetting"), &Z_Registration_Info_UScriptStruct_SignificanceBucketSetting, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSignificanceBucketSetting), 2390447197U) },
		{ FSignificanceSettingForSpecifyClass::StaticStruct, Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics::NewStructOps, TEXT("SignificanceSettingForSpecifyClass"), &Z_Registration_Info_UScriptStruct_SignificanceSettingForSpecifyClass, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSignificanceSettingForSpecifyClass), 1948743009U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UExtensibleSignificanceSettings, UExtensibleSignificanceSettings::StaticClass, TEXT("UExtensibleSignificanceSettings"), &Z_Registration_Info_UClass_UExtensibleSignificanceSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UExtensibleSignificanceSettings), 4205248348U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_249410480(TEXT("/Script/ExtensibleSignificanceSystem"),
	Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
