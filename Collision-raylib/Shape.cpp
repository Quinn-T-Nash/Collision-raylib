#include "Shape.h"



Shape::Shape()
{
	position = { 0,0 };
	movementX = 0;
	movementY = 0;
	bCollision = false;
}

Shape::Shape(Vector2 startPosition, int speed)
{
	position = startPosition;
	movementX = speed;
	movementY = speed;
	bCollision = false;
};

void Shape::Draw()
{
	//rectangle

	DrawRectangleLines(position.x, position.y, 40, 40, MAROON);
}

void Shape::Move()
{
	position.x = position.x + movementX;
	position.y += movementY;

	SetVertices();
}

void Shape::SetVertices()
{
	vertices.clear();

	vertices.push_back(position);

	vertices.push_back({ position.x + 40, position.y });

	vertices.push_back({ position.x - 40, position.y - 40 });

	vertices.push_back({ position.x, position.y - 40 });

}


