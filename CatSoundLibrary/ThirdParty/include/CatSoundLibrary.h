#pragma once

#ifdef CATSOUNDLIBRARY_EXPORTS  
#define CATSOUNDLIBRARY_API __declspec(dllexport)   
#else  
#define CATSOUNDLIBRARY_API __declspec(dllimport)   
#endif  


extern "C" CATSOUNDLIBRARY_API char* GetCatSound();
