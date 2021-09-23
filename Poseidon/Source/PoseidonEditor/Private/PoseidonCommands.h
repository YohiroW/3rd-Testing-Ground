#pragma once

#include "Framework/Commands/Commands.h"
#include "Misc/SlowTask.h"
#include "Delegates/IDelegateInstance.h"


struct FSlowTask;

// Class containing commands for Houdini Engine actions
class FPoseidonCommands : public TCommands<FPoseidonCommands>
{
public:
	FPoseidonCommands(): TCommands<FPoseidonCommands>(
			             TEXT("Poseidon"), // Context name for fast lookup
			             NSLOCTEXT("Contexts", "Poseidon", "Poseidon Editor"), // Localized context name for displaying
			             NAME_None, // Parent context name. 
			             FName(TEXT("PoseidonStyle"))
                         )
	{
	}

	// TCommand<> interface
	virtual void RegisterCommands() override;

public:

    static bool IsSessionValid();
	// Menu action to bake/replace all
	static void RebuildAll();

public:
	TSharedPtr<FUICommandInfo> RebuildAllCommand;

protected:


};
