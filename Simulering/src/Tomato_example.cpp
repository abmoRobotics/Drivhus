#include "tomato_plant.h"
#include <thread>
#include <chrono>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

void simulateOneDay(PlantBase &a_plant){
    a_plant.grow(1);
}

int main(int argc, char const *argv[])
{
/*     Tomato my_tomato_plant1;
    Tomato my_tomato_plant2;
    for (size_t i = 0; i < 5; i++)
    {
        using namespace std::chrono_literals;
        simulateOneDay(my_tomato_plant1);
        simulateOneDay(my_tomato_plant2);
        std::cout << "Tomato 1 height: " << my_tomato_plant1.getHeight() << std::endl;
        std::cout << "Tomato 2 height: " << my_tomato_plant2.getHeight() << std::endl;
        std::this_thread::sleep_for(1s);
    }
     */

    float stalk_length = 25.0;

    sf::RectangleShape tomato_stalk {sf::Vector2f{5.0,stalk_length}};
    tomato_stalk.setFillColor(sf::Color(0,255,0));
    
 // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tomato Simulator");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window,deltaClock.restart());
        ImGui::Begin("Hello, world");
        ImGui::Button("BUTTON");
        if (ImGui::SliderFloat("Length", &stalk_length, 0.0, 100.0)){
            tomato_stalk.setSize(sf::Vector2f{2.0, stalk_length});
        };
        ImGui::End();
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(tomato_stalk);
        ImGui::SFML::Render(window);
        // end the current frame
        window.display();
    }
    
}
