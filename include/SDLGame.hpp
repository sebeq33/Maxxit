#pragma once

#include "Font.hh"
#include "Image.hh"
#include "IGui.hh"
#include "Window.hh"

template <class T>
class SDLGame
{
private:
	static bool loaded;
	SDLGame(const SDLGame &);
	SDLGame& operator=(const SDLGame &);

	std::list<Font &> fontList;
	std::list<Image &> imageList; //stacks ? \w FontID ImageID ?
	std::list<IGui *> guiList;
	Window screen;

public:
	SDLGame();
	~SDLGame();
	void start(); //SDL_init TTF_init, create a T

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