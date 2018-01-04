// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
namespace UnrealBuildTool.Rules
{
	public class CatSound : ModuleRules
	{
		public CatSound(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			
			PrivateIncludePaths.AddRange(
				new string[] {
					"CatSound/Private",
				});
				
			
			PublicDependencyModuleNames.AddRange(
				new string[] {
					"Core",
				});
			
			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"CoreUObject",
					"Projects",
					"Engine",
					"Slate",
					"SlateCore",
				});
			
			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				});
			
			string TSEDir = Path.GetFullPath(Path.Combine (ModuleDirectory, "..", "..", "ThirdParty"));
			
			PrivateIncludePaths.Add(Path.Combine(TSEDir, "include"));
			
			if (Target.Platform == UnrealTargetPlatform.Win32)
			{
				string LibDir = Path.Combine(TSEDir, "lib", "windows", "x86");
				string DllPath = Path.Combine(LibDir, "CatSoundLibrary.dll");

				PublicLibraryPaths.Add(LibDir);
				PublicAdditionalLibraries.Add("CatSoundLibrary.lib");
				PublicDelayLoadDLLs.Add("CatSoundLibrary.dll");
				RuntimeDependencies.Add(new RuntimeDependency(DllPath));
			}
			else if (Target.Platform == UnrealTargetPlatform.Win64)
			{
				string LibDir = Path.Combine(TSEDir, "lib", "windows", "x64");
				string DllPath = Path.Combine(LibDir, "CatSoundLibrary.dll");

				PublicLibraryPaths.Add(LibDir);
				PublicAdditionalLibraries.Add("CatSoundLibrary.lib");
				PublicDelayLoadDLLs.Add("CatSoundLibrary.dll");
				RuntimeDependencies.Add(new RuntimeDependency(DllPath));
			}
			else
			{
				System.Console.WriteLine("Cat Sound Library does not supported this platform");
			} 
		}
	}
}
