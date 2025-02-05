#include "Functions.h"

bool CollisionSAT(vector<Vector2> verticesA, vector<Vector2> verticesB) {

	// Test axes from shape A
	for (size_t i = 0; i < verticesA.size(); i++) {
		// Get edge vector
		Vector2 edge = {
			verticesA[(i + 1) % verticesA.size()].x - verticesA[i].x,
			verticesA[(i + 1) % verticesA.size()].y - verticesA[i].y
		};

		// Get perpendicular axis
		Vector2 axis = { -edge.y, edge.x };

		// Normalize axis
		float magnitude = sqrt(axis.x * axis.x + axis.y * axis.y);
		if (magnitude > 0) {
			axis.x /= magnitude;
			axis.y /= magnitude;
		}

		// Projection values of both shapes onto the axis
		float minA = INFINITY, maxA = -INFINITY;
		float minB = INFINITY, maxB = -INFINITY;

		// Project shape A
		for (const auto& vertex : verticesA) {
			float projection = DotProduct(axis, vertex);
			minA = min(minA, projection);
			maxA = max(maxA, projection);
		}

		// Project shape B
		for (const auto& vertex : verticesB) {
			float projection = DotProduct(axis, vertex);
			minB = min(minB, projection);
			maxB = max(maxB, projection);
		}

		// Check for gap
		if (maxA < minB || maxB < minA) {
			return false; // Separating axis found
		}
	}

	// Test axes from shape B
	for (size_t i = 0; i < verticesB.size(); i++) {
		Vector2 edge = {
			verticesB[(i + 1) % verticesB.size()].x - verticesB[i].x,
			verticesB[(i + 1) % verticesB.size()].y - verticesB[i].y
		};

		// Get perpendicular axis
		Vector2 axis = { -edge.y, edge.x };

		// Normalize axis
		float magnitude = sqrt(axis.x * axis.x + axis.y * axis.y);
		if (magnitude > 0) {
			axis.x /= magnitude;
			axis.y /= magnitude;
		}

		// Projection values of both shapes onto the axis
		float minA = INFINITY, maxA = -INFINITY;
		float minB = INFINITY, maxB = -INFINITY;

		// Project shape A
		for (const auto& vertex : verticesA) {
			float projection = DotProduct(axis, vertex);
			minA = min(minA, projection);
			maxA = max(maxA, projection);
		}

		// Project shape B
		for (const auto& vertex : verticesB) {
			float projection = DotProduct(axis, vertex);
			minB = min(minB, projection);
			maxB = max(maxB, projection);
		}

		// Check for gap
		if (maxA < minB || maxB < minA) {
			return false;
		}
	}

	return true; // No separating axis found = collision
}


// Helper method for calculating dot product

float DotProduct(const Vector2& v1, const Vector2& v2) {
	return (v1.x * v2.x) + (v1.y * v2.y);
}

Vector2 TripleProdcut(const Vector2& A, const Vector2& B, const Vector2& C)
{
	//A x (B x C) = A dot C * B - A dot B * C

	float dotAC = DotProduct(A, C);
	float dotBC = DotProduct(B, C);

	Vector2 v1 = { B.x * dotAC, B.y * dotAC };

	Vector2 v2 = { B.x * dotAC, B.y * dotAC };

	Vector2 result = { v1.x - v2.x, v1.y - v2.y };

	return result;
}


bool CollisionGJK(vector<Vector2> verticesA, vector<Vector2> verticesB)
{
	//using random direction
	//TODO switch to vector between center of the two shapes
	Vector2 direction = { 1 , 0 };

	//build our simplex
	vector<Vector2> simplex;

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


bool HandleSimplex(vector<Vector2> simplex, Vector2 direction)
{
	//check the line case
	if (simplex.size() == 2)
	{
		return (LineCase(simplex, direction));
	}
	else
	{
		return (TriangleCase(simplex, direction));
	}

	//check the triangle case
}


bool LineCase(vector<Vector2> simplex, Vector2 direction)
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

bool TriangleCase(vector<Vector2> simplex, Vector2 direction)
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


//finds the support point in a given direction of the minkowski difference of the two shapes
Vector2 SupportFunction(vector<Vector2> verticesA, vector<Vector2> verticesB, Vector2 direction)
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