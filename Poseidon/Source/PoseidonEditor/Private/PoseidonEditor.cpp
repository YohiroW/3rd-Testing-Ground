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

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPoseidonEditorModule, Poseidon)