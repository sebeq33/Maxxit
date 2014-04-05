#include "Window.hh"

Window::Window(int sizeX, int sizeY, const std::string &windowTitle, const std::string &iconPath)
	: window(NULL), icon(NULL), sizeX(sizeX), sizeY(sizeY), windowTitle(windowTitle), iconPath(iconPath)
{
}

Window::~Window()
{
	//screen free by destroy window
	if (this->window != NULL)
		SDL_DestroyWindow(this->window);
	if (this->icon != NULL)
		SDL_FreeSurface(this->icon);
}

void Window::start()
{
	this->window = SDL_CreateWindow(this->windowTitle.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		this->sizeX, this->sizeY, 
		SDL_WINDOW_SHOWN);
	if (this->window == NULL)
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	if ((this->screen = SDL_GetWindowSurface(window)) == NULL)
		throw std::runtime_error(std::string("SDL_GetWindowSurface Error: ") + SDL_GetError());
	if (this->iconPath != "")
	{
		this->icon = IMG_Load(this->iconPath.c_str());
		if (this->icon != NULL)
			SDL_SetWindowIcon(this->window, this->icon);
	}
}

void Window::resize(int sizeX, int sizeY)
{
	//TODO
}

void Window::setTitle(const std::string &title)
{
	this->windowTitle = title;
}

const std::string &Window::getWindowTitle() const
{
	return (this->windowTitle);
}

bool isFullScreen()
{
	return (false); //TODO
}

void toggleFullScreen()
{
	//TODO
}

void Window::updateDisplays()
{
	this->guiList.back()->display(*this);
	for(std::list<Display *>::iterator it = displayList.begin(); it != displayList.end(); ++it)
	{
		this->blitDisplay((*it));
	}
	this->updateWindow();
}

void Window::addDisplay(Display *display)
{
	this->displayList.push_back(display);
}

void Window::removeDisplay(const Display *)
{
	//TODO
}

#include <iostream>

void Window::blitDisplay(Display *display)
{
	ISurface *surface = display->getSurface();
	if (surface == NULL)
		return ;
	SDL_Surface *src = surface->getSurface();
	if (src == NULL)
		return ;
	SDL_Rect rect;
	rect.x = display->getPosX();
	rect.y = display->getPosY();
	rect.w = src->w;
	rect.h = src->h;
 	SDL_BlitSurface(src, NULL, screen, &rect);
}

void Window::updateWindow()
{
	std::cout << "UPDATE" << std::endl;
	SDL_UpdateWindowSurface(window);
}

void Window::addGui(IGui *gui)
{
	this->guiList.push_back(gui);
}

void Window::removeGui(IGui *gui)
{
	//TODO
}

IGui *Window::popGui()
{
	IGui *last = this->guiList.back();
	this->guiList.pop_back();
	return (last);
}

std::list<IGui *> &Window::getGuiList()
{
	return (this->guiList);
}

SDL_Window *Window::getWindow()
{
	return (this->window);
}

int Window::getSizeX() const
{
	return (this->sizeX);
}

int Window::getSizeY() const
{
	return (this->sizeY);
}
