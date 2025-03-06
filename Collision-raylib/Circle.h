#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

namespace CustomObjects {

	class Circle : public Shape
	{
	public:

		Circle() = default;

		Circle(Vec2<int> center, Vec2<int> speed);

		void draw(Screen* screen) override;

		int getRadius() const { return radius; }

	private:

		int radius;
	};
}

#endif