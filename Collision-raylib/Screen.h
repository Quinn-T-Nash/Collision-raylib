#ifndef SCREEN_H
#define SCREEN_H

#include "Vec2.h"
#include <vector>
#include <utility> // For std::pair
#include "ShapeType.h"
#include "ShapeFactory.h" 

// Forward declare Shape instead of including it
class Shape;


class Screen
{
public:

	// Static method to get Screen instance
	static Screen& getInstance(const Vec2<int>& size = { 0,0 });

	bool screenClosed() const;

	bool testCollision(std::pair<Shape*, ShapeType> a, std::pair<Shape*, ShapeType> b);

	void update(std::vector<Shape*>& shapes, ShapeFactory* factory);

	Vec2<int> getScreenSize();

	void addToShapeVector(Shape* shape, ShapeType vertices);

	void clearShapeVector();

private:

	Screen() : screenSize({ 0,0 }) {};

	Screen(Vec2<int> screenSize);

	// Delete copy constructor and assignment operator
	Screen(const Screen&) = delete;
	Screen& operator=(const Screen&) = delete;

	Vec2<int> screenSize;

	std::vector<std::pair<Shape*, ShapeType>> shapesOnScreen;

	std::vector<Vec2<int>> collisionLocations;


};

#endif

