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

protected:
	std::list<Font *> fontList;
	std::list<Image *> imageList; //stacks ? w FontID ImageID ?
	Window screen;

	virtual void startGame() = 0; //done by the game implementing this class

public:
	SDLGame(int sizeX, int sizeY, const std::string &title, const std::string &iconPath);
	~SDLGame();
	
	void start();

	void addImage(Image *img);
	Image *popImage();
	std::list<Image *> &getImageList();

	void addFont(Font *font);
	Font *popFont();
	std::list<Font *> &getFontList();
};