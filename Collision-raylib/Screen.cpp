#include "Screen.h"

Screen::Screen(Vec2<int> screenSize)
{
	this->screenSize = screenSize;

	InitWindow(screenSize.getX(), screenSize.getY(), "QN-BSSD6000: raylib collisions");

	SetTargetFPS(60);
}

bool Screen::screenClosed() const
{
	return WindowShouldClose();
}

Vec2<int> Screen::getScreenSize()
{
	return screenSize;
}

void Screen::update(std::vector<Vector2> vecCollisionPts)
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawFPS(10, 10);

	//whatever I wabnt to draw
	for (Shape* shape : pShapes)
	{
		shape->update();
		
		shape->draw();

	}


	for (Vector2 vec : vecCollisionPts)
	{
		DrawCircleV(vec, 15, getRandomRGB());

		//Lines attacvhed to shapeA
		DrawLine(vec.x, vec.y,
			pShapes[0]->getCenter().getX(), pShapes[0]->getCenter().getY(), BLACK);
		
		//Lines attacvhed to shapeB
		DrawLine(vec.x, vec.y,
			pShapes[1]->getCenter().getX(), pShapes[1]->getCenter().getY(), BLACK);
	}

	EndDrawing();

}
