#include "RectangleShape.h"

RectangleShape::RectangleShape() : Shape()
{
	width = 0;
	height = 0;
}

RectangleShape::RectangleShape(Vector2 startPosition, int width, int height) : Shape(startPosition)
{

	this->width = width;
	this->height = height;

}

void RectangleShape::Draw()
{

	DrawRectangleLines((int)startPosition.x, (int)startPosition.y, width, height, BLACK);

}
