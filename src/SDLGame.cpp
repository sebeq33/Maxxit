#include "SDLGame.hh"

SDLGame::SDLGame(int sizeX, int sizeY, const std::string &title, const std::string &iconPath)
	: screen(sizeX, sizeY, title, iconPath)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) //if IMG_INIT_PNG flag is not set on the returned value
		throw std::runtime_error(std::string("IMG_Init Error (.png): ") + IMG_GetError());
	if (TTF_Init() != 0)
		throw std::runtime_error(std::string("TTF_Init Error: ") + TTF_GetError());
}

SDLGame::~SDLGame()
{
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void SDLGame::start()
{
	this->screen.start();
	this->startGame();
}

void SDLGame::addSurface(ISurface *img)
{
	this->loadedSurfaceList.push_back(img);
}

ISurface *SDLGame::popSurface()
{
	ISurface *last = this->loadedSurfaceList.back();
	this->loadedSurfaceList.pop_back();
	return (last);
}

std::list<ISurface *> &SDLGame::getSurfaceList()
{
	return (this->loadedSurfaceList);
}

void SDLGame::addFont(Font *font)
{
	this->loadedFontList.push_back(font);
}

Font *SDLGame::popFont()
{
	Font *last = this->loadedFontList.back();
	this->loadedFontList.pop_back();
	return (last);
}

std::list<Font *> &SDLGame::getFontList()
{
	return (this->loadedFontList);
}
