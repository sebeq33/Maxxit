#pragma once

#include <SDL2\SDL.h>
#include <string>
#include "Display.hh"

class Font;

class Label : public ISurface
{
private:
	Font &font;
	bool modified;
	std::string str;
	SDL_Surface *lastText;

public:
	Label(Font &font, const std::string &str = "");
	Label(const Label &);
	Label &operator=(const Label &);
	~Label();

	Font &getFont();
	void setFont(Font &);

	const std::string &getStr() const;
	void setStr(const std::string &str);

	bool loaded() const;
	void unload();
	SDL_Surface *getSurface(); //if str != lastStr recreate lastText
};