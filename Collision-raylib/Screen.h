#ifndef SCREEN_H
#define SCREEN_H

#include "raylib.h"
#include "Shape.h"

class Screen
{
public:
	Screen() = default;

	Screen(int screenWidth, int screenHeight);

	void startScreenLoop();

	void Draw();

	int getScreenWidth();
	int getScreenHeight();

private:

	int screenWidth;
	int screnHeight;

};

#endif

