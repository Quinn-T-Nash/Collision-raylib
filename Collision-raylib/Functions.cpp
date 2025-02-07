#include "Functions.h"

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
