using System.IO;
using UnrealBuildTool;

public class SmallTalkerEditor : ModuleRules
{
    public SmallTalkerEditor(ReadOnlyTargetRules rules) : base(rules)
    {
		//bEnforceIWYU = true;
		//bLegacyPublicIncludePaths = false;

		OptimizeCode = CodeOptimization.Never;

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