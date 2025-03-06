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

bool satAlgorithm::CheckCircleCollision(const CustomObjects::Circle& circleA, const CustomObjects::Circle& circleB)
{

	// Get the centers of the circles
	Vec2<int> centerA = circleA.getCenter();
	Vec2<int> centerB = circleB.getCenter();

	// Calculate the distance between centers
	float dx = static_cast<float>(centerB.getX() - centerA.getX());
	float dy = static_cast<float>(centerB.getY() - centerA.getY());
	float distanceSquared = dx * dx + dy * dy;

	// Get the radii of the circles
	float radiusA = static_cast<float>(circleA.getRadius());
	float radiusB = static_cast<float>(circleB.getRadius());

	// Calculate the sum of radii
	float sumRadii = radiusA + radiusB;

	// Circles collide if the distance between centers is less than or equal to the sum of radii
	return distanceSquared <= sumRadii * sumRadii;
}


// Polygon-to-circle collision detection
bool satAlgorithm::CheckPolygonToCircleCollision(const std::vector<Vec2<int>>& vertices, const CustomObjects::Circle& circle)
{
	// Get the center of the circle
	Vec2<int> circleCenter = circle.getCenter();
	float circleRadius = static_cast<float>(circle.getRadius());

	// Case 1: Check if the circle's center is inside the polygon
	if (IsPointInPolygon(vertices, circleCenter)) {
		return true;
	}

	// Case 2: Check if any polygon edge intersects with the circle
	float minimumDistance = std::numeric_limits<float>::infinity();

	// Test each edge of the polygon
	for (size_t i = 0; i < vertices.size(); i++) {
		// Get the current vertex and the next vertex to form an edge
		const Vec2<int>& currentVertex = vertices[i];
		const Vec2<int>& nextVertex = vertices[(i + 1) % vertices.size()];

		// Find the minimum distance from the circle's center to the edge
		float distance = satAlgorithm::FindMinimumDistanceFromPointToLine(circleCenter, currentVertex, nextVertex);

		// Update the minimum distance found
		minimumDistance = std::min(minimumDistance, distance);

		// If this distance is less than the circle's radius, there's a collision
		if (distance <= circleRadius) {
			return true;
		}
	}

	// No collision detected
	return false;
}

float satAlgorithm::FindMinimumDistanceFromPointToLine(const Vec2<int>& point, const Vec2<int>& lineStart, const Vec2<int>& lineEnd)
{
	// Calculate the squared length of the line segment
	float lineSquaredLength = static_cast<float>((lineEnd.getX() - lineStart.getX()) * (lineEnd.getX() - lineStart.getX()) +
		(lineEnd.getY() - lineStart.getY()) * (lineEnd.getY() - lineStart.getY()));

	// If the line is actually a point, return the distance to that point
	if (lineSquaredLength == 0.0) {
		float dx = static_cast<float>(point.getX() - lineStart.getX());
		float dy = static_cast<float>(point.getY() - lineStart.getY());
		return std::sqrt(dx * dx + dy * dy);
	}

	// Calculate the projection of the point onto the line
	float t = ((point.getX() - lineStart.getX()) * (lineEnd.getX() - lineStart.getX()) +
		(point.getY() - lineStart.getY()) * (lineEnd.getY() - lineStart.getY())) / lineSquaredLength;

	// Clamp t to [0, 1] to ensure we're on the line segment
	t = std::max(0.0f, std::min(1.0f, t));

	// Calculate the closest point on the line segment
	Vector2 closestPoint = {
		lineStart.getX() + t * (lineEnd.getX() - lineStart.getX()),
		lineStart.getY() + t * (lineEnd.getY() - lineStart.getY())
	};

	// Calculate the distance to the closest point
	float dx = point.getX() - closestPoint.x;
	float dy = point.getY() - closestPoint.y;

	return std::sqrt(dx * dx + dy * dy);
}

// Helper function to check if a point is inside a polygon
bool satAlgorithm::IsPointInPolygon(const std::vector<Vec2<int>>& vertices, const Vec2<int>& point)
{
	// Implementation of the ray casting algorithm
	bool inside = false;

	for (size_t i = 0, j = vertices.size() - 1; i < vertices.size(); j = i++) {
		// Check if the point is on a vertex
		if ((vertices[i].getX() == point.getX() && vertices[i].getY() == point.getY()) ||
			(vertices[j].getX() == point.getX() && vertices[j].getY() == point.getY())) {
			return true;
		}

		// Check if the ray from the point crosses the edge
		if (((vertices[i].getY() > point.getY()) != (vertices[j].getY() > point.getY())) &&
			(point.getX() < (vertices[j].getX() - vertices[i].getX()) * (point.getY() - vertices[i].getY()) /
				(vertices[j].getY() - vertices[i].getY()) + vertices[i].getX())) {
			inside = !inside;
		}
	}

	return inside;
}