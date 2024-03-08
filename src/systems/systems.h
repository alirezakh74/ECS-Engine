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
            e.cShape->circleShape.setPosition(e.cTransform->position.x, e.cTransform->position.y);
            e.cShape->rectangleShape.setPosition(e.cTransform->position.x, e.cTransform->position.y);
            e.cName->text.setPosition(e.cTransform->position.x, e.cTransform->position.y);
        }
    }
}

void sPhysics(std::vector<Entity>& entities)
{
    for(auto e : entities)
    {
        if(e.cBBox)
        {
            if((e.cTransform->position.x < 0) || 
            (e.cTransform->position.x + e.cBBox->width > 640))
            {
                e.cTransform->velocity.x *= -1;
            }
            if((e.cTransform->position.y < 0) || 
            (e.cTransform->position.y + e.cBBox->height > 480))
            {
                e.cTransform->velocity.y *= -1;
            }
        }
    }
}

void sRender(std::vector<Entity>& entities, sf::RenderWindow& window)
{
    for(auto e : entities)
    {
        if(e.cTransform && e.cShape)
        {
            window.draw(e.cShape->circleShape);
            window.draw(e.cShape->rectangleShape);
            window.draw(e.cName->text);
        }
    }
}

#endif // SYSTEMS_H