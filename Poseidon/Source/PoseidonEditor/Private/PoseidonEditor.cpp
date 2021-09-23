// Copyright Epic Games, Inc. All Rights Reserved.

#include "PoseidonEditor.h"
#include "Misc/Paths.h"
#include "Interfaces/IPluginManager.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "AssetRegistryModule.h"
#include "PropertyEditorModule.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "LevelEditor.h"
#include "Templates/SharedPointer.h"
#include "Framework/Application/SlateApplication.h"
#include "HAL/ConsoleManager.h"
#include "Editor/UnrealEdEngine.h"
#include "Editor.h"
#include "UnrealEdGlobals.h"
#include "Engine/Selection.h"
#include "Widgets/Input/SCheckBox.h"
#include "Logging/LogMacros.h"
#include "MultiBox/MultiBoxExtender.h"

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
	ExtendMenu();

	// Store the instance.
	FPoseidonEditor::PoseidonEditorInstance = this;
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

	BindMenuCommands();

	MenuExtender = MakeShareable(new FExtender);

	// Added section of mine 
	MenuExtender->AddMenuExtension(
		"TestPoseidon",
		EExtensionHook::After,
		PoseidonUICommands,
		FMenuExtensionDelegate::CreateRaw(this, &FPoseidonEditor::AddPoseidonMainMenuExtension)
	);

	MenuExtender->AddMenuBarExtension(
		"EditPoseidon",
		EExtensionHook::After,
		PoseidonUICommands,
		FMenuBarExtensionDelegate::CreateRaw(this, &FPoseidonEditor::AddPoseidonEditorMenu)
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

void FPoseidonEditor::BindMenuCommands()
{
	PoseidonUICommands = MakeShareable(new FUICommandList);

	FPoseidonCommands::Register();
	const FPoseidonCommands& commands = FPoseidonCommands::Get();

	// 
	PoseidonUICommands->MapAction(
		commands.RebuildAllCommand,
		FExecuteAction::CreateLambda([](){ return FPoseidonCommands::RebuildAll(); }),
		FCanExecuteAction::CreateLambda([](){ return FPoseidonCommands::IsSessionValid(); })
	);

}


#undef LOCTEXT_NAMESPACE