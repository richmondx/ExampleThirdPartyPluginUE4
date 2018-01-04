#include "CatSound.h"
#include "CoreMinimal.h"
#include "IPluginManager.h"
#include "Misc/App.h"
#include "Misc/MessageDialog.h"
#include <stdio.h>
#include <assert.h>
#include "CatSoundLibrary.h"

#define LOCTEXT_NAMESPACE "FCatSoundModule"

class FCatSoundModule : public ICatSoundModule
{
public:
	/** IModuleInterface interface */
	virtual void StartupModule() override
	{
		FString BuildArch;
#if PLATFORM_64BITS
		BuildArch = FString(TEXT("x64"));
#else
		BuildArch = FString(TEXT("x86"));
#endif
		// Get directory paths
		const FString PluginPath = IPluginManager::Get().FindPlugin("CatSound")->GetBaseDir();
		const FString RootLibPath = PluginPath / FString::Printf(TEXT("ThirdParty/lib/windows/%s/"), *BuildArch);

		FPlatformProcess::PushDllDirectory(*RootLibPath);
		CatSoundDLLHandle = FPlatformProcess::GetDllHandle(*(RootLibPath + "CatSoundLibrary.dll"));
        FPlatformProcess::PopDllDirectory(*RootLibPath);

		if (CatSoundDLLHandle != nullptr)
		{
			// Init things here
		}
		else
		{
			// Display error here if dll isn't found
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("CatSoundModule Error", "Failed to load CatSoundLibrary.dll"));
		}
	}

	virtual void ShutdownModule() override
	{
		if (CatSoundDLLHandle != nullptr)
		{
			FPlatformProcess::FreeDllHandle(CatSoundDLLHandle);
			CatSoundDLLHandle = nullptr;
		}
	}

	/** ICatSoundModule interface */
	virtual FString GetCatSound() const override
	{
		return FString(CatSoundLibrary::GetCatSound());
	}

private:
	void* CatSoundDLLHandle;
};

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FCatSoundModule, CatSound)
