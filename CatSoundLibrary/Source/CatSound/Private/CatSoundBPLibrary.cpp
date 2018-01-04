#include "CatSoundBPLibrary.h"
#include "CatSound.h"
#include "ModuleManager.h"

UCatSoundBPLibrary::UCatSoundBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FString UCatSoundBPLibrary::GetCatSound()
{
	ICatSoundModule* CatSoundModule = &FModuleManager::LoadModuleChecked<ICatSoundModule>("CatSound");
	return CatSoundModule->GetCatSound();
}
