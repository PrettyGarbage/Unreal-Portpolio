// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StudyProject : ModuleRules
{
	public StudyProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore",
			
			//JSON Module	
			"Json", "JsonUtilities",
			
			//Enhanced Input
			"EnhancedInput",
			
			//AI
			"NavigationSystem", "AIModule", "GameplayTasks",
			
			//UI
			"UMG",
			
			//Geometry
			"GeometryCollectionEngine",
			
			//Niagara
			"Niagara",
			
			//Motion Warping
			"MotionWarping",
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			//Custom Modules
			"StudyProjectSettings",
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
