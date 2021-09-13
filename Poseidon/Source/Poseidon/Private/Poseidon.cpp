// Copyright Epic Games, Inc. All Rights Reserved.

#include "Poseidon.h"
#include "Misc/Paths.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FPoseidonModule"

void FPoseidonModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FString shaderPath;
	if (TSharedPtr<IPlugin> poseidon = IPluginManager::Get().FindPlugin(TEXT("Poseidon")))
	{
		shaderPath = FPaths::Combine(poseidon->GetBaseDir(), TEXT("Shaders"));
	}
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/Poseidon"), shaderPath);
}

void FPoseidonModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPoseidonModule, Poseidon)