
#include "Rectangle.h"

namespace CustomObjects {


	void Rectangle::draw()
	{
		getCenter();

		calcVertices();

		for (Vec2<int> vertex : getVertices())
		{
			if (isOutOfBounds(vertex))
			{
				wallBounce(vertex);
				break;
			}
		}

		DrawRectangleLines(getVertices()[0].getX(), getVertices()[0].getY(),
			getDimensions().getX(), getDimensions().getY(), BLACK);

		Vector2 test = { 0, 0};

		DrawCircleV(test, 10, BLACK);
	}


	void Rectangle::calcVertices()
	{
		//Find the 4 vertices of our recangle using Vec2 center and Vec2 dimensions
		//Add vetices to our vertex vector starting in the top left corner and going clockwise

		clearVertices();

		Vec2<int> distance = getDimensions() / 2;

		addVertex({ getCenter().getX() - distance.getX(), getCenter().getY() - distance.getY() });
		addVertex(getCenter() + distance);
		addVertex({ getCenter().getX() + distance.getX(), getCenter().getY() + distance.getY() });
		addVertex(getCenter() - distance);

	}

}