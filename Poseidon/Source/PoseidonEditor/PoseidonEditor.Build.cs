using UnrealBuildTool;
using System;
using System.IO;

public class PoseidonEditor : ModuleRules
{
    public PoseidonEditor( ReadOnlyTargetRules Target ) : base( Target )
    {
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
            new string[] {
                Path.Combine(ModuleDirectory, "Public")
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
                "Poseidon/Private",
            }
        );

        PrivateIncludePathModuleNames.AddRange(
            new string[] {
                "PlacementMode"
            }
        );

        // Add common dependencies.
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Poseidon",
                "Slate",
                "SlateCore",
                "Landscape",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "AppFramework",
                "AssetTools",
                "ContentBrowser",
                "DesktopWidgets",
                "EditorStyle",
                "EditorWidgets",
                "Engine",
                "InputCore",
                "LevelEditor",
                "MainFrame",
                "Projects",
                "PropertyEditor",
                "RHI",
                "RawMesh",
                "RenderCore",
                "TargetPlatform",
                "UnrealEd",
                "ApplicationCore",
                "CurveEditor",
                "Json",
                "SceneOutliner",
                "PropertyPath",
                "MaterialEditor"
            }
        );

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                "PlacementMode",
            }
        );
    }
}
