#include "SmallTalkerEditorCommands.h"

#define LOCTEXT_NAMESPACE "FSmallTalkerEditorModule"

void FSmallTalkerEditorCommands::RegisterCommands()
{
	UI_COMMAND(ImportAction, "Import with string bundle", "Import with Excel.", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
