#pragma once

#include <list>
#include <SDL2\SDL.h>
#include "IDisplay.hh"

class Window
{
private:
	Window(const Window &);
	Window &operator=(const Window &);

	SDL_Surface *screen;
	std::list<IDisplay &> elements;
	int sizeX, sizeY;

public:
	Window(int x, int y); //open window, set window title / size / icon ...etc
	~Window();
	void updateDisplay(); //Flip Display
	void addDisplay(const IDisplay &);
	void removeDisplay(const IDisplay &);
	int getSizeX() const;
	int getSizeY() const;
};