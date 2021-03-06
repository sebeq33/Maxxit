#include "Rectangle.hh"

Rectangle::Rectangle(int sizeX , int sizeY)
	: rect(NULL), 
	sizeX(sizeX), 
	sizeY(sizeY),
	red(255),
	green(255),
	blue(255),
	alpha(255),
	modified(true)
{

}

Rectangle::~Rectangle()
{
	this->unload();
}

void Rectangle::createSurface()
{
	if (!this->modified)
		return ;
	SDL_Surface *src = SDL_CreateRGBSurface(0, sizeX, sizeY, 32, 0, 0, 0, 0); 
	if (src == NULL)
		return ;
	if (this->rect != NULL)
		SDL_FreeSurface(this->rect);
	this->rect = src;
	SDL_FillRect(this->rect, NULL, SDL_MapRGBA(rect->format, red, green, blue, alpha));
	modified = false;
}

void Rectangle::setColorRed(Uint8 red)
{
	this->red = red;
	modified = true;
}

void Rectangle::setColorGreen(Uint8 green)
{
	this->green = green;
	modified = true;
}

void Rectangle::setColorBlue(Uint8 blue)
{
	this->blue = blue;
	modified = true;
}

void Rectangle::setColorAlpha(Uint8 alpha)
{
	this->alpha = alpha;
	modified = true;
}

void Rectangle::setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
	modified = true;
}

SDL_Surface *Rectangle::getSurface()
{
	this->createSurface();
	return (this->rect);
}

bool Rectangle::preload()
{
	this->createSurface();
	return (this->rect != NULL);
}

bool Rectangle::loaded() const
{
	return (this->rect != NULL);
}

void Rectangle::unload()
{
	if (this->rect != NULL)
	{
		SDL_FreeSurface(this->rect);
		this->rect = NULL;
		modified = true;
	}
}