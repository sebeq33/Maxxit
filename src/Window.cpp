#include "Window.hh"

Window::Window(
	int sizeX, 
	int sizeY, 
	const std::string &windowTitle,
	const std::string &iconPath)//open window, set window title / size / icon ...etc
	: screen(NULL), icon(NULL), sizeX(sizeX), sizeY(sizeY), windowTitle(windowTitle), iconPath(iconPath)
{
}

Window::~Window()
{
	if (this->screen != NULL)
		SDL_DestroyWindow(this->screen);
	if (this->icon != NULL)
		SDL_FreeSurface(this->icon);
}

#include <iostream>

void Window::start()
{
	this->screen = SDL_CreateWindow(this->windowTitle.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		this->sizeX, 
		this->sizeY, 
		SDL_WINDOW_SHOWN);
	if (this->screen == NULL)
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	if (this->iconPath != "")
	{
		this->icon = IMG_Load(this->iconPath.c_str());
		if (this->icon != NULL)
			SDL_SetWindowIcon(this->screen, this->icon);
		else
			std::cout << std::string("IMG_Init Error (.png): ") + IMG_GetError() << std::endl;
	}
}

void Window::updateDisplay()
{

}

void Window::addDisplay(const IDisplay *)
{

}

void Window::removeDisplay(const IDisplay *)
{

}

int Window::getSizeX() const
{
	return (this->sizeX);
}

int Window::getSizeY() const
{
	return (this->sizeY);
}
