#include "SmallTalkerEditorPlugin.h"
#include "ISmallTalkerEditorPlugin.h"
#include "SmallTalkerEditorCommands.h"

#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"
#include "LevelEditor.h"

#include "AssetTypeActions_SmallTalkerConversation.h"

class FToolBarBuilder;
class FMenuBuilder;

#define LOCTEXT_NAMESPACE "FSmallTalkerEditorModule"

IMPLEMENT_MODULE(FSmallTalkerEditorPlugin, SmallTalkerEditor)
DEFINE_LOG_CATEGORY(LogSmallTalkerEditor);

EAssetTypeCategories::Type FSmallTalkerEditorPlugin::SmallTalkerAssetCategory;

void FSmallTalkerEditorPlugin::StartupModule()
{
	// Load necessary module
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

#if NEED_CUSTOM_CATEGPRY
	SmallTalkerAssetCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("SmallTalker")), LOCTEXT("SmallTalkerAssetCategory", "Conversation"));
#endif

	// Helper lambda for registering asset type actions for automatic cleanup on shutdown
	auto RegisterAssetTypeAction = [&](TSharedRef<IAssetTypeActions> Action)
	{
		AssetTools.RegisterAssetTypeActions(Action);
		CreatedAssetTypeActions.Add(Action);
	};

	// Register custom assets
	RegisterAssetTypeAction(MakeShareable(new FAssetTypeActions_SmallTalkerConversation));

	FSmallTalkerEditorCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FSmallTalkerEditorCommands::Get().ImportAction,
		FExecuteAction::CreateLambda([]() { return FSmallTalkerEditorCommands::ImportStringBundle(); }),
		FCanExecuteAction());

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuBarExtension("Window", EExtensionHook::After, PluginCommands, FMenuBarExtensionDelegate::CreateRaw(this, &FSmallTalkerEditorPlugin::AddMenuBarExtension));
		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
}

void FSmallTalkerEditorPlugin::ShutdownModule()
{
	FSmallTalkerEditorCommands::Unregister();
}

void FSmallTalkerEditorPlugin::ImportActionClicked()
{
	// Request file path

}

void FSmallTalkerEditorPlugin::AddMenuBarExtension(FMenuBarBuilder& Builder)
{
	Builder.AddPullDownMenu(
		LOCTEXT("SmallTalkerMenu", "SmallTalker Menu"),
		LOCTEXT("SmallTalkerMenu_ToolTip", "Open SmallTalker Help and Documentation"),
		FNewMenuDelegate::CreateRaw(this, &FSmallTalkerEditorPlugin::AddMenuExtension),
		"SmallTalker 2");
}

void FSmallTalkerEditorPlugin::AddMenuExtension(FMenuBuilder& Builder)
{	
	Builder.BeginSection("Dev", LOCTEXT("SmallTalkerMenu_Dev", "Dev"));
	Builder.AddMenuEntry(FSmallTalkerEditorCommands::Get().ImportAction);
	Builder.EndSection();
}


#undef LOCTEXT_NAMESPACE
//
//void FImportStringBundleContext::MakeContextMenu(const TArray<FName>& InSelectedAssetPaths, const FOnImportStringBundleRequested& InOnImportAssetRequested)
//{
//	const FCanExecuteAction CanExecuteAssetActionsDelegate = FCanExecuteAction::CreateLambda([NumSelectedAssetPaths = InSelectedAssetPaths.Num()]()
//	{
//		// We can execute asset actions when we only have a single asset path selected
//		return NumSelectedAssetPaths == 1;
//	});
//
//	const FName FirstSelectedPath = (InSelectedAssetPaths.Num() > 0) ? InSelectedAssetPaths[0] : FName();
//
//	// Import
//	if (InOnImportAssetRequested.IsBound() && !FirstSelectedPath.IsNone())
//	{
//		{
//			FToolMenuSection& Section = Menu->AddSection("ContentBrowserImportAsset", LOCTEXT("ImportAssetMenuHeading", "Import Asset"));
//			Section.AddMenuEntry(
//				"ImportAsset",
//				FText::Format(LOCTEXT("ImportAsset", "Import to {0}..."), FText::FromName(FirstSelectedPath)),
//				LOCTEXT("ImportAssetTooltip_NewAsset", "Imports an asset from file to this folder."),
//				FSlateIcon(FEditorStyle::GetStyleSetName(), "ContentBrowser.ImportIcon"),
//				FUIAction(
//					FExecuteAction::CreateStatic(&FImportStringBundleContext::ExecuteImportAsset, InOnImportAssetRequested, FirstSelectedPath),
//					CanExecuteAssetActionsDelegate
//				)
//			);
//		}
//	}
//}
//
//void FImportStringBundleContext::ExecuteImportAsset(FOnImportStringBundleRequested InOnImportStringBundleRequested, FName InPath)
//{
//	InOnImportStringBundleRequested.ExecuteIfBound(InPath);
//}
