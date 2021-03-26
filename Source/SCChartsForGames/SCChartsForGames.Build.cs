// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SCChartsForGames : ModuleRules
{
	public SCChartsForGames(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "SCChartsFSM" });
		PublicIncludePaths.AddRange(new string[] {"../Plugins/SCChartsForUE/Source/SCChartsForUE//Public"});
		PrivateIncludePaths.AddRange(new string[] {"../Plugins/SCChartsForUE/Source/SCChartsForUE/Private", "../Plugins/SCChartsForUE/Source/SCChartsForUE/Classes"});
		PrivateDependencyModuleNames.AddRange(new string[] { "SCChartsForUE"});
		
		PublicIncludePaths.AddRange(new string[] {"../Plugins/SCChartsFSM/Source/SCChartsFSM//Public"});
		PrivateIncludePaths.AddRange(new string[] {"../Plugins/SCChartsFSM/Source/SCChartsFSM/Private", "../Plugins/SCChartsFSM/Source/SCChartsFSM/Classes"});
		PrivateDependencyModuleNames.AddRange(new string[] { "SCChartsFSM"});
		
		
		PublicIncludePaths.AddRange(new string[] {"../Plugins/RollingBallHS/Source/RollingBallHS//Public"});
		PrivateIncludePaths.AddRange(new string[] {"../Plugins/RollingBallHS/Source/RollingBallHS/Private", "../Plugins/RollingBallHS/Source/RollingBallHS/Classes"});
		PrivateDependencyModuleNames.AddRange(new string[] { "RollingBallHS"});
	}
}
