#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"
#include "raylib.h"

namespace CustomObjects {

	class Rectangle : public Polygon
	{
	public:

		Rectangle() = default;

		Rectangle(Vec2<int> center, Vec2<int> speed) : Polygon(center, speed) {};

		void draw(Screen* screen) override;

	protected:

		Vec2<int> calcVertices(int width, int height) override;

	};

}
#endif