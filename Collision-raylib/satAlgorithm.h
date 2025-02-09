#ifndef SATALGORITHM_H
#define SATALGORITHM_H

#include <vector>
#include "raylib.h"
#include <math.h>
#include "Functions.h"
#include "Vec2.h"


class satAlgorithm
{
public:

	static bool CheckCollision(std::vector<Vec2<int>> vecA, std::vector<Vec2<int>> vecB);


};

#endif

