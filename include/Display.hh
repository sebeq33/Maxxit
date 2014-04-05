#pragma once

#include <SDL2\SDL.h>
#include "ISurface.hh"

class Display
{
private:
	ISurface *surface;
	int posX, posY;

public:
	Display(ISurface *surface = NULL, int posX = 0, int posY = 0);
	~Display();
	int getPosX() const;
	int getPosY() const;
	
	
	/*
	** not return const SDL_Surface because SDL_BlitSurface use non-const
	** function itself not const to be able to load the function only when asked but can still be pre-loaded
	*/
	ISurface *getSurface();
	void setSurface(ISurface *surface);
};