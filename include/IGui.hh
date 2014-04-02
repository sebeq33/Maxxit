#pragma once

class Window;

class IGui
{
private:
	IGui(const IGui &);
	IGui &operator=(const IGui &);

public:
	virtual ~IGui();
	virtual void display(Window &) = 0;
	virtual void update() = 0;
};