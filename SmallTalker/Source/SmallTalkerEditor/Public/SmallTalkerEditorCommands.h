#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "Styling/SlateStyle.h"

class FSmallTalkerEditorCommands : public TCommands<FSmallTalkerEditorCommands>
{
public:

	FSmallTalkerEditorCommands()
		: TCommands<FSmallTalkerEditorCommands>(
			TEXT("SmallTalkerEditor"), 
			NSLOCTEXT("Contexts", "SmallTalkerEditor", "SmallTalkerEditor Plugin"),
			NAME_None, 
			FName(TEXT("SmallTalkerEditorStyle"))
			)
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> ImportAction;
};