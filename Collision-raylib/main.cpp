/*
Quinn Nash
qnash@live.nmhu.edu
Collision-raylib

Goal: Generative art using SAT and GJK collision algorithms with the raylib open source graphics API
*/

#include "Screen.h"
#include "ShapeFactory.h"
#include <vector>

int main(void)
{
	Vec2<int> screenSize = { 800, 800 };

	Screen& screenSingleton = Screen::getInstance(screenSize);

	ShapeFactory* factory = new ShapeFactory();

	std::vector<Shape*> shapes;

	shapes.push_back(factory->createShape(factory->getRandomShapeType(), screenSize));
	shapes.push_back(factory->createShape(factory->getRandomShapeType(), screenSize));


	while (!screenSingleton.screenClosed())
	{
		screenSingleton.update(shapes, factory);
		
	}

	return 0;
}


