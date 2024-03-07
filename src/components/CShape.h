#ifndef CSHAPE_H
#define CSHAPE_H

#include <SFML/Graphics.hpp>

class CShape
{
public:
    sf::CircleShape shape;
    CShape() {};
    CShape(float r)  { shape.setRadius(r); }
};

#endif