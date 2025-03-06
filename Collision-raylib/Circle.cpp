#include "Circle.h"
#include "ShapeFactory.h"

#include <raylib.h>
#include <random>
#include "ShapeType.h"
#include "Screen.h"

namespace CustomObjects {
	

	Circle::Circle(Vec2<int> center, Vec2<int> speed)
		: Shape(center, speed)
	{
		std::random_device rd; // True random number generator
		std::mt19937 gen(rd()); // Mersenne Twister engine

		//Generate a dimensions speed
		std::uniform_int_distribution<> r(40, 80);

		radius = (r(gen));
	}

	void Circle::draw(Screen* screen)
	{

		DrawCircleLines(getCenter().getX(), getCenter().getY(), static_cast<float>(radius), BLACK);

		//So the screen can check itself for collisions
		screen->addToShapeVector(this, ShapeType::CIRCLE);
	}

}
