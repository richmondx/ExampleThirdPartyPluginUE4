// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include "CatSoundLibrary.h"

class FCatSoundModule : public IModuleInterface
{
public:
	/**
	* Singleton-like access to this module's interface.  This is just for convenience!
	* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	*
	* @return Returns singleton instance, loading the module on demand if needed
	*/
	static inline FCatSoundModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FCatSoundModule >("Module");
	}

	/**
	* Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	*
	* @return True if the module is loaded and ready to use
	*/
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("Module");
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FString GetTheCatSound()
	{
		//UE_LOG(LogTemp, Log, TEXT("Gaze Location: %f %f"), GazePoint.X, GazePoint.Y);
		return FString(GetCatSound());
	}
private:
	void*	LibHandle;
};