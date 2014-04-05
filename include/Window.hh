#pragma once

#include <list>
#include <string>
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "Display.hh"
#include "IGui.hh"

//Ref SDL 1.2 to 2.0 FR : http://jeux.developpez.com/tutoriels/sdl-2/guide-migration/

class Window
{
private:
	Window(const Window &);
	Window &operator=(const Window &);

	SDL_Window *window;
	SDL_Surface *screen;
	SDL_Surface *icon; //replace by image
	std::list<IGui *> guiList;
	std::list<Display *> displayList;

	int sizeX, sizeY;
	std::string windowTitle;
	std::string iconPath;

public:
	Window(int sizeX = 800, 
		int sizeY = 640, 
		const std::string &windowTitle = "no name",
		const std::string &iconPath = "");
	~Window();

	void start(); //allocate and open window
	void resize(int sizeX, int sizeY);
	void setTitle(const std::string &title);
	const std::string &getWindowTitle() const;

	bool isFullScreen();
	void toggleFullScreen();

	void updateDisplays();              //Flip all Display from scratch (temporary display will disappear)
	void addDisplay(Display *);
	void removeDisplay(const Display *);

	void blitDisplay(Display *display);       //temporaly blit a display on the current screen
	void updateWindow();                //Flip the window with temporary blited display

	void addGui(IGui *gui);
	void removeGui(IGui *gui);
	IGui *popGui();
	std::list<IGui *> &getGuiList();

	SDL_Window *getWindow();

	int getSizeX() const;
	int getSizeY() const;
};