//#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/Vec2.h"


int main(int argc, char * argv[])
{
    Vec2f v1(100, 100);
    Vec2f v2(50, 50);
    v1 = v1 + v2;
    std::cout << v1;
    return 0;
}