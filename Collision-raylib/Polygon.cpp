#include "Polygon.h"

#include<random>

Polygon::Polygon(Vec2<int> center, Vec2<int> speed)
	:Shape(center, speed)
{

	std::random_device rd; // True random number generator
	std::mt19937 gen(rd()); // Mersenne Twister engine

	//Generate a dimensions speed
	std::uniform_int_distribution<> width(40, 80);
	std::uniform_int_distribution<> height(40, 80);

	this->dimensions = Vec2<int>(width(gen), height(gen));

}

Vec2<int> Polygon::getDimensions()
{
	return dimensions;
}

void Polygon::setDimensions(Vec2<int> dimensions)
{
	this->dimensions = dimensions;
}


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

