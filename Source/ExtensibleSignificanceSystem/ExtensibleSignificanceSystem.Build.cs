// Copyright Chengll, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ExtensibleSignificanceSystem : ModuleRules
{
	public ExtensibleSignificanceSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		OptimizeCode = CodeOptimization.InShippingBuildsOnly;
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"SignificanceManager",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"DeveloperSettings",
				// ... add private dependencies that you statically link with here ...	
			}
			);
	}
}
