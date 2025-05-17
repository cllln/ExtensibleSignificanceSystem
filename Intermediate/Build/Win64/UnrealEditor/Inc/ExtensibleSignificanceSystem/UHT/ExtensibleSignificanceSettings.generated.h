// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ExtensibleSignificanceSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EXTENSIBLESIGNIFICANCESYSTEM_ExtensibleSignificanceSettings_generated_h
#error "ExtensibleSignificanceSettings.generated.h already included, missing '#pragma once' in ExtensibleSignificanceSettings.h"
#endif
#define EXTENSIBLESIGNIFICANCESYSTEM_ExtensibleSignificanceSettings_generated_h

#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_24_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSignificanceSystemSetting_Statics; \
	EXTENSIBLESIGNIFICANCESYSTEM_API static class UScriptStruct* StaticStruct();


template<> EXTENSIBLESIGNIFICANCESYSTEM_API UScriptStruct* StaticStruct<struct FSignificanceSystemSetting>();

#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_45_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSignificanceBucketSetting_Statics; \
	EXTENSIBLESIGNIFICANCESYSTEM_API static class UScriptStruct* StaticStruct();


template<> EXTENSIBLESIGNIFICANCESYSTEM_API UScriptStruct* StaticStruct<struct FSignificanceBucketSetting>();

#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_76_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSignificanceSettingForSpecifyClass_Statics; \
	EXTENSIBLESIGNIFICANCESYSTEM_API static class UScriptStruct* StaticStruct();


template<> EXTENSIBLESIGNIFICANCESYSTEM_API UScriptStruct* StaticStruct<struct FSignificanceSettingForSpecifyClass>();

#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_99_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUExtensibleSignificanceSettings(); \
	friend struct Z_Construct_UClass_UExtensibleSignificanceSettings_Statics; \
public: \
	DECLARE_CLASS(UExtensibleSignificanceSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/ExtensibleSignificanceSystem"), NO_API) \
	DECLARE_SERIALIZER(UExtensibleSignificanceSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Plugins");} \



#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_99_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UExtensibleSignificanceSettings(UExtensibleSignificanceSettings&&); \
	UExtensibleSignificanceSettings(const UExtensibleSignificanceSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UExtensibleSignificanceSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UExtensibleSignificanceSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UExtensibleSignificanceSettings) \
	NO_API virtual ~UExtensibleSignificanceSettings();


#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_96_PROLOG
#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_99_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_99_INCLASS_NO_PURE_DECLS \
	FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h_99_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EXTENSIBLESIGNIFICANCESYSTEM_API UClass* StaticClass<class UExtensibleSignificanceSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSettings_h


#define FOREACH_ENUM_EVIEWPOINTTYPE(op) \
	op(EViewPointType::None) \
	op(EViewPointType::Camera) \
	op(EViewPointType::Player) \
	op(EViewPointType::Both) 

enum class EViewPointType : uint8;
template<> struct TIsUEnumClass<EViewPointType> { enum { Value = true }; };
template<> EXTENSIBLESIGNIFICANCESYSTEM_API UEnum* StaticEnum<EViewPointType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
