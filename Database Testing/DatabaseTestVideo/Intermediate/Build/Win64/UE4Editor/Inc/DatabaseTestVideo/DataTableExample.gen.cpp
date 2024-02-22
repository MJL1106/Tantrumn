// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DatabaseTestVideo/DataTableExample.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataTableExample() {}
// Cross Module References
	DATABASETESTVIDEO_API UEnum* Z_Construct_UEnum_DatabaseTestVideo_EEffectType();
	UPackage* Z_Construct_UPackage__Script_DatabaseTestVideo();
	DATABASETESTVIDEO_API UScriptStruct* Z_Construct_UScriptStruct_FEffectStats();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	DATABASETESTVIDEO_API UClass* Z_Construct_UClass_ADataTableExample_NoRegister();
	DATABASETESTVIDEO_API UClass* Z_Construct_UClass_ADataTableExample();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
// End Cross Module References
	static UEnum* EEffectType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_DatabaseTestVideo_EEffectType, Z_Construct_UPackage__Script_DatabaseTestVideo(), TEXT("EEffectType"));
		}
		return Singleton;
	}
	template<> DATABASETESTVIDEO_API UEnum* StaticEnum<EEffectType>()
	{
		return EEffectType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EEffectType(EEffectType_StaticEnum, TEXT("/Script/DatabaseTestVideo"), TEXT("EEffectType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_DatabaseTestVideo_EEffectType_Hash() { return 2935487933U; }
	UEnum* Z_Construct_UEnum_DatabaseTestVideo_EEffectType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_DatabaseTestVideo();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EEffectType"), 0, Get_Z_Construct_UEnum_DatabaseTestVideo_EEffectType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EEffectType::None", (int64)EEffectType::None },
				{ "EEffectType::Speed", (int64)EEffectType::Speed },
				{ "EEffectType::Jump", (int64)EEffectType::Jump },
				{ "EEffectType::Power", (int64)EEffectType::Power },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Jump.DisplayName", "JumpBuff" },
				{ "Jump.Name", "EEffectType::Jump" },
				{ "ModuleRelativePath", "DataTableExample.h" },
				{ "None.DisplayName", "None" },
				{ "None.Name", "EEffectType::None" },
				{ "Power.DisplayName", "PowerBuff" },
				{ "Power.Name", "EEffectType::Power" },
				{ "Speed.DisplayName", "SpeedBuff" },
				{ "Speed.Name", "EEffectType::Speed" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_DatabaseTestVideo,
				nullptr,
				"EEffectType",
				"EEffectType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}

static_assert(std::is_polymorphic<FEffectStats>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FEffectStats cannot be polymorphic unless super FTableRowBase is polymorphic");

class UScriptStruct* FEffectStats::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern DATABASETESTVIDEO_API uint32 Get_Z_Construct_UScriptStruct_FEffectStats_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FEffectStats, Z_Construct_UPackage__Script_DatabaseTestVideo(), TEXT("EffectStats"), sizeof(FEffectStats), Get_Z_Construct_UScriptStruct_FEffectStats_Hash());
	}
	return Singleton;
}
template<> DATABASETESTVIDEO_API UScriptStruct* StaticStruct<FEffectStats>()
{
	return FEffectStats::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FEffectStats(FEffectStats::StaticStruct, TEXT("/Script/DatabaseTestVideo"), TEXT("EffectStats"), false, nullptr, nullptr);
static struct FScriptStruct_DatabaseTestVideo_StaticRegisterNativesFEffectStats
{
	FScriptStruct_DatabaseTestVideo_StaticRegisterNativesFEffectStats()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("EffectStats")),new UScriptStruct::TCppStructOps<FEffectStats>);
	}
} ScriptStruct_DatabaseTestVideo_StaticRegisterNativesFEffectStats;
	struct Z_Construct_UScriptStruct_FEffectStats_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EffectType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EffectType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_EffectType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EffectStrength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EffectStrength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EffectDescription_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_EffectDescription;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEffectStats_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FEffectStats_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEffectStats>();
	}
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectType_MetaData[] = {
		{ "Category", "EffectStats" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectType = { "EffectType", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEffectStats, EffectType), Z_Construct_UEnum_DatabaseTestVideo_EEffectType, METADATA_PARAMS(Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectStrength_MetaData[] = {
		{ "Category", "EffectStats" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectStrength = { "EffectStrength", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEffectStats, EffectStrength), METADATA_PARAMS(Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectStrength_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectStrength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectDescription_MetaData[] = {
		{ "Category", "EffectStats" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectDescription = { "EffectDescription", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FEffectStats, EffectDescription), METADATA_PARAMS(Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectDescription_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEffectStats_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectStrength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEffectStats_Statics::NewProp_EffectDescription,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEffectStats_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_DatabaseTestVideo,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"EffectStats",
		sizeof(FEffectStats),
		alignof(FEffectStats),
		Z_Construct_UScriptStruct_FEffectStats_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectStats_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FEffectStats_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEffectStats_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FEffectStats()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FEffectStats_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_DatabaseTestVideo();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("EffectStats"), sizeof(FEffectStats), Get_Z_Construct_UScriptStruct_FEffectStats_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FEffectStats_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FEffectStats_Hash() { return 330768231U; }
	void ADataTableExample::StaticRegisterNativesADataTableExample()
	{
	}
	UClass* Z_Construct_UClass_ADataTableExample_NoRegister()
	{
		return ADataTableExample::StaticClass();
	}
	struct Z_Construct_UClass_ADataTableExample_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EffectsTable_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EffectsTable;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SelectedEffectBP_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelectedEffectBP_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_SelectedEffectBP;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelectedEffect_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_SelectedEffect;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EffectType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EffectType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_EffectType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EffectStrength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EffectStrength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Description;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADataTableExample_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_DatabaseTestVideo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADataTableExample_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DataTableExample.h" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectsTable_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectsTable = { "EffectsTable", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADataTableExample, EffectsTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectsTable_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectsTable_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffectBP_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffectBP_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffectBP = { "SelectedEffectBP", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADataTableExample, SelectedEffectBP), Z_Construct_UEnum_DatabaseTestVideo_EEffectType, METADATA_PARAMS(Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffectBP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffectBP_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffect_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffect = { "SelectedEffect", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADataTableExample, SelectedEffect), METADATA_PARAMS(Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffect_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffect_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectType_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectType = { "EffectType", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADataTableExample, EffectType), Z_Construct_UEnum_DatabaseTestVideo_EEffectType, METADATA_PARAMS(Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectStrength_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectStrength = { "EffectStrength", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADataTableExample, EffectStrength), METADATA_PARAMS(Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectStrength_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectStrength_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADataTableExample_Statics::NewProp_Description_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "DataTableExample.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ADataTableExample_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADataTableExample, Description), METADATA_PARAMS(Z_Construct_UClass_ADataTableExample_Statics::NewProp_Description_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADataTableExample_Statics::NewProp_Description_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADataTableExample_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectsTable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffectBP_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffectBP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataTableExample_Statics::NewProp_SelectedEffect,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataTableExample_Statics::NewProp_EffectStrength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataTableExample_Statics::NewProp_Description,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADataTableExample_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADataTableExample>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADataTableExample_Statics::ClassParams = {
		&ADataTableExample::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ADataTableExample_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ADataTableExample_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADataTableExample_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADataTableExample_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADataTableExample()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADataTableExample_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADataTableExample, 1224169663);
	template<> DATABASETESTVIDEO_API UClass* StaticClass<ADataTableExample>()
	{
		return ADataTableExample::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADataTableExample(Z_Construct_UClass_ADataTableExample, &ADataTableExample::StaticClass, TEXT("/Script/DatabaseTestVideo"), TEXT("ADataTableExample"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADataTableExample);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
