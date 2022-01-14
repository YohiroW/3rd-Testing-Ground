#pragma once

#include "CoreMinimal.h"
#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"
#include "LevelEditor.h"
#include "AssetTypeCategories.h"
#include "IAssetTypeActions.h"
#include "ISmallTalkerEditorPlugin.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSmallTalkerEditor, Log, All);

class FToolBarBuilder;
class FMenuBuilder;

#define LOCTEXT_NAMESPACE "FSmallTalkerEditorModule"

class FImportStringBundleContext
{
public:
	DECLARE_DELEGATE_OneParam(FOnImportStringBundleRequested, const FName /*SelectedFilePath*/);

	/** Makes the context menu widget */
	static void MakeContextMenu(
		const TArray<FName>& InSelectedAssetPaths,
		const FOnImportStringBundleRequested& InOnImportAssetRequested
	);

private:
	/** Handle when the "Import" button is clicked */
	static void ExecuteImportAsset(FOnImportStringBundleRequested InOnImportAssetRequested, FName InPath);
};


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
