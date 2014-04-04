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

void SDLGame::addImage(Image *img)
{
	this->imageList.push_back(img);
}

Image *SDLGame::popImage()
{
	Image *last = this->imageList.back();
	this->imageList.pop_back();
	return (last);
}

std::list<Image *> &SDLGame::getImageList()
{
	return (this->imageList);
}

void SDLGame::addFont(Font *font)
{
	this->fontList.push_back(font);
}

Font *SDLGame::popFont()
{
	Font *last = this->fontList.back();
	this->fontList.pop_back();
	return (last);
}

std::list<Font *> &SDLGame::getFontList()
{
	return (this->fontList);
}
