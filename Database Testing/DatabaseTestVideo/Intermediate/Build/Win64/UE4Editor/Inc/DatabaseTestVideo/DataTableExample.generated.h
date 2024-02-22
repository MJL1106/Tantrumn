// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DATABASETESTVIDEO_DataTableExample_generated_h
#error "DataTableExample.generated.h already included, missing '#pragma once' in DataTableExample.h"
#endif
#define DATABASETESTVIDEO_DataTableExample_generated_h

#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEffectStats_Statics; \
	DATABASETESTVIDEO_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> DATABASETESTVIDEO_API UScriptStruct* StaticStruct<struct FEffectStats>();

#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_SPARSE_DATA
#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_RPC_WRAPPERS
#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_RPC_WRAPPERS_NO_PURE_DECLS
#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADataTableExample(); \
	friend struct Z_Construct_UClass_ADataTableExample_Statics; \
public: \
	DECLARE_CLASS(ADataTableExample, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DatabaseTestVideo"), NO_API) \
	DECLARE_SERIALIZER(ADataTableExample)


#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_INCLASS \
private: \
	static void StaticRegisterNativesADataTableExample(); \
	friend struct Z_Construct_UClass_ADataTableExample_Statics; \
public: \
	DECLARE_CLASS(ADataTableExample, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DatabaseTestVideo"), NO_API) \
	DECLARE_SERIALIZER(ADataTableExample)


#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADataTableExample(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADataTableExample) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADataTableExample); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADataTableExample); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADataTableExample(ADataTableExample&&); \
	NO_API ADataTableExample(const ADataTableExample&); \
public:


#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADataTableExample(ADataTableExample&&); \
	NO_API ADataTableExample(const ADataTableExample&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADataTableExample); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADataTableExample); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADataTableExample)


#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_PRIVATE_PROPERTY_OFFSET
#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_34_PROLOG
#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_PRIVATE_PROPERTY_OFFSET \
	DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_SPARSE_DATA \
	DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_RPC_WRAPPERS \
	DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_INCLASS \
	DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_PRIVATE_PROPERTY_OFFSET \
	DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_SPARSE_DATA \
	DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_INCLASS_NO_PURE_DECLS \
	DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DATABASETESTVIDEO_API UClass* StaticClass<class ADataTableExample>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DatabaseTestVideo_Source_DatabaseTestVideo_DataTableExample_h


#define FOREACH_ENUM_EEFFECTTYPE(op) \
	op(EEffectType::None) \
	op(EEffectType::Speed) \
	op(EEffectType::Jump) \
	op(EEffectType::Power) 

enum class EEffectType : uint8;
template<> DATABASETESTVIDEO_API UEnum* StaticEnum<EEffectType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
