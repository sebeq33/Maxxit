
#include <SDL2\SDL.h>
#include <SDL2\SDL_ttf.h>
#include <iostream>
#include "SDLGame.hh"

//SDL2 API : http://wiki.libsdl.org/APIByCategory

int main(int argc, char *argv[])
{
	SDLGame game(new Window(800, 600, "FIRST", "ressources/maxit_icon.png"));
	
	try
	{
		game.start();
	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR : " << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}