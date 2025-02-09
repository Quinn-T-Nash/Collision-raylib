/*
Quinn Nash
qnash@live.nmhu.edu
Collision-raylib

Goal: Generative art using SAT and GJK collision algorithms with the raylib open source graphics API
*/

#include "Screen.h"
#include "Rectangle.h"
#include "gjkAlgorithm.h"
#include "satAlgorithm.h"
#include <vector>

int main(void)
{
	// Initialization
	std::vector<Vector2> vecCollisionPts;

	Vec2<int> screenSize{ 600, 400 };

	Screen screen(screenSize);

	CustomObjects::Rectangle rectangle(screenSize, Vec2(40, 40));
	CustomObjects::Rectangle rectangle2(screenSize, Vec2(40, 40));


	screen.pShapes[0] = &rectangle;
	screen.pShapes[1] = &rectangle2;


	while (!screen.screenClosed())
	{
		screen.update(vecCollisionPts);


		if (gjkAlgorithm::CheckCollision(rectangle.getVertices(), rectangle2.getVertices()))
		{
			Vec2<int> approxCollisionPt = rectangle.getCenter();

			Vector2 pt = { approxCollisionPt.getX(), approxCollisionPt.getY() };

			vecCollisionPts.push_back(pt);

			rectangle.setSpeed(rectangle.getSpeed() * -1);
			rectangle2.setSpeed(rectangle2.getSpeed() * -1);

		}

	}


	/*if (CollisionSAT(shapeA.vertices, shapeB.vertices))
	{
		shapeA.NegateMovements();
		shapeB.NegateMovements();

		collisionPtA = { shapeA.position.x, shapeA.position.y };
		collisionPtB = { shapeB.position.x, shapeB.position.y };

		shapeA.satLines.push_back(collisionPtA);
		shapeB.satLines.push_back(collisionPtB);

		bCollision = !bCollision;
	}

	if (CollisionGJK(shapeA.vertices, shapeB.vertices))
	{
		shapeA.NegateMovements();
		shapeB.NegateMovements();

		collisionPtA = { shapeA.position.x, shapeA.position.y };
		collisionPtB = { shapeB.position.x, shapeB.position.y };

		shapeA.gjkLines.push_back(collisionPtA);
		shapeB.gjkLines.push_back(collisionPtB);

		bCollision = !bCollision;
	}*/

	return 0;
}


