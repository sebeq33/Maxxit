#pragma once

#include <list>
#include <string>
#include <iostream>
#include <exception>
#include <SDL2\SDL.h>
#include <SDL2\SDL_ttf.h>
#include "Window.hh"
#include "Font.hh"
#include "Image.hh"
#include "IGui.hh"

class SDLGame
{
private:
	// no copy
	SDLGame(const SDLGame &);
	SDLGame& operator=(const SDLGame &);

protected:
	std::list<Font *> loadedFontList;
	std::list<ISurface *> loadedSurfaceList;
	Window screen;

	virtual void startGame() = 0; //done by the game implementing this class

public:
	SDLGame(int sizeX, int sizeY, const std::string &title, const std::string &iconPath);
	~SDLGame();
	
	void start();

	void addSurface(ISurface *img);
	ISurface *popSurface();
	std::list<ISurface *> &getSurfaceList();

	void addFont(Font *font);
	Font *popFont();
	std::list<Font *> &getFontList();
};