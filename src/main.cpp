
#include <SDL2\SDL.h>
#include <SDL2\SDL_ttf.h>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Hello World !" << std::endl;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return (EXIT_FAILURE);
	}
	if (TTF_Init() == -1)
	{
		std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
		return (EXIT_FAILURE);
	}

	SDL_Delay(5000);
	SDL_Quit();
	return (EXIT_SUCCESS);
}