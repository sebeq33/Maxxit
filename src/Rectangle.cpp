#include "Rectangle.hh"

Rectangle::Rectangle(int posX, int posY, int sizeX , int sizeY)
	: rect(NULL), 
	posX(posX), 
	posY(posY), 
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

}


void Rectangle::createSurface()
{
	if (this->rect != NULL)
		SDL_FreeSurface(this->rect);
	this->rect = SDL_CreateRGBSurface(0, sizeX, sizeY, 32, 0, 0, 0, 0); //Creating the surface.
	SDL_FillRect(this->rect, NULL, SDL_MapRGBA(rect->format, red, green, blue, alpha)); //Filling the surface with red colour.
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

int Rectangle::getPosX() const
{
	return (this->posX);
}

int Rectangle::getPosY() const
{
	return (this->posY);
}

SDL_Surface *Rectangle::getSurface()
{
	if (this->modified)
		this->createSurface();
	return (this->rect);
}