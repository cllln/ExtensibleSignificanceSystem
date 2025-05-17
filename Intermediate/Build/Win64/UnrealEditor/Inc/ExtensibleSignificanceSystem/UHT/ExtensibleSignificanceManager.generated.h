// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ExtensibleSignificanceManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UExtensibleSignificanceManager;
class UObject;
struct FSignificanceSystemSetting;
#ifdef EXTENSIBLESIGNIFICANCESYSTEM_ExtensibleSignificanceManager_generated_h
#error "ExtensibleSignificanceManager.generated.h already included, missing '#pragma once' in ExtensibleSignificanceManager.h"
#endif
#define EXTENSIBLESIGNIFICANCESYSTEM_ExtensibleSignificanceManager_generated_h

#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetSignificanceSystemSetting); \
	DECLARE_FUNCTION(execGetExtensibleSignificanceManager);


#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUExtensibleSignificanceManager(); \
	friend struct Z_Construct_UClass_UExtensibleSignificanceManager_Statics; \
public: \
	DECLARE_CLASS(UExtensibleSignificanceManager, USignificanceManager, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/ExtensibleSignificanceSystem"), NO_API) \
	DECLARE_SERIALIZER(UExtensibleSignificanceManager)


#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UExtensibleSignificanceManager(UExtensibleSignificanceManager&&); \
	UExtensibleSignificanceManager(const UExtensibleSignificanceManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UExtensibleSignificanceManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UExtensibleSignificanceManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UExtensibleSignificanceManager) \
	NO_API virtual ~UExtensibleSignificanceManager();


#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_8_PROLOG
#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_11_INCLASS_NO_PURE_DECLS \
	FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EXTENSIBLESIGNIFICANCESYSTEM_API UClass* StaticClass<class UExtensibleSignificanceManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
