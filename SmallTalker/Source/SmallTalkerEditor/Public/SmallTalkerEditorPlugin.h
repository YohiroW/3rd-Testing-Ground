#pragma once

#include "CoreMinimal.h"
#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"
#include "LevelEditor.h"
#include "AssetTypeCategories.h"
#include "IAssetTypeActions.h"
#include "ISmallTalkerEditorPlugin.h"

class FToolBarBuilder;
class FMenuBuilder;

#define LOCTEXT_NAMESPACE "FSmallTalkerEditorModule"

class FSmallTalkerEditorPlugin : public ISmallTalkerEditorPlugin
{
public:
	static EAssetTypeCategories::Type GetAssetCategory() { return SmallTalkerAssetCategory; }

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command. */
	void ImportActionClicked();

private:
	void AddMenuBarExtension(FMenuBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

private:
	TSharedPtr<class FUICommandList> PluginCommands;

	static EAssetTypeCategories::Type SmallTalkerAssetCategory;

	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
};
