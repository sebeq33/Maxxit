#pragma once

#include <SDL2\SDL.h>

class IDisplay
{
public:
	virtual ~IDisplay() {};
	virtual int getPosX() const = 0;
	virtual int getPosY() const = 0;
	virtual const SDL_Surface *getSurface() const;
};