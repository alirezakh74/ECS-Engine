#ifndef CSPRITE_H
#define CSPRITE_H

#include <stdexcept>

#include <SFML/Graphics.hpp>


class CSprite
{
public:
    sf::Texture texture;
    sf::Sprite sprite;
    CSprite() {};
    CSprite(const std::string& filename) 
    {
        if(!texture.loadFromFile(filename))
        {
            throw std::runtime_error("CSprite::constructor - Faild to load texture " + filename);
        }
        
        sprite.setTexture(texture);
    };
};


#endif