#include "CatSound.h"
#include "Core.h"
#include "ModuleManager.h"
#include "IPluginManager.h"
#include <stdio.h>
#include <assert.h>

#define LOCTEXT_NAMESPACE "FCatSoundModule"
typedef void (FCatSoundModule::*FUNC) (int);

void FCatSoundModule::StartupModule()
{
	// determine directory paths
	const FString BaseDir = IPluginManager::Get().FindPlugin("CatSound")->GetBaseDir();
	const FString LibDir = FPaths::Combine(*BaseDir, TEXT("ThirdParty"), TEXT("lib"));

#if PLATFORM_WINDOWS
#if PLATFORM_64BITS
	const FString Lib = FPaths::Combine(*LibDir, TEXT("windows"), TEXT("x64"), TEXT("CatSoundLibrary.dll"));
#else
	const FString Lib = FPaths::Combine(*LibDir, TEXT("windows"), TEXT("x86"), TEXT("CatSoundLibrary.dll"));
#endif
#endif
	LibHandle = FPlatformProcess::GetDllHandle(*Lib);

	if (LibHandle != nullptr)
	{
		// Init things here
	}
	else 
	{
		// Display Error here if dll isn't found
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("TobiiStreamEngine Error", "Failed to load Cat Sound Library dll"));
	}
}

void FCatSoundModule::ShutdownModule()
{	

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCatSoundModule, CatSound)