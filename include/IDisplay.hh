#pragma once

#include <SDL2\SDL.h>

class IDisplay
{
public:
	virtual ~IDisplay() {}
	virtual int getPosX() const = 0;
	virtual int getPosY() const = 0;
	
	/*
	** not return const SDL_Surface because SDL_BlitSurface use non-const
	** function itself not const to be able to load the function only when asked but can still be pre-loaded
	*/
	virtual SDL_Surface *getSurface() = 0; 
};