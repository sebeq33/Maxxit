#pragma once

#include <SDL2\SDL.h>

class ISurface
{
public:
	virtual ~ISurface() {}
	virtual bool preload() = 0;
	virtual bool loaded() const = 0;
	virtual void unload() = 0;
	virtual SDL_Surface *getSurface() = 0;
};