#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "Vec2.h"
#include <random>

// Forward declaration
class Screen;  // Add this line


//Purely Virtual BaseShape Class (Basically serves as our shape inerface
class Shape
{
public:

	Shape(Screen& screen);

	virtual void Draw() = 0;
	virtual void Update() = 0;

	//std::vector<Vector2> satLines;
	//std::vector<Vector2> gjkLines;

	Vec2<int> getCenter();
	void setCenter(Vec2<int> center);

	Vec2<int> getSpeed();
	void setSpeed(Vec2<int> speed);

private:

	Vec2<int> center;
	Vec2<int> speed;

};

#endif


