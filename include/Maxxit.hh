#pragma once

#include "SDLGame.hh"

class Maxxit : public SDLGame
{
private:
	Maxxit(const Maxxit &);
	Maxxit& operator=(const Maxxit &);

public:
	Maxxit();
	~Maxxit();
	void startGame();
};