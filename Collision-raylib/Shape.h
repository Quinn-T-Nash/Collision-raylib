#ifndef SHAPE_H
#define SHAPE_H

#include "raylib.h"
#include <vector>

class Shape
{
public:

	Shape();

	Shape(Vector2 startPosition, int speed);

	virtual void Draw();

	void Move();

	std::vector<Vector2> vertices;

	Vector2 position;
	int movementX;
	int movementY;
	bool bCollision;

	void SetVertices();

private:

};

#endif


