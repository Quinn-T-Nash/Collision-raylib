#ifndef GJKALGORITHM_H
#define GJKALGORITHM_H

#include <vector>
#include "raylib.h"
#include <math.h>
#include "Functions.h"
#include "Vec2.h"


class gjkAlgorithm
{
public:
	static bool CheckCollision(std::vector<Vec2<int>> vecA, std::vector<Vec2<int>> vecB);

	static Vector2 SupportFunction(std::vector<Vector2> verticesA, std::vector<Vector2> verticesB, Vector2 direction);

	static bool HandleSimplex(std::vector<Vector2> simplex, Vector2 direction);

	static bool LineCase(std::vector<Vector2> simplex, Vector2 direction);

	static bool TriangleCase(std::vector<Vector2> simplex, Vector2 direction);
};

#endif

