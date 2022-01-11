#include "ISmallTalkerEditorPlugin.h"
#include "SmallTalkerEditorCommands.h"

#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"
#include "LevelEditor.h"

class FToolBarBuilder;
class FMenuBuilder;

#define LOCTEXT_NAMESPACE "FSmallTalkerEditorModule"

class FSmallTalkerEditorPlugin : public ISmallTalkerEditorPlugin
{
public:
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
};
