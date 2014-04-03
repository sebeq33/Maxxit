#include "SDLGame.hh"

SDLGame::SDLGame(Window *window)
{
	this->screen = window;
}

SDLGame::~SDLGame()
{
	if (this->screen != NULL)
		delete (screen);
}

void SDLGame::start()//IGame *game, Window *)
{
	if (screen == NULL)
		throw std::logic_error("Screen missing");
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	if (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG != IMG_INIT_PNG)
		throw std::runtime_error(std::string("IMG_Init Error (.png): ") + IMG_GetError());
	if (TTF_Init() != 0)
		throw std::runtime_error(std::string("TTF_Init Error: ") + TTF_GetError());
			
	this->screen->start();
	//game->start(this);
	SDL_Delay(5000);

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void SDLGame::addGui(IGui *gui)
{
	this->guiList.push_back(gui);
}

IGui *SDLGame::popGui()
{
	IGui *last = this->guiList.back();
	this->guiList.pop_back();
	return (last);
}

std::list<IGui *> &SDLGame::getGuiList()
{
	return (this->guiList);
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

void SDLGame::setWindow(Window *screen)
{
	if (this->screen != NULL)
		delete (screen);
	this->screen = screen;
}

Window *SDLGame::getWindow()
{
	return (this->screen);
}