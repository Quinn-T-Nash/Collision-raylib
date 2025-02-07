/*
Quinn Nash
qnash@live.nmhu.edu
Collision-raylib

Goal: Generative art using SAT and GJK collision algorithms with the raylib open source graphics API
*/


#include "Screen.h"

int main(void)
{
	// Initialization
	const int screenWidth = 1200;
	const int screenHeight = 650;

	Screen screen(screenWidth, screenHeight);

	screen.startScreenLoop();

		
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


