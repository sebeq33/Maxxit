#pragma once

#include <string>
#include <SDL2\SDL.h>

class Image
{
private:
	Image(const Image &);
	Image& operator=(const Image &);

	SDL_Surface *src;

public:
	Image(){}
	~Image(){}
	bool load(const std::string &path);
	void unload();
	bool loaded() const;
	const SDL_Surface *getImage();
};