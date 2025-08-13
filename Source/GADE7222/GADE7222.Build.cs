// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GADE7222 : ModuleRules
{
	public GADE7222(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"GADE7222",
			"GADE7222/Variant_Platforming",
			"GADE7222/Variant_Combat",
			"GADE7222/Variant_Combat/AI",
			"GADE7222/Variant_SideScrolling",
			"GADE7222/Variant_SideScrolling/Gameplay",
			"GADE7222/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
