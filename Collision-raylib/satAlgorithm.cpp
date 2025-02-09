#include "satAlgorithm.h"

bool satAlgorithm::CheckCollision(std::vector<Vec2<int>> vecA, std::vector<Vec2<int>> vecB)
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
			minA = std::min(minA, projection);
			maxA = std::max(maxA, projection);
		}

		// Project shape B
		for (const auto& vertex : verticesB) {
			float projection = DotProduct(axis, vertex);
			minB = std::min(minB, projection);
			maxB = std::max(maxB, projection);
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
			minA = std::min(minA, projection);
			maxA = std::max(maxA, projection);
		}

		// Project shape B
		for (const auto& vertex : verticesB) {
			float projection = DotProduct(axis, vertex);
			minB = std::min(minB, projection);
			maxB = std::max(maxB, projection);
		}

		// Check for gap
		if (maxA < minB || maxB < minA) {
			return false;
		}
	}

	return true; // No separating axis found = collision
}

