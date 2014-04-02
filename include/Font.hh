#pragma once

#include <SDL2\SDL_ttf.h>
#include "Label.hh"

//http://fr.openclassrooms.com/informatique/cours/apprenez-a-programmer-en-c/les-differentes-methodes-d-ecriture

class Font
{
public:
	enum Quality
	{
		Solid, //transparency + Low Quality
		Shaded, //no transparency + Good Quality
		Blended //both but slower
	};

private:
	Font(const Font &);
	Font &operator=(const Font &);

	TTF_Font *font;
	Quality currentQuality;
	SDL_Color bg; //only for Shaded quality
	SDL_Color fg;

public:
	Font();
	Font(const std::string &path, int size, Quality q = Solid);
	~Font();
	
	bool load(const std::string &path, int size, Quality q = Solid);
	bool isLoaded() const;
	void unload();

	Quality getQuality() const;
	void setQuality(Quality q);

	void setBackgroungColor(const SDL_Color &color); //TEST TO DO (REF ?)
	void setForegroungColor(const SDL_Color &color);
	
	const TTF_Font *getFont() const;
	Label &createLabel(const std::string &str) const;
};