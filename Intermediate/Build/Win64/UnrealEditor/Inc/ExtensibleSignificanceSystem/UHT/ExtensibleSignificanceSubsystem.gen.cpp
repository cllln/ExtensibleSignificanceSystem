// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ExtensibleSignificanceSystem/Public/ExtensibleSignificanceSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExtensibleSignificanceSubsystem() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTickableWorldSubsystem();
EXTENSIBLESIGNIFICANCESYSTEM_API UClass* Z_Construct_UClass_UExtensibleSignificanceSubsystem();
EXTENSIBLESIGNIFICANCESYSTEM_API UClass* Z_Construct_UClass_UExtensibleSignificanceSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_ExtensibleSignificanceSystem();
// End Cross Module References

// Begin Class UExtensibleSignificanceSubsystem Function GetSubsystem
struct Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics
{
	struct ExtensibleSignificanceSubsystem_eventGetSubsystem_Parms
	{
		const UObject* WorldContext;
		UExtensibleSignificanceSubsystem* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ExtensibleSignificance" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContext_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtensibleSignificanceSubsystem_eventGetSubsystem_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContext_MetaData), NewProp_WorldContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtensibleSignificanceSubsystem_eventGetSubsystem_Parms, ReturnValue), Z_Construct_UClass_UExtensibleSignificanceSubsystem_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::NewProp_WorldContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtensibleSignificanceSubsystem, nullptr, "GetSubsystem", nullptr, nullptr, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::ExtensibleSignificanceSubsystem_eventGetSubsystem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::ExtensibleSignificanceSubsystem_eventGetSubsystem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UExtensibleSignificanceSubsystem::execGetSubsystem)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UExtensibleSignificanceSubsystem**)Z_Param__Result=UExtensibleSignificanceSubsystem::GetSubsystem(Z_Param_WorldContext);
	P_NATIVE_END;
}
// End Class UExtensibleSignificanceSubsystem Function GetSubsystem

// Begin Class UExtensibleSignificanceSubsystem Function OnActorDestroyed
struct Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics
{
	struct ExtensibleSignificanceSubsystem_eventOnActorDestroyed_Parms
	{
		AActor* DestroyedActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DestroyedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::NewProp_DestroyedActor = { "DestroyedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtensibleSignificanceSubsystem_eventOnActorDestroyed_Parms, DestroyedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::NewProp_DestroyedActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtensibleSignificanceSubsystem, nullptr, "OnActorDestroyed", nullptr, nullptr, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::ExtensibleSignificanceSubsystem_eventOnActorDestroyed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::ExtensibleSignificanceSubsystem_eventOnActorDestroyed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UExtensibleSignificanceSubsystem::execOnActorDestroyed)
{
	P_GET_OBJECT(AActor,Z_Param_DestroyedActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnActorDestroyed(Z_Param_DestroyedActor);
	P_NATIVE_END;
}
// End Class UExtensibleSignificanceSubsystem Function OnActorDestroyed

// Begin Class UExtensibleSignificanceSubsystem Function OnActorSpawned
struct Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics
{
	struct ExtensibleSignificanceSubsystem_eventOnActorSpawned_Parms
	{
		AActor* SpawnedActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::NewProp_SpawnedActor = { "SpawnedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtensibleSignificanceSubsystem_eventOnActorSpawned_Parms, SpawnedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::NewProp_SpawnedActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtensibleSignificanceSubsystem, nullptr, "OnActorSpawned", nullptr, nullptr, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::ExtensibleSignificanceSubsystem_eventOnActorSpawned_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::ExtensibleSignificanceSubsystem_eventOnActorSpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UExtensibleSignificanceSubsystem::execOnActorSpawned)
{
	P_GET_OBJECT(AActor,Z_Param_SpawnedActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnActorSpawned(Z_Param_SpawnedActor);
	P_NATIVE_END;
}
// End Class UExtensibleSignificanceSubsystem Function OnActorSpawned

// Begin Class UExtensibleSignificanceSubsystem Function RegisterSignificance
struct Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics
{
	struct ExtensibleSignificanceSubsystem_eventRegisterSignificance_Parms
	{
		AActor* TargetActor;
		FName Tag;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ExtensibleSignificance" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Tag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtensibleSignificanceSubsystem_eventRegisterSignificance_Parms, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtensibleSignificanceSubsystem_eventRegisterSignificance_Parms, Tag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tag_MetaData), NewProp_Tag_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::NewProp_Tag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtensibleSignificanceSubsystem, nullptr, "RegisterSignificance", nullptr, nullptr, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::ExtensibleSignificanceSubsystem_eventRegisterSignificance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::ExtensibleSignificanceSubsystem_eventRegisterSignificance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UExtensibleSignificanceSubsystem::execRegisterSignificance)
{
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_GET_PROPERTY(FNameProperty,Z_Param_Tag);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RegisterSignificance(Z_Param_TargetActor,Z_Param_Tag);
	P_NATIVE_END;
}
// End Class UExtensibleSignificanceSubsystem Function RegisterSignificance

// Begin Class UExtensibleSignificanceSubsystem Function UnRegisterAllSignificance
struct Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterAllSignificance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ExtensibleSignificance" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterAllSignificance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtensibleSignificanceSubsystem, nullptr, "UnRegisterAllSignificance", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterAllSignificance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterAllSignificance_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterAllSignificance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterAllSignificance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UExtensibleSignificanceSubsystem::execUnRegisterAllSignificance)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnRegisterAllSignificance();
	P_NATIVE_END;
}
// End Class UExtensibleSignificanceSubsystem Function UnRegisterAllSignificance

// Begin Class UExtensibleSignificanceSubsystem Function UnRegisterSignificance
struct Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics
{
	struct ExtensibleSignificanceSubsystem_eventUnRegisterSignificance_Parms
	{
		AActor* TargetActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ExtensibleSignificance" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtensibleSignificanceSubsystem_eventUnRegisterSignificance_Parms, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::NewProp_TargetActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtensibleSignificanceSubsystem, nullptr, "UnRegisterSignificance", nullptr, nullptr, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::ExtensibleSignificanceSubsystem_eventUnRegisterSignificance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::ExtensibleSignificanceSubsystem_eventUnRegisterSignificance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UExtensibleSignificanceSubsystem::execUnRegisterSignificance)
{
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnRegisterSignificance(Z_Param_TargetActor);
	P_NATIVE_END;
}
// End Class UExtensibleSignificanceSubsystem Function UnRegisterSignificance

// Begin Class UExtensibleSignificanceSubsystem
void UExtensibleSignificanceSubsystem::StaticRegisterNativesUExtensibleSignificanceSubsystem()
{
	UClass* Class = UExtensibleSignificanceSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetSubsystem", &UExtensibleSignificanceSubsystem::execGetSubsystem },
		{ "OnActorDestroyed", &UExtensibleSignificanceSubsystem::execOnActorDestroyed },
		{ "OnActorSpawned", &UExtensibleSignificanceSubsystem::execOnActorSpawned },
		{ "RegisterSignificance", &UExtensibleSignificanceSubsystem::execRegisterSignificance },
		{ "UnRegisterAllSignificance", &UExtensibleSignificanceSubsystem::execUnRegisterAllSignificance },
		{ "UnRegisterSignificance", &UExtensibleSignificanceSubsystem::execUnRegisterSignificance },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UExtensibleSignificanceSubsystem);
UClass* Z_Construct_UClass_UExtensibleSignificanceSubsystem_NoRegister()
{
	return UExtensibleSignificanceSubsystem::StaticClass();
}
struct Z_Construct_UClass_UExtensibleSignificanceSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe7\xae\xa1\xe7\x90\x86\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xef\xbc\x8c\xe7\x9b\x91\xe5\x90\xac""Actor\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe5\x88\x9b\xe5\xbb\xba\xe9\x94\x80\xe6\xaf\x81\xef\xbc\x8c\xe5\xb0\x86\xe5\x85\xb3\xe5\xbf\x83\xe7\x9a\x84""Actor\xe6\xb7\xbb\xe5\x8a\xa0\xe5\x88\xb0\xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8\xe9\x87\x8c\xe3\x80\x82\n */" },
#endif
		{ "IncludePath", "ExtensibleSignificanceSubsystem.h" },
		{ "ModuleRelativePath", "Public/ExtensibleSignificanceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe7\xae\xa1\xe7\x90\x86\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xef\xbc\x8c\xe7\x9b\x91\xe5\x90\xac""Actor\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe5\x88\x9b\xe5\xbb\xba\xe9\x94\x80\xe6\xaf\x81\xef\xbc\x8c\xe5\xb0\x86\xe5\x85\xb3\xe5\xbf\x83\xe7\x9a\x84""Actor\xe6\xb7\xbb\xe5\x8a\xa0\xe5\x88\xb0\xe9\x87\x8d\xe8\xa6\x81\xe5\xba\xa6\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8\xe9\x87\x8c\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UExtensibleSignificanceSubsystem_GetSubsystem, "GetSubsystem" }, // 2580729439
		{ &Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorDestroyed, "OnActorDestroyed" }, // 2534810223
		{ &Z_Construct_UFunction_UExtensibleSignificanceSubsystem_OnActorSpawned, "OnActorSpawned" }, // 3994098462
		{ &Z_Construct_UFunction_UExtensibleSignificanceSubsystem_RegisterSignificance, "RegisterSignificance" }, // 3316854676
		{ &Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterAllSignificance, "UnRegisterAllSignificance" }, // 2975177590
		{ &Z_Construct_UFunction_UExtensibleSignificanceSubsystem_UnRegisterSignificance, "UnRegisterSignificance" }, // 1354979256
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UExtensibleSignificanceSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UExtensibleSignificanceSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UTickableWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ExtensibleSignificanceSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UExtensibleSignificanceSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UExtensibleSignificanceSubsystem_Statics::ClassParams = {
	&UExtensibleSignificanceSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UExtensibleSignificanceSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UExtensibleSignificanceSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UExtensibleSignificanceSubsystem()
{
	if (!Z_Registration_Info_UClass_UExtensibleSignificanceSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UExtensibleSignificanceSubsystem.OuterSingleton, Z_Construct_UClass_UExtensibleSignificanceSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UExtensibleSignificanceSubsystem.OuterSingleton;
}
template<> EXTENSIBLESIGNIFICANCESYSTEM_API UClass* StaticClass<UExtensibleSignificanceSubsystem>()
{
	return UExtensibleSignificanceSubsystem::StaticClass();
}
UExtensibleSignificanceSubsystem::UExtensibleSignificanceSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UExtensibleSignificanceSubsystem);
UExtensibleSignificanceSubsystem::~UExtensibleSignificanceSubsystem() {}
// End Class UExtensibleSignificanceSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UExtensibleSignificanceSubsystem, UExtensibleSignificanceSubsystem::StaticClass, TEXT("UExtensibleSignificanceSubsystem"), &Z_Registration_Info_UClass_UExtensibleSignificanceSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UExtensibleSignificanceSubsystem), 2712920842U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_1170735433(TEXT("/Script/ExtensibleSignificanceSystem"),
	Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
