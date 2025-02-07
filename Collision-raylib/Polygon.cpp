#include "Polygon.h"


Polygon::Polygon(Screen& screen, Vec2<int> dimensions)
	: Shape(screen)
{
	this->dimensions = dimensions;
}

Vec2<int> Polygon::getDimensions()
{
	return dimensions;
}

void Polygon::setDimensions(Vec2<int> dimensions)
{
	this->dimensions = dimensions;
}

//Functions to add move or reset vertexs
void Polygon::addVertex(const Vec2<int>& vertex)
{
	vertices.push_back(vertex);
}

void Polygon::clearVertices()
{
	vertices.clear();
}

const std::vector<Vec2<int>>& Polygon::getVertices() const
{
	return vertices;
}
