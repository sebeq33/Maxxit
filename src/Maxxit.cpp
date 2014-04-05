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
	Rectangle bg(screen.getSizeX(), screen.getSizeY());

	Display displayBG(static_cast<ISurface *>(&bg));
	Display displayRect(static_cast<ISurface *>(&rect), 100, 100);
	rect.setColor(255, 0, 0);
	
	Image img("ressources/ingame.png");
	Display displayImage(static_cast<ISurface *>(&img), 
		screen.getSizeX() - img.getSizeX(), 0);
	
	/*this->screen.blitDisplay(&displayBG);
	this->screen.blitDisplay(&displayRect);
	this->screen.blitDisplay(&displayImage);
	this->screen.updateWindow();*/

	this->screen.addDisplay(&displayBG);
	this->screen.addDisplay(&displayRect);
	this->screen.addDisplay(&displayImage);
	this->screen.updateDisplays();

	SDL_Delay(10000);
}
