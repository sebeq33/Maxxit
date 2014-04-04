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
	Rectangle rect(50, 50, 100, 100);
	rect.setColor(255, 0, 0);

	this->screen.blitDisplay(static_cast<IDisplay *>(&rect));
	this->screen.updateWindow();  
	SDL_Delay(5000);
}
