// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ExtensibleSignificanceSystem/Public/ExtensibleSignificanceManager.h"
#include "ExtensibleSignificanceSystem/Public/ExtensibleSignificanceSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExtensibleSignificanceManager() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
EXTENSIBLESIGNIFICANCESYSTEM_API UClass* Z_Construct_UClass_UExtensibleSignificanceManager();
EXTENSIBLESIGNIFICANCESYSTEM_API UClass* Z_Construct_UClass_UExtensibleSignificanceManager_NoRegister();
EXTENSIBLESIGNIFICANCESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSignificanceSystemSetting();
SIGNIFICANCEMANAGER_API UClass* Z_Construct_UClass_USignificanceManager();
UPackage* Z_Construct_UPackage__Script_ExtensibleSignificanceSystem();
// End Cross Module References

// Begin Class UExtensibleSignificanceManager Function GetExtensibleSignificanceManager
struct Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics
{
	struct ExtensibleSignificanceManager_eventGetExtensibleSignificanceManager_Parms
	{
		UObject* WorldContext;
		UExtensibleSignificanceManager* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe8\x8e\xb7\xe5\x8f\x96\xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtensibleSignificanceManager_eventGetExtensibleSignificanceManager_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtensibleSignificanceManager_eventGetExtensibleSignificanceManager_Parms, ReturnValue), Z_Construct_UClass_UExtensibleSignificanceManager_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::NewProp_WorldContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtensibleSignificanceManager, nullptr, "GetExtensibleSignificanceManager", nullptr, nullptr, Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::ExtensibleSignificanceManager_eventGetExtensibleSignificanceManager_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::ExtensibleSignificanceManager_eventGetExtensibleSignificanceManager_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UExtensibleSignificanceManager::execGetExtensibleSignificanceManager)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UExtensibleSignificanceManager**)Z_Param__Result=UExtensibleSignificanceManager::GetExtensibleSignificanceManager(Z_Param_WorldContext);
	P_NATIVE_END;
}
// End Class UExtensibleSignificanceManager Function GetExtensibleSignificanceManager

// Begin Class UExtensibleSignificanceManager Function GetSignificanceSystemSetting
struct Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics
{
	struct ExtensibleSignificanceManager_eventGetSignificanceSystemSetting_Parms
	{
		FSignificanceSystemSetting ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SignificanceSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe8\x8e\xb7\xe5\x8f\x96\xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe8\xae\xbe\xe7\xbd\xae\n" },
#endif
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe8\xae\xbe\xe7\xbd\xae" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtensibleSignificanceManager_eventGetSignificanceSystemSetting_Parms, ReturnValue), Z_Construct_UScriptStruct_FSignificanceSystemSetting, METADATA_PARAMS(0, nullptr) }; // 47627083
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtensibleSignificanceManager, nullptr, "GetSignificanceSystemSetting", nullptr, nullptr, Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::ExtensibleSignificanceManager_eventGetSignificanceSystemSetting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::ExtensibleSignificanceManager_eventGetSignificanceSystemSetting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UExtensibleSignificanceManager::execGetSignificanceSystemSetting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSignificanceSystemSetting*)Z_Param__Result=UExtensibleSignificanceManager::GetSignificanceSystemSetting();
	P_NATIVE_END;
}
// End Class UExtensibleSignificanceManager Function GetSignificanceSystemSetting

// Begin Class UExtensibleSignificanceManager
void UExtensibleSignificanceManager::StaticRegisterNativesUExtensibleSignificanceManager()
{
	UClass* Class = UExtensibleSignificanceManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetExtensibleSignificanceManager", &UExtensibleSignificanceManager::execGetExtensibleSignificanceManager },
		{ "GetSignificanceSystemSetting", &UExtensibleSignificanceManager::execGetSignificanceSystemSetting },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UExtensibleSignificanceManager);
UClass* Z_Construct_UClass_UExtensibleSignificanceManager_NoRegister()
{
	return UExtensibleSignificanceManager::StaticClass();
}
struct Z_Construct_UClass_UExtensibleSignificanceManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ExtensibleSignificanceManager.h" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceManager.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UExtensibleSignificanceManager_GetExtensibleSignificanceManager, "GetExtensibleSignificanceManager" }, // 1016967384
		{ &Z_Construct_UFunction_UExtensibleSignificanceManager_GetSignificanceSystemSetting, "GetSignificanceSystemSetting" }, // 2066647707
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UExtensibleSignificanceManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UExtensibleSignificanceManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USignificanceManager,
	(UObject* (*)())Z_Construct_UPackage__Script_ExtensibleSignificanceSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UExtensibleSignificanceManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UExtensibleSignificanceManager_Statics::ClassParams = {
	&UExtensibleSignificanceManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UExtensibleSignificanceManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UExtensibleSignificanceManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UExtensibleSignificanceManager()
{
	if (!Z_Registration_Info_UClass_UExtensibleSignificanceManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UExtensibleSignificanceManager.OuterSingleton, Z_Construct_UClass_UExtensibleSignificanceManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UExtensibleSignificanceManager.OuterSingleton;
}
template<> EXTENSIBLESIGNIFICANCESYSTEM_API UClass* StaticClass<UExtensibleSignificanceManager>()
{
	return UExtensibleSignificanceManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UExtensibleSignificanceManager);
UExtensibleSignificanceManager::~UExtensibleSignificanceManager() {}
// End Class UExtensibleSignificanceManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UExtensibleSignificanceManager, UExtensibleSignificanceManager::StaticClass, TEXT("UExtensibleSignificanceManager"), &Z_Registration_Info_UClass_UExtensibleSignificanceManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UExtensibleSignificanceManager), 2801470739U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_4093042873(TEXT("/Script/ExtensibleSignificanceSystem"),
	Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
