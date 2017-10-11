#include "CatSoundBPLibrary.h"
#include "CatSound.h"

UCatSoundBPLibrary::UCatSoundBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

FString UCatSoundBPLibrary::GetCatSound()
{
	return FCatSoundModule::GetTheCatSound();
}

