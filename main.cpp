#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "src/Vec2.h"
#include "src/entities/Entity.h"
#include "src/systems/systems.h"

#include "imgui.h"
#include "imgui-SFML.h"

int main(int argc, char * argv[])
{
    int windowWidth = 640, windowHeight = 480;
    sf::Font font;
    sf::Text testText;
    std::vector<Entity> entities;

    std::ifstream file;
    std::string line;
    file.open("assets/configs/config.txt");
    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            //std::cout << line << "\n";
            std::istringstream iss(line);
            std::string s;
            while(std::getline(iss, s, ' '))
            {
                if(s == "Window")
                {
                    int width = 0, height = 0;
                    iss >> width >> height;
                    windowWidth = width;
                    windowHeight = height;
                    std::cout << s << " " << width << " " << height << "\n";
                }
                else if(s == "Font")
                {
                    std::string path = "";
                    int size=0,r=0,g=0,b=0;
                    iss >> path >> size >> r >> g >> b;
                    if(!font.loadFromFile("assets/" + path))
                    {
                        throw std::runtime_error("Unable to load font: assets/" + path);
                    }
                    std::cout << s << " " << path << " " << size << " " << r << " " << g << " " << b << " " << "\n";
                }
                else if(s == "Circle")
                {
                    std::string name = "";
                    Vec2f pos(0, 0), vel(0, 0), accel(0, 0);
                    int r=0,g=0,b=0,size=0;
                    iss >> name >> pos.x >> pos.y >> vel.x >> vel.y >> r >> g >> b >> size;
                    std::cout << s << " " << name << " " << pos << vel << r << " " << g << " " << b << " " << size << "\n";
                    
                    Entity e;
                    e.cTransform = std::make_shared<CTransform>(pos, vel, accel);
                    e.cName = std::make_shared<CName>(name, font);
                    sf::CircleShape shape(size);
                    shape.setFillColor(sf::Color(r,g,b));
                    e.cShape = std::make_shared<CShape>(shape);
                    e.cBBox = std::make_shared<CBBox>(size + 50, size + 50);
                    entities.push_back(e);
                }
                else if(s == "Rectangle")
                {
                    std::string name = "";
                    Vec2f pos(0, 0), vel(0, 0), accel(0, 0);
                    int r=0,g=0,b=0,width=0,height=0;
                    iss >> name >> pos.x >> pos.y >> vel.x >> vel.y >> r >> g >> b >> width >> height;
                    std::cout << s << " " << name << " " << pos << vel << r << " " << g << " " << b << " " << width << " " << height << "\n";

                    Entity e;
                    e.cTransform = std::make_shared<CTransform>(pos, vel, accel);
                    e.cName = std::make_shared<CName>(name, font);
                    sf::RectangleShape shape(sf::Vector2f(width, height));
                    shape.setFillColor(sf::Color(r,g,b));
                    e.cShape = std::make_shared<CShape>(shape);
                    e.cBBox = std::make_shared<CBBox>(width, height);
                    entities.push_back(e);
                }
            }
            
        }
        file.close();
    }
    else
    {
        throw std::runtime_error("Unable to open config file");
    }

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "ECS-Engine");
    window.setFramerateLimit(60);

    //ImGui::SFML::Init(window);

    // Vec2f pos(100, 100), vel(5, 5), accel(0, 0);
    // Entity e;
    // e.cTransform = std::make_shared<CTransform>(pos, vel, accel);
    // e.cName = std::make_shared<CName>("Red Box");
    // e.cShape = std::make_shared<CShape>(50);
    // entities.push_back(e);

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //ImGui::SFML::ProcessEvent(window, event);
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // ImGui::SFML::Update(window, deltaClock.restart());

        // ImGui::Begin("first imgui test");
        // ImGui::Button("this is a button");
        // ImGui::Separator();
        // ImGui::Button("this is a button2");
        // ImGui::End();
        
        window.clear();
        sMovement(entities);
        sPhysics(entities);
        sRender(entities, window);
        //ImGui::SFML::Render(window);
        window.display();
    }

    //ImGui::SFML::Shutdown();
    
    return 0;
}
