// Copyright Epic Games, Inc. All Rights Reserved.

#include "PoseidonEditor.h"
#include "Misc/Paths.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FPoseidonEditorModule"

IMPLEMENT_MODULE(FPoseidonEditor, PoseidonEditor);
DEFINE_LOG_CATEGORY(LogPoseidonEditor);

FPoseidonEditor* FPoseidonEditor::PoseidonEditorInstance = nullptr;

FPoseidonEditor& FPoseidonEditor::Get()
{
	return *PoseidonEditorInstance;
}

bool FPoseidonEditor::IsInitialized()
{
	return FPoseidonEditor::PoseidonEditorInstance != nullptr;
}

void FPoseidonEditor::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

}

void FPoseidonEditor::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FPoseidonEditor::ExtendMenu()
{
	if (IsRunningCommandlet())
		return;

	MenuExtender = MakeShareable(new FExtender);

	// Added section of mine 
	MenuExtender->AddMenuExtension(
		"TestPoseidon",
		EExtenderHook::After,
		PoseidonUICommands,
		FMenuExtensionDelegate::CreateRaw(this, &FPoseidonEditor::AddPoseidonMainMenuExtension)
	);

	MenuExtender->AddMenuBarExtension(
		"EditPoseidon",
		EExtenderHook::After,
		PoseidonUICommands,
		FMenuBarExtensionDelegate::CreateRaw(this, &FPoseidonEditorMenu::AddPoseidonEditorMenu)
	);

	FLevelEditorModule& levelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	levelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
}

void FPoseidonEditor::AddPoseidonEditorMenu(FMenuBarBuilder& builder)
{
	// View
	builder.AddPullDownMenu(
		LOCTEXT("PoseidonLabel", "Poseidon"),
		LOCTEXT("PoseidonMenu_ToolTip", "Open menu"),
		FNewMenuDelegate::CreateRaw(this, &FPoseidonEditor::AddPoseidonMainMenuExtension),
		"View");
}

void FPoseidonEditor::AddPoseidonMainMenuExtension(FMenuBuilder& builder)
{
	builder.BeginSection("Session", LOCTEXT("SessionLabel", "Session"));

	// Insert UI commands below

}

void FPoseidonEditor::AddPoseidonFileMenuExtension(FMenuBuilder& builder)
{
	builder.BeginSection("Poseidon", LOCTEXT("PoseidonLabel", "Poseidon"));

	// Insert UI commands below

}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPoseidonEditorModule, Poseidon)