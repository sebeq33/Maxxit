#include "Display.hh"

Display::Display(ISurface *surface, int posX, int posY)
	: surface(surface), posX(posX), posY(posY)
{

}

Display::~Display()
{

}

int Display::getPosX() const
{
	return (this->posX);
}

int Display::getPosY() const
{
	return (this->posY);
}

ISurface *Display::getSurface()
{
	return (this->surface);
}

void Display::setSurface(ISurface *surface)
{
	this->surface = surface;
}