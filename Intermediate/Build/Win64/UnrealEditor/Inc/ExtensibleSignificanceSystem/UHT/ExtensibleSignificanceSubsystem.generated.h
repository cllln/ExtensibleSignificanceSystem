// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ExtensibleSignificanceSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UExtensibleSignificanceSubsystem;
class UObject;
#ifdef EXTENSIBLESIGNIFICANCESYSTEM_ExtensibleSignificanceSubsystem_generated_h
#error "ExtensibleSignificanceSubsystem.generated.h already included, missing '#pragma once' in ExtensibleSignificanceSubsystem.h"
#endif
#define EXTENSIBLESIGNIFICANCESYSTEM_ExtensibleSignificanceSubsystem_generated_h

#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUnRegisterAllSignificance); \
	DECLARE_FUNCTION(execUnRegisterSignificance); \
	DECLARE_FUNCTION(execRegisterSignificance); \
	DECLARE_FUNCTION(execOnActorDestroyed); \
	DECLARE_FUNCTION(execOnActorSpawned); \
	DECLARE_FUNCTION(execGetSubsystem);


#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUExtensibleSignificanceSubsystem(); \
	friend struct Z_Construct_UClass_UExtensibleSignificanceSubsystem_Statics; \
public: \
	DECLARE_CLASS(UExtensibleSignificanceSubsystem, UTickableWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ExtensibleSignificanceSystem"), NO_API) \
	DECLARE_SERIALIZER(UExtensibleSignificanceSubsystem)


#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UExtensibleSignificanceSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UExtensibleSignificanceSubsystem(UExtensibleSignificanceSubsystem&&); \
	UExtensibleSignificanceSubsystem(const UExtensibleSignificanceSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UExtensibleSignificanceSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UExtensibleSignificanceSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UExtensibleSignificanceSubsystem) \
	NO_API virtual ~UExtensibleSignificanceSubsystem();


#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_13_PROLOG
#define FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_16_INCLASS_NO_PURE_DECLS \
	FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EXTENSIBLESIGNIFICANCESYSTEM_API UClass* StaticClass<class UExtensibleSignificanceSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_SignificanceSystem_Plugins_ExtensibleSignificanceSystem_Source_ExtensibleSignificanceSystem_Public_ExtensibleSignificanceSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
