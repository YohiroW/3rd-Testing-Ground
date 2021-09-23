// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IPoseidonEditor.h"

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPoseidonEditor, Log, All);

class FExtender;

class POSEIDONEDITOR_API FPoseidonEditor : public IPoseidonEditor
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

// Interfaces implementation
	/** Register and unregister component visualizers used by this module. **/
	virtual void RegisterComponentVisualizers() {}
	virtual void UnregisterComponentVisualizers() {}

	/** Register and unregister detail presenters used by this module. **/
	virtual void RegisterDetails() {}
	virtual void UnregisterDetails() {}

	/** Register and unregister asset type actions. **/
	virtual void RegisterAssetTypeActions() {}
	virtual void UnregisterAssetTypeActions() {}

	/** Create and register / unregister asset brokers. **/
	virtual void RegisterAssetBrokers() {}
	virtual void UnregisterAssetBrokers() {}

	/** Create and register actor factories. **/
	virtual void RegisterActorFactories() {}

	/** Extend menu. **/
	virtual void ExtendMenu();

	/** Register and unregister thumbnails. **/
	virtual void RegisterThumbnails() {}
	virtual void UnregisterThumbnails() {}

	/** Register and unregister for undo/redo notifications. **/
	virtual void RegisterForUndo() {}
	virtual void UnregisterForUndo() {}

	/** Create custom modes **/
	virtual void RegisterModes() {}
	virtual void UnregisterModes() {}

	/** Create custom placement extensions */
	virtual void RegisterPlacementModeExtensions() {}
	virtual void UnregisterPlacementModeExtensions() {}
// End Interfaces

	// Return singleton instance of PoseidonEditor, used internally.
	static FPoseidonEditor& Get();

	// Return true if singleton instance has been created.
	static bool IsInitialized();

	// Returns the plugin's directory
	static FString GetPoseidonPluginDir();

// Begin menu extension
	void AddPoseidonMainMenuExtension(FMenuBuilder& builder);
	void AddPoseidonFileMenuExtension(FMenuBuilder& builder);
	void AddPoseidonEditorMenu(FMenuBarBuilder& builder);
//
protected:
	// Binds the commands used by the menus
	void BindMenuCommands();

private:

	// Nested instance, used internally
	static FPoseidonEditor* PoseidonEditorInstance;

	//
	TSharedPtr<FExtender> MenuExtender;
	//
	TSharedPtr<class FUICommandList> PoseidonUICommands;

};
