#include "gjkAlgorithm.h"

bool gjkAlgorithm::CheckCollision(std::vector<Vec2<int>> vecA, std::vector<Vec2<int>> vecB)
{

	// Convert vector A
	std::vector<Vector2> verticesA;
	verticesA.reserve(vecA.size());  // Reserve space for efficiency
	for (const auto& vertex : vecA) {
		verticesA.push_back(convertToVector2(vertex));
	}

	// Convert vector B
	std::vector<Vector2> verticesB;
	verticesB.reserve(vecB.size());  // Reserve space for efficiency
	for (const auto& vertex : vecB) {
		verticesB.push_back(convertToVector2(vertex));
	}


	// using random direction
		//TODO switch to vector between center of the two shapes
	Vector2 direction = { 1 , 0 };

	//build our simplex
	std::vector<Vector2> simplex;

	Vector2 firstPoint = SupportFunction(verticesA, verticesB, direction);

	simplex.push_back(firstPoint);

	//new direction towards orgin
	direction = { 0 - firstPoint.x, 0 - firstPoint.y };

	Vector2 ptA = { 0,0 };
	//loop until we find a simplex that contains the orgin
	while (true)
	{
		// Normalize direction
		float length = sqrt(direction.x * direction.x + direction.y * direction.y);
		if (length > 0) {
			direction.x /= length;
			direction.y /= length;
		}

		ptA = SupportFunction(verticesA, verticesB, direction);

		float dotResult = DotProduct(ptA, direction);
		//check new point passes the orgin with dot product
		if (dotResult < 0)
		{
			//did not pass the orgin
			return false;
		}

		simplex.insert(simplex.begin(), ptA);

		if (HandleSimplex(simplex, direction))
		{
			return true;
		}
	}

	return false;
}


//finds the support point in a given direction of the minkowski difference of the two shapes
Vector2 gjkAlgorithm::SupportFunction(std::vector<Vector2> verticesA, std::vector<Vector2> verticesB, Vector2 direction)
{
	//Get furthest point on shapeA
	Vector2 farthestA = verticesA[0];
	float maxDot = DotProduct(direction, verticesA[0]);

	for (size_t i = 1; i < verticesA.size(); i++) {
		float dot = DotProduct(direction, verticesA[i]);
		if (dot > maxDot) {
			maxDot = dot;
			farthestA = verticesA[i];
		}
	}

	//get furthest on shapeB

	//first negate the direction
	direction = { -direction.x, -direction.y };

	Vector2 farthestB = verticesB[0];
	maxDot = DotProduct(direction, verticesB[0]);

	for (size_t i = 1; i < verticesB.size(); i++) {
		float dot = DotProduct(direction, verticesB[i]);
		if (dot > maxDot) {
			maxDot = dot;
			farthestB = verticesB[i];
		}

	}

	Vector2 farthestMinkoswki = { farthestA.x - farthestB.x, farthestA.y - farthestB.y };

	return farthestMinkoswki;

}

bool gjkAlgorithm::HandleSimplex(std::vector<Vector2> simplex, Vector2 direction)
{
	//check the line case
	if (simplex.size() == 2)
	{
		return (LineCase(simplex, direction));
	}
	else
	{
		//check the triangle case
		return (TriangleCase(simplex, direction));
	}

}


bool gjkAlgorithm::LineCase(std::vector<Vector2> simplex, Vector2 direction)
{
	//define vectors AB and A0

	Vector2 ab = { simplex[1].x - simplex[0].x, simplex[1].y - simplex[0].y };
	Vector2 ao = { 0 - simplex[0].x, 0 - simplex[0].y };

	//use triple product to get the next direction
	// https://www.geeksforgeeks.org/vector-triple-product/
	//AB X (AO X AB) which can be (AB dot AB ) * AO - (AB dot AO) * AB
	Vector2 abPerp = TripleProdcut(ab, ao, ab);

	direction = abPerp;

	return false;
}

bool gjkAlgorithm::TriangleCase(std::vector<Vector2> simplex, Vector2 direction)
{
	Vector2  A = simplex[0];
	Vector2  B = simplex[1];
	Vector2  C = simplex[2];

	Vector2 AB = { B.x - A.x,B.y - A.y };
	Vector2 AC = { C.x - A.x,C.y - A.x };
	Vector2 AO = { 0 - A.x, 0 - A.y };

	Vector2 abPerp = TripleProdcut(AC, AB, AB);

	Vector2 acPerp = TripleProdcut(AB, AC, AC);

	//use voroi regins to check if we have contain the orgin
	if (DotProduct(abPerp, AO) > 0)
	{
		//Orgin is in regin AO 
		simplex.erase(simplex.begin() + 2);

		//so we delete point C and set the new direction
		direction = abPerp;

		return false;
	}
	else if (DotProduct(acPerp, AO) > 0)
	{
		//same logic checking if orgin was in AC regin
		simplex.erase(simplex.begin() + 1);

		direction = acPerp;

		return false;
	}

	return true;
}