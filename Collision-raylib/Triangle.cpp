#include "Triangle.h"
#include "ShapeFactory.h"
#include "Screen.h"

void CustomObjects::Triangle::draw(Screen* screen)
{
	getCenter();

	int width = getDimensions().getX();
	int height = getDimensions().getY();

	calcVertices(width, height);


	Vector2 a { static_cast<float>(getVertices().at(0).getX()), static_cast<float>(getVertices().at(0).getY()) };
	Vector2 b { static_cast<float>(getVertices().at(1).getX()), static_cast<float>(getVertices().at(1).getY()) };
	Vector2 c { static_cast<float>(getVertices().at(2).getX()), static_cast<float>(getVertices().at(2).getY()) };

	DrawTriangleLines(a,b,c, BLACK);

	//So the screen can check itself for collisions
	screen->addToShapeVector(this, ShapeType::TRIANGLE);
}

Vec2<int> CustomObjects::Triangle::calcVertices(int width, int height)
{
	clearVertices();

	Vec2<int> top(getCenter().getX(), getCenter().getY() - (2 * height / 3));
	Vec2<int> bottomRight(getCenter().getX() + (width / 2), getCenter().getY() + (height / 3));
	Vec2<int> bottomLeft(getCenter().getX() - (width / 2), getCenter().getY() + (height / 3));

	addVertex(top);
	addVertex(bottomRight);
	addVertex(bottomLeft);

	//Return nothing
	return top;
}



