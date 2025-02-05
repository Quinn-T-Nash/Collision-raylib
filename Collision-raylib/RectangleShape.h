#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H
#include "Shape.h"

class RectangleShape :
    public Shape
{
public:

    RectangleShape();

    RectangleShape(Vector2 startPosition, int width, int height);

    void Draw();

private:

    int height;
    int width;

};

#endif
