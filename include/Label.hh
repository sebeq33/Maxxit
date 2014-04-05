#pragma once

#include <SDL2\SDL.h>
#include <string>
#include "Display.hh"

class Font;

class Label : public ISurface, public std::string
{
private:
	Font &font;
	std::string lastStr;
	SDL_Surface *lastText;
	int posX, posY;

public:
	Label(Font &font, int posX = 0, int posY = 0);
	Label(const Label &);
	Label &operator=(const Label &);
	~Label();

	Font &getFont();
	void setFont(Font &);

	const SDL_Surface *getSurface() const; //if str != lastStr recreate lastText
};