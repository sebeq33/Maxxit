#pragma once

#include "Font.h"
#include "Image.h"
#include "IGui.h"
#include "Window.h"

class SDLGame
{
private:
	SDLGame(const SDLGame &);
	SDLGame& operator=(const SDLGame &);

	std::list<Font &> fontList;
	std::list<Image &> imageList; //stacks ? \w FontID ImageID ?
	std::list<IGui *> guiList;
	Window screen;

public:
	SDLGame(); //SDL_init TTF_init
	~SDLGame();
	virtual void start() = 0;

	void addGUi();
	IGui *popGui();
	std::list<IGui *> &getGuiList();

	void addImage();
	Image &popImage();
	std::list<Image &> &getImageList();

	void addFont();
	Image &popFont();
	std::list<Font &> &getFontList();

	Window &getWindow();
};