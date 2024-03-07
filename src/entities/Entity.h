#ifndef ENTITY_H
#define ENTITY_H

#include <memory>

#include "../components/CTransform.h"
#include "../components/CName.h"
#include "../components/CShape.h"
#include "../components/CBBox.h"

class Entity
{
public:
    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CName> cName;
    std::shared_ptr<CShape> cShape;
    std::shared_ptr<CBBox> cBBox;
    Entity() {};
};

#endif