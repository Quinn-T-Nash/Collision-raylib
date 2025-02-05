
#include "raylib.h"
#include "Functions.h"

#include "Shape.h"
#include "RectangleShape.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "QN-BSSD6000: raylib collisions");

	int positionX = screenWidth / 2;
	int positionY = screenHeight / 2;

	bool movePosX = true;
	int movingX = positionX - 100;
	int movingY = positionY;

	Vector2 collisionPt = { 0,0 };
	bool bCollision = false;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	//Get a random place on screen
	int randomX = rand() % screenWidth + 1;
	int randomY = rand() % screenHeight + 1;
	//int randomY = positionY;

	int randomSpeed = rand() % 5 + 1;

	Vector2 startPostion = { randomX,randomY };

	Shape shapeA(startPostion, randomSpeed);


	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------

		//check wall collisions
		if (shapeA.position.x <= 0 || shapeA.position.x >= screenWidth)
		{
			//change moving direction
			shapeA.movementX = -shapeA.movementX;
		}

		if (shapeA.position.y <= 0 || shapeA.position.y >= screenHeight)
		{
			shapeA.movementY = -shapeA.movementY;
		}

		//----------------------------------------------------------------------------------


		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		shapeA.Draw();
		shapeA.Move();

		vector<Vector2> verticesB = {
			{positionX + 0.0f, positionY + 40.0f},
			{positionX + 40.0f, positionY + 40.0f},
			{positionX + 40.0f, positionY - 40.0f }
		};

		DrawTriangleLines(verticesB[0], verticesB[1], verticesB[2], BLACK);


		/*if (CollisionSAT(shapeA.vertices, verticesB))
		{

			shapeA.bCollision = true;
			shapeA.movementX = 0;
			shapeA.movementY = 0;

		}*/

		if (CollisionGJK(shapeA.vertices, verticesB))
		{
			shapeA.bCollision = true;
			shapeA.movementX = 0;
			shapeA.movementY = 0;

		}

		//draw the line post collision
		if (bCollision)
		{
			DrawLine(collisionPt.x, collisionPt.y, movingX, movingY, BLACK);
		}

		DrawFPS(10, 10);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}


