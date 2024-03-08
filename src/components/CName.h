#ifndef CNAME_H
#define CNAME_H

#include <string>

#include <SFML/Graphics.hpp>

class CName
{
public:
    std::string name = "";
    sf::Text text;
    CName() {};
    CName(const std::string& n) : name(n) {}
    CName(const std::string& n, const sf::Font& f) : name(n)
    {
        text.setFont(f);
        text.setString(name);
    }
};


#endif