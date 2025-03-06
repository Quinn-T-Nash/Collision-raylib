#include "Shape.h"

//Sets the start position of the shape to a random location on the screen
Shape::Shape(Vec2<int> center, Vec2<int> speed)
{
	this->center = center;
	this->speed = speed;
}

void Shape::update()
{
	center = center + speed;
}

Vec2<int> Shape::getCenter() const
{
	return center;
}

void Shape::setCenter(Vec2<int> center)
{
	this->center = center;
}

Vec2<int> Shape::getSpeed()
{
	return speed;
}

void Shape::setSpeed(Vec2<int> speed)
{
	this->speed = speed;
}
