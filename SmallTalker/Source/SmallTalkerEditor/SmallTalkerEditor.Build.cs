using System.IO;
using UnrealBuildTool;

public class SmallTalkerEditor : ModuleRules
{
    public SmallTalkerEditor(ReadOnlyTargetRules rules) : base(rules)
    {
		//bEnforceIWYU = true;
		//bLegacyPublicIncludePaths = false;

		OptimizeCode = CodeOptimization.Never;

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				"Runtime/Core/Public/Misc",
				"Developer/DesktopPlatform/Public"
			}
			);

		PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
				// ... add other public dependencies that you statically link with here ...
                
            }
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                // ... add private dependencies that you statically link with here ...	
                "Engine",
                "Slate",
                "SlateCore",
                "RenderCore",
                "RHI",
                "NavigationSystem",
                "UnrealEd",
                "LevelEditor",
                "PropertyEditor",
                "AssetTools",
                "AssetRegistry",
                "Projects",
                "EditorStyle",
                "InputCore",

				"SmallTalker"

            }
            );
    }
}