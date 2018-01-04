#pragma once
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CatSoundBPLibrary.generated.h"

UCLASS()
class UCatSoundBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Cat Sound", Keywords = "Get Cat Sound"), Category = "Sound")
	static FString GetCatSound();
};
