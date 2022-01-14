#pragma once

#include "AssetTypeActions_Base.h"

class FAssetTypeActions_SmallTalkerConversation : public FAssetTypeActions_Base
{
public:

	// Begin IAssetTypeActions Interface
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override { return FColor(112, 146, 190); }
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	//virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; }
	//virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
	//virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
	// End IAssetTypeActions Interface
};