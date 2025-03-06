#include "Screen.h"
#include "Shape.h"
#include "gjkAlgorithm.h"
#include "satAlgorithm.h"
#include <vector>
#include <raylib.h>
#include <typeinfo>
#include "Circle.h"
#include "Polygon.h"

Screen::Screen(Vec2<int> screenSize) : screenSize(screenSize)
{

	InitWindow(screenSize.getX(), screenSize.getY(), "QN-BSSD6000: raylib collisions");

	SetTargetFPS(60);
}


Screen& Screen::getInstance(const Vec2<int>& size)
{
	static Screen instance(size);  // Created once on first call

	return instance;
}


bool Screen::screenClosed() const
{
	return WindowShouldClose();
}

bool Screen::testCollision(std::pair<Shape*, ShapeType> a, std::pair<Shape*, ShapeType> b)
{
	bool collision = false;

	if (a.second == ShapeType::CIRCLE && b.second == ShapeType::CIRCLE)
	{
		//circle
		CustomObjects::Circle* circleA = dynamic_cast<CustomObjects::Circle*>(a.first);
		CustomObjects::Circle* circleB = dynamic_cast<CustomObjects::Circle*>(b.first);

		collision = satAlgorithm::CheckCircleCollision(*circleA, *circleB);
	}
	else if (a.second == ShapeType::CIRCLE || b.second == ShapeType::CIRCLE)
	{
		//mixed
		if (a.second == ShapeType::CIRCLE)
		{
			CustomObjects::Circle* circleA = dynamic_cast<CustomObjects::Circle*>(a.first);
			Polygon* polyB = dynamic_cast<Polygon*>(b.first);

			collision = satAlgorithm::CheckPolygonToCircleCollision(polyB->getVertices(), *circleA);

		}
		else
		{

			Polygon* polyA = dynamic_cast<Polygon*>(a.first);
			CustomObjects::Circle* circleB = dynamic_cast<CustomObjects::Circle*>(b.first);

			collision = satAlgorithm::CheckPolygonToCircleCollision(polyA->getVertices(), *circleB);

		}
	}
	else
	{
		//regular
		//if (gjkAlgorithm::CheckCollision(shapesOnScreen[i].second, shapesOnScreen[j].second))

		Polygon* polyA = dynamic_cast<Polygon*>(a.first);
		Polygon* polyB = dynamic_cast<Polygon*>(b.first);

		collision = satAlgorithm::CheckCollision(polyA->getVertices(), polyB->getVertices());
	}

	return collision;
}

void Screen::update(std::vector<Shape*>& shapes, ShapeFactory* factory)
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	clearShapeVector();

	for (auto& shape : shapes)
	{
		shape->update();

		shape->draw(this);

		//check if any vertex is at the wall
		if (shape->getCenter().getX() < 0 || shape->getCenter().getX() > screenSize.getX())
		{
			//negate the x speed
			shape->setSpeed({ -shape->getSpeed().getX(), shape->getSpeed().getY() });
		}

		if (shape->getCenter().getY() < 0 || shape->getCenter().getY() > screenSize.getY())
		{
			//negate the Y speed
			shape->setSpeed({ shape->getSpeed().getX(), -shape->getSpeed().getY() });
		}
	}

	//Check each shape on the screen
	for (size_t i = 0; i < shapesOnScreen.size(); i++)
	{

		for (size_t j = i + 1; j < shapesOnScreen.size(); j++)
		{

			if (testCollision(shapesOnScreen[i], shapesOnScreen[j]))
			{
				//Save collision location just as the first point
				collisionLocations.push_back(shapesOnScreen[i].first->getCenter());

				//negate the speed
				shapesOnScreen[i].first->setSpeed(shapesOnScreen[i].first->getSpeed() * -1);
				shapesOnScreen[j].first->setSpeed(shapesOnScreen[j].first->getSpeed() * -1);

				if (shapes.size() < 8)
				{
					shapes.push_back(factory->createShape(factory->getRandomShapeType(), screenSize));
				}

			}
		}

	}

	for (auto& location : collisionLocations)
	{
		Vector2 pt{ static_cast<float>(location.getX()), static_cast<float>(location.getY()) };

		DrawCircleV(pt, 15, getRandomRGB());
	}

	DrawFPS(10, 10);

	EndDrawing();

}


Vec2<int> Screen::getScreenSize()
{
	return screenSize;
}

void Screen::addToShapeVector(Shape* shape, ShapeType type)
{
	// Declare and initialize the pair:
	std::pair<Shape*, ShapeType> pair = {
		shape,
		type
	};

	shapesOnScreen.push_back(pair);
}

void Screen::clearShapeVector()
{
	shapesOnScreen.clear();
}

