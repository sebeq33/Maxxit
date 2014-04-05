#include "Maxxit.hh"	

Maxxit::Maxxit()
	: SDLGame(800, 600, "Maxxit", "ressources/maxit_icon.png")
{

}

Maxxit::~Maxxit()
{

}

void Maxxit::startGame()
{
	Rectangle rect(100, 100);
	rect.setColor(255, 0, 0);
	Display displayRect(static_cast<ISurface *>(&rect), 100, 100);
	this->screen.blitDisplay(&displayRect);
	this->screen.updateWindow();
	SDL_Delay(10000);
}
