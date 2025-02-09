#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "Vec2.h"
#include <random>

//Purely Virtual BaseShape Class (Basically serves as our shape inerface
class Shape
{
public:

	Shape(Vec2<int> bounds);

	virtual void draw() = 0;

	void update();

	//std::vector<Vector2> satLines;
	//std::vector<Vector2> gjkLines;

	Vec2<int> getCenter();
	void setCenter(Vec2<int> center);

	Vec2<int> getSpeed();
	void setSpeed(Vec2<int> speed);

	bool isOutOfBounds(Vec2<int> vertex);

	void wallBounce(Vec2<int> vertex);

private:

	Vec2<int> center;
	Vec2<int> speed;
	Vec2<int> bounds;

	const Vec2<int> origin{ 0,0 };

};

#endif


