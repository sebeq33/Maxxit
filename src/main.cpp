
#include <SDL2\SDL.h>
#include <SDL2\SDL_ttf.h>
#include <iostream>
#include "SDLGame.hh"
#include "Maxxit.hh"

//SDL2 API : http://wiki.libsdl.org/APIByCategory

int main(int argc, char *argv[])
{
	Maxxit maxxit;

	try
	{
		maxxit.start();
	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR : " << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}