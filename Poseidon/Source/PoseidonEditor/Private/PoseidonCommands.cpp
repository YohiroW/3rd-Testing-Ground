#include "PoseidonCommands.h"

#include "DesktopPlatformModule.h"
#include "Interfaces/IMainFrameModule.h"
#include "EditorDirectories.h"
#include "Misc/ScopedSlowTask.h"
#include "Async/Async.h"
#include "FileHelpers.h"
#include "AssetRegistryModule.h"
#include "Engine/ObjectLibrary.h"
#include "ObjectTools.h"
#include "CoreGlobals.h"
#include "Misc/FeedbackContext.h"
#include "HAL/FileManager.h"
#include "Modules/ModuleManager.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FPoseidonCommands"

void FPoseidonCommands::RegisterCommands()
{	
	UI_COMMAND(RebuildAllCommand, "Rebuild All", "Rebuilds all Assets Actors in the current level.", EUserInterfaceActionType::Button, FInputChord());
	//UI_COMMAND(_RebuildSelected, "Rebuild Selection", "Rebuilds selected Asset Actors in the current level.", EUserInterfaceActionType::Button, FInputChord(EKeys::R, EModifierKey::Control | EModifierKey::Alt));
}

bool FPoseidonCommands::IsSessionValid()
{
	// Test only for now
	return true;
}

void FPoseidonCommands::RebuildAll()
{
	UE_LOG(LogTemp, Warning, TEXT("TO BE IMPLEMENT.."));
}