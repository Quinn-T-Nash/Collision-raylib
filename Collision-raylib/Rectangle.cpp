
#include "Rectangle.h"

namespace CustomObjects {


	Rectangle::Rectangle(Screen& screen, Vec2<int> dimensions)
		: Polygon(screen, dimensions)
	{
		Update();
	}

	void Rectangle::Update()
	{
		getCenter();

		calcVertices();

	}


	void Rectangle::Draw()
	{
		DrawRectangleLines(getCenter().getX(), getCenter().getY(), width, height, BLACK);
	}


	void Rectangle::calcVertices()
	{
		//Find the 4 vertices of our recangle using Vec2 center and Vec2 dimensions
		//Add vetices to our vertex vector starting in the top left corner and going clockwise

		Vec2<int> distance = getDimensions() * .5;
		
		addVertex({ getCenter().getX() - distance.getX(), getCenter().getY() + distance.getY() });
		addVertex(getCenter() + distance);
		addVertex({ getCenter().getX() + distance.getX(), getCenter().getY() - distance.getY() });
		addVertex(getCenter() - distance);

	}

}