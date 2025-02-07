#ifndef GJKALGORITHM_H
#define GJKALGORITHM_H

#include <vector>
#include "raylib.h"
#include <math.h>
#include "Functions.h"

static class gjkAlgorithm
{
	bool CheckCollision(std::vector<Vector2> verticesA, std::vector<Vector2> verticesB);

	Vector2 SupportFunction(std::vector<Vector2> verticesA, std::vector<Vector2> verticesB, Vector2 direction);

	bool HandleSimplex(std::vector<Vector2> simplex, Vector2 direction);

	bool LineCase(std::vector<Vector2> simplex, Vector2 direction);

	bool TriangleCase(std::vector<Vector2> simplex, Vector2 direction);
};

#endif

