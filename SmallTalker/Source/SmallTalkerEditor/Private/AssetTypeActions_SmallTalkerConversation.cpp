// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetTypeActions_SmallTalkerConversation.h"
#include "SmallTalkerConversation.h"
#include "SmallTalkerEditorPlugin.h"

#define LOCTEXT_NAMESPACE "SmallTalkerConversation"

#define NEED_CUSTOM_CATEGPRY 0

FText FAssetTypeActions_SmallTalkerConversation::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "FAssetTypeActions_SmallTalkerConversation", "SmallTalker Conversation");
}

UClass* FAssetTypeActions_SmallTalkerConversation::GetSupportedClass() const 
{
	return USmallTalkerConversationAsset::StaticClass();
}

uint32 FAssetTypeActions_SmallTalkerConversation::GetCategories() 
{
#if NEED_CUSTOM_CATEGPRY
	return FSmallTalkerEditorPlugin::GetAssetCategory();
#else
	return EAssetTypeCategories::Misc;
#endif
}

#undef LOCTEXT_NAMESPACE