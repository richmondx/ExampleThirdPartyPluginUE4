#pragma once

#include "Engine.h"
#include "CatSoundBPLibrary.generated.h"

UCLASS()
class UCatSoundBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Cat Sound", Keywords = "Get Cat Sound GetCatSound getcatsound"), Category = "AnimalSound")
	static FString GetCatSound();
};
