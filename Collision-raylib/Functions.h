#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <raylib.h>
#include <vector>
#include <math.h>

#include "Vec2.h"
#include <random>


float DotProduct(const Vector2& pt1, const Vector2& pt2);

Vector2 TripleProdcut(const Vector2& A, const Vector2& B, const Vector2& C);

Vector2 convertToVector2(const Vec2<int>& vec);

Color getRandomRGB();

#endif // !FUNCTIONS_H

