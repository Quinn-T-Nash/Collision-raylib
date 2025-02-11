#include "Shape.h"
#include "Screen.h"


//Sets the start position of the shape to a random location on the screen
Shape::Shape(Vec2<int> bounds)
{
	this->bounds = bounds;

	std::random_device rd; // True random number generator
	std::mt19937 gen(rd()); // Mersenne Twister engine

	//Generate a random spot on screen
	std::uniform_int_distribution<> disX(25, this->bounds.getX() - 25);
	std::uniform_int_distribution<> disY(25, this->bounds.getY() - 25);

	std::uniform_int_distribution<> disSpeedX(5, 10);
	std::uniform_int_distribution<> disSpeedY(5, 10);

	center = Vec2<int>(disX(gen), disY(gen));
	speed = Vec2<int>(disSpeedX(gen), disSpeedY(gen));
}

void Shape::update()
{
	center = center + speed;
}

Vec2<int> Shape::getCenter()
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


bool Shape::isOutOfBounds(Vec2<int> vertex)
{
	bool outOfBounds{ false };

	if (vertex.getX() < origin.getX() || vertex.getY() < origin.getY()
		|| vertex.getX() > bounds.getX() || vertex.getY() > bounds.getY())
	{
		outOfBounds = true;
	}

	return outOfBounds;

}

void Shape::wallBounce(Vec2<int> vertex)
{
	if (vertex.getX() < origin.getX() || bounds.getX() < vertex.getX())
	{
		setSpeed({ - speed.getX(), speed.getY() });
	}

	if (vertex.getY() < origin.getY() || bounds.getY() < vertex.getY())
	{
		setSpeed({ speed.getX(), - speed.getY() });
	}
}



