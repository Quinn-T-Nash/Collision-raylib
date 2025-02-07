#include "Shape.h"
#include "Screen.h"


//Sets the start position of the shape to a random location on the screen
Shape::Shape(Screen& screen)
{
	std::random_device rd; // True random number generator
	std::mt19937 gen(rd()); // Mersenne Twister engine

	//Generate a random spot on screen
	std::uniform_int_distribution<> disX(1, screen.getScreenWidth());
	std::uniform_int_distribution<> disY(1, screen.getScreenHeight());

	std::uniform_int_distribution<> disSpeedX(1, 10);
	std::uniform_int_distribution<> disSpeedY(1, 10);


	center = Vec2<int>(disX(gen), disY(gen));
	speed = Vec2<int>(disSpeedX(gen), disSpeedY(gen));

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


