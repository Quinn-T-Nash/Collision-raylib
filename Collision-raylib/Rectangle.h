#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"
#include "raylib.h"

namespace CustomObjects {

	class Rectangle : protected Polygon
	{
	public:

		Rectangle() = default;

		Rectangle(Screen& screen, Vec2<int> dimensions);

		void Update() override;

		void Draw() override;

	protected:

		void calcVertices() override;

	private:

		int height;
		int width;

	};

}
#endif