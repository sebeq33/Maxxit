#pragma once

#include <string>
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "ISurface.hh"

class Image : public ISurface
{
private:
	Image(const Image &);
	Image& operator=(const Image &);

	SDL_Surface *src;

public:
	Image(const std::string &path = "");
	~Image();

	bool load(const std::string &path);
	void unload();
	bool loaded() const;

	int getSizeX() const;
	int getSizeY() const;

	SDL_Surface *getSurface();
};