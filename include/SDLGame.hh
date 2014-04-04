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
#include "IGame.hh"

class SDLGame
{
private:
	SDLGame(const SDLGame &);
	SDLGame& operator=(const SDLGame &);

	std::list<Font *> fontList;
	std::list<Image *> imageList; //stacks ? w FontID ImageID ?
	std::list<IGui *> guiList;
	Window screen;

	virtual void startGame() = 0;

public:
	SDLGame(int sizeX, int sizeY, const std::string &title, const std::string &iconPath);
	~SDLGame();
	
	void start();

	void addGui(IGui *gui);
	IGui *popGui();
	std::list<IGui *> &getGuiList();

	void addImage(Image *img);
	Image *popImage();
	std::list<Image *> &getImageList();

	void addFont(Font *font);
	Font *popFont();
	std::list<Font *> &getFontList();

	void setWindow(Window *screen);
	Window &getWindow();
};