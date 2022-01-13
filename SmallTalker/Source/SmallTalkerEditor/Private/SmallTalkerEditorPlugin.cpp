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
		FExecuteAction::CreateRaw(this, &FSmallTalkerEditorPlugin::ImportActionClicked),
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
	//Builder.BeginSection("Help", LOCTEXT("SmallTalkerMenu_Help", "Help"));
	//Builder.AddMenuEntry(FSmallTalkerEditorCommands::Get().MarketplaceAction);
	//Builder.AddMenuEntry(FSmallTalkerEditorCommands::Get().ForumsAction);
	//Builder.AddMenuEntry(FSmallTalkerEditorCommands::Get().HelpAction);
	//Builder.AddMenuEntry(FSmallTalkerEditorCommands::Get().IssuesAction);
	//Builder.AddMenuEntry(FSmallTalkerEditorCommands::Get().DiscordAction);
	//Builder.EndSection();
	
	Builder.BeginSection("Dev", LOCTEXT("SmallTalkerMenu_Dev", "Dev"));
	Builder.AddMenuEntry(FSmallTalkerEditorCommands::Get().ImportAction);
	Builder.EndSection();
}


#undef LOCTEXT_NAMESPACE