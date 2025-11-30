using UnrealBuildTool;

public class CustomGraph : ModuleRules
{
    public CustomGraph(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "AssetTools",
            "EditorSubsystem",
            "EditorFramework",
            "AssetDefinition"
        });

    }
}
