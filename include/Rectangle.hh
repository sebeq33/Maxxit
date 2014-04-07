#pragma once

#include <SDL2\SDL.h>
#include "ISurface.hh"

class Rectangle : public ISurface
{
private:
	Rectangle(const Rectangle &);
	Rectangle &operator=(const Rectangle &);

	SDL_Surface *rect;
	int sizeX, sizeY;
	Uint8 red, green, blue, alpha;
	bool modified;

	void createSurface();

public:
	Rectangle(int sizeX = 10, int sizeY = 10);
	~Rectangle();

	void setColorRed(Uint8 red);
	void setColorGreen(Uint8 green);
	void setColorBlue(Uint8 blue);
	void setColorAlpha(Uint8 alpha);
	void setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);


	bool preload();
	bool loaded() const;
	void unload();
	SDL_Surface *getSurface();
};