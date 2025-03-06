#include "Rectangle.h"
#include "ShapeFactory.h"
#include "Screen.h"

namespace CustomObjects {


	void Rectangle::draw(Screen* screen)
	{
		getCenter();

		int width = getDimensions().getX();
		int height = getDimensions().getY();

		calcVertices(width, height);

		Vec2<int> topLeft = getCenter() - (getDimensions() / 2);

		//Draws top left - tr - br - bl
		DrawRectangleLines(topLeft.getX(), topLeft.getY(), height, width, BLACK);

		//So the screen can check itself for collisions
		screen->addToShapeVector(this, ShapeType::RECTANGLE);
	}

	//Add vertices to our vector starting in the top left corner and going clockwise
	//NOTE zero zero is top left of screen and draw accordingly
	Vec2<int> Rectangle::calcVertices(int width, int height)
	{
		clearVertices();

		Vec2<int> topLeft = getCenter() - (getDimensions() / 2);

		Vec2<int> vWidth = Vec2<int>(width, 0);
		Vec2<int> vHeight = Vec2<int>(0, height);

		Vec2<int> topRight = topLeft + vWidth;
		Vec2<int> botRight = topRight - vHeight;
		Vec2<int> botLeft = botRight - vWidth;

		addVertex(topLeft);
		addVertex(topRight);
		addVertex(botRight);
		addVertex(botLeft);

		return topLeft;
	}

}