#include "SmallTalkerEditorCommands.h"
#include "SmallTalkerEditorPlugin.h"

#include "FileHelper.h"
#include "Paths.h"
#include "IDesktopPlatform.h"
#include "DesktopPlatformModule.h"

#define LOCTEXT_NAMESPACE "FSmallTalkerEditorModule"

TArray<FString> GetPathByFileDialog()
{
	TArray<FString> OpenFileNames;
	FString ExtensionStr = TEXT("*.xlsx");

	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	DesktopPlatform->OpenFileDialog(nullptr, TEXT("Explorer"), FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()), TEXT(""), *ExtensionStr, EFileDialogFlags::Multiple, OpenFileNames);

	return OpenFileNames;
}

void FSmallTalkerEditorCommands::RegisterCommands()
{
	UI_COMMAND(ImportAction, "Import with string bundle", "Import with Excel.", EUserInterfaceActionType::Button, FInputGesture());
}

void FSmallTalkerEditorCommands::ImportStringBundle()
{
	// Get file path
	TArray<FString> filePaths = GetPathByFileDialog();

	// Should be only one file selected
	for (FString path: filePaths)
	{
		UE_LOG(LogSmallTalkerEditor, Log, TEXT("%s"), *path);
	}
}

#undef LOCTEXT_NAMESPACE
