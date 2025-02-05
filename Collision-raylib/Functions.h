#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <raylib.h>
#include <vector>
#include <math.h>


using namespace std;

bool CollisionSAT(vector<Vector2> verticesA, vector<Vector2> verticesB);

float DotProduct(const Vector2& pt1, const Vector2& pt2);

Vector2 TripleProdcut(const Vector2& A, const Vector2& B, const Vector2& C);

bool CollisionGJK(vector<Vector2> verticesA, vector<Vector2> verticesB);

bool HandleSimplex(vector<Vector2> simplex, Vector2 direction);

bool LineCase(vector<Vector2> simplex, Vector2 direction);

bool TriangleCase(vector<Vector2> simplex, Vector2 direction);

Vector2 SupportFunction(vector<Vector2> verticesA, vector<Vector2> verticesB, Vector2 direction);

#endif // !FUNCTIONS_H

