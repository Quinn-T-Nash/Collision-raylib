#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "Shape.h"

class Polygon : public Shape
{
public:

	Polygon() = default;

	Polygon(Vec2<int> center, Vec2<int> speed);

	Vec2<int> getDimensions();

	void setDimensions(Vec2<int> dimensions);

	const std::vector<Vec2<int>>& getVertices() const;

protected:
	
	//Functions to add move or reset vertexs
	virtual Vec2<int> calcVertices(int width, int height) = 0;

	void addVertex(const Vec2<int>& vertex);

	void clearVertices();

private:

	Vec2<int> dimensions;
	std::vector<Vec2<int>> vertices;

};

#endif