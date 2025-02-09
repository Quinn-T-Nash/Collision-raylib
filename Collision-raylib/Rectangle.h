#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"
#include "raylib.h"

namespace CustomObjects {

	class Rectangle : public Polygon
	{
	public:

		Rectangle() = default;

		Rectangle(Vec2<int> bounds, Vec2<int> dimensions) : Polygon(bounds, dimensions) {};

		void draw() override;

	protected:

		void calcVertices() override;

	};

}
#endif