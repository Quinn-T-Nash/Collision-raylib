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

Vector2 convertToVector2(const Vec2<int>& vec) {
	// Create a new Vector2 and convert the integer components to float
	return Vector2{
		static_cast<float>(vec.getX()),  // Convert x component from int to float
		static_cast<float>(vec.getY())   // Convert y component from int to float
	};
}

Color getRandomRGB()
{

	std::random_device rd; // True random number generator
	std::mt19937 gen(rd()); // Mersenne Twister engine

	//Generate a random spot on screen
	std::uniform_int_distribution<> disColor(0, 255);

	return Color{
	   static_cast<unsigned char>(disColor(gen)),  // r
	   static_cast<unsigned char>(disColor(gen)),  // g
	   static_cast<unsigned char>(disColor(gen)),  // b
	   255                                         // a (fully opaque)
	};
}

