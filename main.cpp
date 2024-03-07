#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "src/Vec2.h"
#include "src/entities/Entity.h"
#include "src/systems/systems.h"

#include "imgui.h"
#include "imgui-SFML.h"

int main(int argc, char * argv[])
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "ECS-Engine");
    window.setFramerateLimit(60);

    ImGui::SFML::Init(window);

    Vec2f pos(100, 100), vel(5, 5), accel(0, 0);
    std::vector<Entity> entities;
    Entity e;
    e.cTransform = std::make_shared<CTransform>(pos, vel, accel);
    e.cName = std::make_shared<CName>("Red Box");
    e.cShape = std::make_shared<CShape>(50);
    entities.push_back(e);

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);
            if(event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("first imgui test");
        ImGui::Button("this is a button");
        ImGui::Separator();
        ImGui::Button("this is a button2");
        ImGui::End();
        
        window.clear();
        // for(auto e : entities)
        // {
        //     window.draw(e.cShape->shape);
        // }
        sMovement(entities);
        sRender(entities, window);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    
    return 0;
}
