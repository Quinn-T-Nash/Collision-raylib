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

int Screen::getScreenSize()
{
	return 0;
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
	}

	EndDrawing();

}
