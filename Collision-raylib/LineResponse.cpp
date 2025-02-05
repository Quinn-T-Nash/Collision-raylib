
#include "LineResponse.h"
#include "raylib.h"

LineResponse::LineResponse()
{
}

void LineResponse::Draw()
{
	int i = 0;

	for (Vector2 vec : lineStarts)
	{

		if (lineEnds.size() != 0)
		{
			DrawLine(vec.x, vec.y, lineEnds[i].x, lineEnds[i].y, BLACK);
		}
		else
		{
			DrawLine(vec.x, vec.y, shape.position.x, shape.position.y, BLACK);
		}
	}
}

