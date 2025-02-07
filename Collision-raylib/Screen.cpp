#include "Screen.h"

Screen::Screen(int screenWidth, int screenHeight)
{
	this->screenWidth = screenWidth;
	this->screnHeight = screenHeight;

	InitWindow(screenWidth, screenHeight, "QN-BSSD6000: raylib collisions");

	SetTargetFPS(60);
}

void Screen::startScreenLoop()
{
	Shape* shape[2];


	while (!WindowShouldClose())
	{

	}

	CloseWindow();        // Close window and OpenGL context

}

void Screen::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawFPS(10, 10);


	//whatever I wabnt to draw


	EndDrawing();

}

int Screen::getScreenWidth()
{
	return screenWidth;
}

int Screen::getScreenHeight()
{
	return screnHeight;
}
