#ifndef SATALGORITHM_H
#define SATALGORITHM_H

#include <vector>
#include "raylib.h"
#include <math.h>
#include "Functions.h"
#include "Vec2.h"
#include "Shape.h"
#include "Circle.h"

class satAlgorithm
{
public:

	static bool CheckCollision(std::vector<Vec2<int>> vecA, std::vector<Vec2<int>> vecB);

	static bool CheckCircleCollision(const CustomObjects::Circle& circleA, const CustomObjects::Circle& circleB);

	static bool CheckPolygonToCircleCollision(const std::vector<Vec2<int>>& vertices, const CustomObjects::Circle& circle);

private:
	
	static float FindMinimumDistanceFromPointToLine(const Vec2<int>& point, const Vec2<int>& lineStart, const Vec2<int>& lineEnd);
	static bool IsPointInPolygon(const std::vector<Vec2<int>>& vertices, const Vec2<int>& point);
};

#endif

