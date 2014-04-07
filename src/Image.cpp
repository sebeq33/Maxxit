
#include "Image.hh"

Image::Image(const std::string &path)
	: src(NULL), path(path)
{
}

Image::~Image()
{
	this->unload();
}

bool Image::load(const std::string &path)
{
	if (path != "")
	{
		if (path == this->path && this->src != NULL)
			return (true);
		this->unload();
		this->src = IMG_Load(path.c_str());
		return (this->src != NULL);
	}
	return (false);
}

bool Image::preload()
{
	if (this->src == NULL)
		this->load(this->path);
	return (this->src != NULL);
}

void Image::unload()
{
	if (this->src != NULL)
	{
		SDL_FreeSurface(this->src);
		this->src = NULL;
	}
}

bool Image::loaded() const
{
	return (this->src != NULL);
}

int Image::getSizeX() const
{
	if (!this->src)
		throw std::logic_error("Image::getSize : Need to load image");
	return (src->w);
}

int Image::getSizeY() const
{
	if (!this->src)
		throw std::logic_error("Image::getSize : Need to load image");
	return (src->h);
}

SDL_Surface *Image::getSurface()
{
	this->preload();
	return (this->src);
}