// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DatabaseTestVideo/DatabaseTestVideoGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDatabaseTestVideoGameModeBase() {}
// Cross Module References
	DATABASETESTVIDEO_API UClass* Z_Construct_UClass_ADatabaseTestVideoGameModeBase_NoRegister();
	DATABASETESTVIDEO_API UClass* Z_Construct_UClass_ADatabaseTestVideoGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_DatabaseTestVideo();
// End Cross Module References
	void ADatabaseTestVideoGameModeBase::StaticRegisterNativesADatabaseTestVideoGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ADatabaseTestVideoGameModeBase_NoRegister()
	{
		return ADatabaseTestVideoGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ADatabaseTestVideoGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADatabaseTestVideoGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_DatabaseTestVideo,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADatabaseTestVideoGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "DatabaseTestVideoGameModeBase.h" },
		{ "ModuleRelativePath", "DatabaseTestVideoGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADatabaseTestVideoGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADatabaseTestVideoGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADatabaseTestVideoGameModeBase_Statics::ClassParams = {
		&ADatabaseTestVideoGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ADatabaseTestVideoGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADatabaseTestVideoGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADatabaseTestVideoGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADatabaseTestVideoGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADatabaseTestVideoGameModeBase, 622377891);
	template<> DATABASETESTVIDEO_API UClass* StaticClass<ADatabaseTestVideoGameModeBase>()
	{
		return ADatabaseTestVideoGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADatabaseTestVideoGameModeBase(Z_Construct_UClass_ADatabaseTestVideoGameModeBase, &ADatabaseTestVideoGameModeBase::StaticClass, TEXT("/Script/DatabaseTestVideo"), TEXT("ADatabaseTestVideoGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADatabaseTestVideoGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
