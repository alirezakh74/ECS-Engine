#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <vector>
#include "../entities/Entity.h"

void sMovement(std::vector<Entity>& entities)
{
    for(auto e : entities)
    {
        if(e.cTransform)
        {
            e.cTransform->velocity += e.cTransform->acceleration;
            e.cTransform->position += e.cTransform->velocity;
            e.cShape->shape.setPosition(e.cTransform->position.x, e.cTransform->position.y);
        }

    }
}

void sPhysics(std::vector<Entity>& entities)
{
    for(auto e : entities)
    {
        if(e.cBBox)
        {

        }
    }
}

void sRender(std::vector<Entity>& entities, sf::RenderWindow& window)
{
    for(auto e : entities)
    {
        if(e.cTransform && e.cShape)
        {
            window.draw(e.cShape->shape);
        }
    }
}

#endif // SYSTEMS_H