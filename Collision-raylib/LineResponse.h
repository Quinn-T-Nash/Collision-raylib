#ifndef LINERESPONSE_H
#define LINERESPONSE_H

#include "raylib.h"
#include <vector>
#include "Shape.h"

class LineResponse
{
public:

	LineResponse();

	void Draw();

	std::vector<Vector2> lineStarts;
	std::vector<Vector2> lineEnds;

	Shape shape;

private:

};

#endif