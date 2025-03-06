#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "Vec2.h"
#include "ShapeType.h" // Include the enum definition

class Shape; 

class ShapeFactory
{
public:
	
	Shape* createShape(ShapeType shapeType, Vec2<int> screenSize);

	~ShapeFactory() {};

	ShapeType getRandomShapeType();
};

#endif