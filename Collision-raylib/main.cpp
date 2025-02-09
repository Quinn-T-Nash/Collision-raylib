/*
Quinn Nash
qnash@live.nmhu.edu
Collision-raylib

Goal: Generative art using SAT and GJK collision algorithms with the raylib open source graphics API
*/


#include "Screen.h"

#include "Rectangle.h"

int main(void)
{
	// Initialization
	Vec2<int> screenSize{ 1200, 600 };

	Screen screen(screenSize);

	CustomObjects::Rectangle rectangle(screenSize, Vec2(40,40));
	CustomObjects::Rectangle rectangle2(screenSize, Vec2(40, 40));


	screen.pShapes[0] = &rectangle;
	screen.pShapes[1] = &rectangle;


	while (!screen.screenClosed())
	{
		screen.update();
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


