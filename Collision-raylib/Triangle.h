#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"
#include "raylib.h"

namespace CustomObjects {

	class Triangle : public Polygon
	{
	public:

		Triangle() = default;

		Triangle(Vec2<int> center, Vec2<int> speed) : Polygon(center, speed) {};

		void draw(Screen* screen) override;

	protected:

		Vec2<int> calcVertices(int width, int height) override;

	};

}

#endif

