#ifdef _DEBUG //check leaks
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#endif

#include <SDL2\SDL.h>
#include <SDL2\SDL_ttf.h>
#include <iostream>
#include "SDLGame.hh"
#include "Maxxit.hh"

//SDL2 API : http://wiki.libsdl.org/APIByCategory

int main(int argc, char *argv[])
{
#ifdef _DEBUG
	//display leaks on output when function finished
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	Maxxit maxxit;

	try
	{
		maxxit.start();
	}
	catch (std::exception &e)
	{
		int result = SDL_ShowSimpleMessageBox(
			SDL_MESSAGEBOX_ERROR, 
			"Error appends",
			e.what(),
            NULL);
		if (result != 0)
			std::cerr << "ERROR : " << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}