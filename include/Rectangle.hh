#pragma once

#include <SDL2\SDL.h>
#include "IDisplay.hh"

class Rectangle : public IDisplay
{
private:
	Rectangle(const Rectangle &);
	Rectangle &operator=(const Rectangle &);

	//TODO IMPORTANT Need to find a way to share a surface between IDisplay without double free
	//to get plural positions printed for 1 same surface loaded
	SDL_Surface *rect;
	int posX, posY, sizeX, sizeY;
	Uint8 red, green, blue, alpha;
	bool modified;

	void createSurface();

public:
	Rectangle(int posX = 0, int posY = 0, int sizeX = 0, int sizeY = 0);
	~Rectangle();

	void setColorRed(Uint8 red);
	void setColorGreen(Uint8 green);
	void setColorBlue(Uint8 blue);
	void setColorAlpha(Uint8 alpha);
	void setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);

	int getPosX() const;
	int getPosY() const;
	SDL_Surface *getSurface();
};