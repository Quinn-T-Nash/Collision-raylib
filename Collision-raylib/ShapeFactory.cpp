#include "ShapeFactory.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <random>
#include "ShapeType.h"

Shape* ShapeFactory::createShape(ShapeType shapeType, Vec2<int> screenSize)
{
	Shape* shape;

	std::random_device rd; // True random number generator
	std::mt19937 gen(rd()); // Mersenne Twister engine

	//Generate a random spot on screen
	std::uniform_int_distribution<> disX(25, screenSize.getX() - 25);
	std::uniform_int_distribution<> disY(25, screenSize.getY() - 25);

	//Generate a random speed
	std::uniform_int_distribution<> disSpeedX(-10, 10);
	std::uniform_int_distribution<> disSpeedY(-10, 10);

	Vec2<int> center{ Vec2<int>(disX(gen), disY(gen)) };
	Vec2<int> speed{ Vec2<int>(disSpeedX(gen), disSpeedY(gen)) };

	switch (shapeType)
	{

	case ShapeType::RECTANGLE:
		shape = new CustomObjects::Rectangle(center, speed);
		break;

	case ShapeType::TRIANGLE:
		shape = new CustomObjects::Triangle(center, speed);
		break;

	case ShapeType::CIRCLE:
		//shape = new CustomObjects::Circle(center, speed);
		shape = new CustomObjects::Circle(center, speed);
		break;

	default:
		shape = nullptr;
	}


	return shape;
}

ShapeType ShapeFactory::getRandomShapeType()
{
	int shapeCount = static_cast<int>(ShapeType::COUNT) - 1;
	
	std::random_device rd; // True random number generator
	std::mt19937 gen(rd()); // Mersenne Twister engine

	//Generate a random spot on screen
	std::uniform_int_distribution<> possibleShapes(0, shapeCount);

	ShapeType randomType = static_cast<ShapeType>(possibleShapes(gen));

	return randomType;
}
