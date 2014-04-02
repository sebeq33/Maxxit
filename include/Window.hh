#pragma once

#include <list>
#include <string>
#include <SDL2\SDL.h>
#include "IDisplay.hh"

class Window
{
private:
	Window(const Window &);
	Window &operator=(const Window &);

	SDL_Window *screen;
	SDL_Surface *icon;
	std::list<IDisplay *> elements;
	int sizeX, sizeY;
	std::string windowTitle;
	std::string iconPath;

public:
	Window(int sizeX = 800, 
		int sizeY = 640, 
		const std::string &windowTitle = "no name",
		const std::string &iconPath = ""); //open window, set window title / size / icon ...etc
	~Window();

	void start();

	void updateDisplay(); //Flip Display
	void addDisplay(const IDisplay *);
	void removeDisplay(const IDisplay *);
	int getSizeX() const;
	int getSizeY() const;
};