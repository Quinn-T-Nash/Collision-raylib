#ifndef SHAPE_H
#define SHAPE_H

#include "Vec2.h"
#include <vector>

class Screen;

//Purely Virtual BaseShape Class (Basically serves as our shape inerface
class Shape
{
public:

	virtual ~Shape() = default;

	Shape() = delete;

	Shape(Vec2<int> center, Vec2<int> speed);

	virtual void draw(Screen* screen) = 0;

	virtual void update();

	Vec2<int> getCenter() const;

	void setCenter(Vec2<int> center);

	Vec2<int> getSpeed();
	void setSpeed(Vec2<int> speed);

private:

	Vec2<int> center;
	Vec2<int> speed;

};

#endif


