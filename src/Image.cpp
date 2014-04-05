#include "Image.hh"

Image::Image(const std::string &path)
	: src(NULL)
{
	this->load(path);
}

Image::~Image()
{
}

bool Image::load(const std::string &path)
{
	if (path != "")
	{
		if (this->src != NULL)
			this->unload();
		this->src = IMG_Load(path.c_str());
		return (this->src != NULL);
	}
	return (false);
}

void Image::unload()
{
	SDL_FreeSurface(this->src);
	this->src = NULL;
}

bool Image::loaded() const
{
	return (this->src != NULL);
}


int Image::getSizeX() const
{
	return (src ? src->w : 0);
}

int Image::getSizeY() const
{
	return (src ? src->h : 0);
}

SDL_Surface *Image::getSurface()
{
	return (this->src);
}