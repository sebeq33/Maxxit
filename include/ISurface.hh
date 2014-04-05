#pragma once

#include <SDL2\SDL.h>

class ISurface
{
public:
	virtual ~ISurface() {}
	virtual void unload() = 0;
	virtual SDL_Surface *getSurface() = 0;
};