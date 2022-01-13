#include "SmallTalkerConversationAssetFactory.h"
#include "AssetTypeCategories.h"
#include "SmallTalkerConversation.h"

#define LOCTEXT_NAMESPACE "SmallTalkerConversationAssetFactory"

USmallTalkerConversationAssetFactory::USmallTalkerConversationAssetFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = USmallTalkerConversationAsset::StaticClass();
}

UObject* USmallTalkerConversationAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	USmallTalkerConversationAsset* NewAsset = NewObject<USmallTalkerConversationAsset>(InParent, Class, Name, Flags | RF_Transactional);
	return NewAsset;
}

FText USmallTalkerConversationAssetFactory::GetToolTip() const
{
	return LOCTEXT("SmallTalkerConversationTooltip", "Creates a default SmallTalker conversation asset");
}

bool USmallTalkerConversationAssetFactory::ShouldShowInNewMenu() const
{
	return true;
}

#undef LOCTEXT_NAMESPACE