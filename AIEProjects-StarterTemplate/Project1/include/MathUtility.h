#pragma once

#ifdef MATHLIBRARYDLL_EXPORTS
#define MATHLIBRARYDLL_API __declspec(dllexport) 
#else
#define MATHLIBRARYDLL_API __declspec(dllimport) 
#endif

namespace MathLibrary
{
	MATHLIBRARYDLL_API float Clamp(float num, float min, float max);
}