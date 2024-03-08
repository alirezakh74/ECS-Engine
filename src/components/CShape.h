#ifndef CSHAPE_H
#define CSHAPE_H

#include <SFML/Graphics.hpp>

class CShape
{
public:
    sf::CircleShape circleShape;
    sf::RectangleShape rectangleShape;
    CShape() {}
    CShape(sf::CircleShape s) : circleShape(s) {}
    CShape(sf::RectangleShape s) : rectangleShape(s) {}
};

#endif