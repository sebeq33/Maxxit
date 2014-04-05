#pragma once

#include <string>
#include <SDL2\SDL.h>
#include "ISurface.hh"

class Image : ISurface
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