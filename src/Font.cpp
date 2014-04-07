#include "Font.hh"

Font::Font()
	: font(NULL), currentQuality(Solid), size(22), modified(true)
{
	this->initDefaultColor();
}

Font::Font(const std::string &path, int size, Quality q)
	: font(NULL), currentQuality(q), path(path), size(size)
{
	this->initDefaultColor();
}

Font::~Font()
{
	this->unload();
}
	
void Font::initDefaultColor()
{
	bg.r = 255; bg.g = 255; bg.b = 255; bg.a = 255;
	fg.r = 0; fg.g = 0; fg.b = 0; fg.a = 255;
}

bool Font::preload()
{
	return (this->load(this->path, this->size, this->currentQuality));
}

bool Font::load(const std::string &path, int size, Quality q)
{
	if (path != "")
	{
		this->size = size;
		this->currentQuality = q;
		//TODO
	}
	return (false);
}

bool Font::isLoaded() const
{
	return (this->font != NULL);
}

void Font::unload()
{
	//TODO
}

Font::Quality Font::getQuality() const
{
	return (this->currentQuality);
}

void Font::setQuality(Quality q)
{
	this->currentQuality = q;
}


void Font::setBackgroungColor(const SDL_Color &color)
{
	this->bg.r = color.r;
	this->bg.g = color.g;
	this->bg.b = color.b;
}

void Font::setForegroungColor(const SDL_Color &color)
{
	this->fg.r = color.r;
	this->fg.g = color.g;
	this->fg.b = color.b;
}
	
const TTF_Font *Font::getFont() const
{
	return (this->font);
}

Label *Font::createLabel(const std::string &str) const
{
	//TODO
	return (NULL);
}
