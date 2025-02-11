#ifndef SCREEN_H
#define SCREEN_H

#include "raylib.h"
#include "Shape.h"
#include "Functions.h"
#include "Polygon.h"
#include "Rectangle.h"

class Screen
{
public:
	Screen() = default;

	Screen(Vec2<int> screenSize);

	bool screenClosed() const;
	Vec2<int> getScreenSize();

	void update(std::vector<Vector2> vecCollisionPts);

	Shape* pShapes[2] = { nullptr, nullptr };

private:

	Vec2<int> screenSize;

};

#endif

