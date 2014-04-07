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
	Image img("ressources/ingame.png");
	img.preload(); //preload to get image size

	Display displayBG(static_cast<ISurface *>(&bg));
	Display displayRect(static_cast<ISurface *>(&rect), 100, 100);
	rect.setColor(255, 0, 0);
	Display displayImage(static_cast<ISurface *>(&img), 
		screen.getSizeX() - img.getSizeX(), 0);

	this->screen.addDisplay(&displayBG);
	this->screen.addDisplay(&displayRect);
	this->screen.addDisplay(&displayImage);
	this->screen.updateDisplays();

	SDL_Event e;
	bool cont = true;
	while (cont)
		{
			SDL_WaitEvent(&e);
			if(e.type == SDL_QUIT)
				cont = false;
		}
}
