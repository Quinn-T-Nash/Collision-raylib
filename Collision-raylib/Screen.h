#ifndef SCREEN_H
#define SCREEN_H

#include "raylib.h"
#include "Shape.h"

#include "Polygon.h"
#include "Rectangle.h"

class Screen
{
public:
	Screen() = default;

	Screen(Vec2<int> screenSize);

	bool screenClosed() const;
	int getScreenSize();

	void update();

	Shape* pShapes[2] = { nullptr, nullptr };

private:

	Vec2<int> screenSize;

};

#endif

