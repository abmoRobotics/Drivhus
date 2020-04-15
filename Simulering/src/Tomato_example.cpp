#include "tomato_plant.h"
#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include <iostream>


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

    //sf::RectangleShape tomato_stalk {sf::Vector2f{5.0,stalk_length}};


    Tomato tomato_stalk;

    tomato_stalk.setPosition({300.0,600.0});
    tomato_stalk.setRotation(180);
    sf::CircleShape tomatfr(10.0);
    tomatfr.setFillColor(sf::Color::Red);
    //lav tomat skud
    sf::RectangleShape tomato_skud({5.0,50});
    tomato_skud.setFillColor(sf::Color::Green);
    

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
        ImGui::SetNextItemWidth(100.0);
        ImGui::Begin("Hello, world");

        if (ImGui::Button("GROW THANKS", {100.0,20.0}))
        {
            tomato_stalk.simulateday(2);
        }


        if (ImGui::SliderFloat("Length", &stalk_length, 0.0, 100.0)){
            tomato_stalk.setSize(sf::Vector2f{stalk_length/15+5, stalk_length});
        };
        ImGui::End();
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(tomato_stalk);

        bool direction = false;
        for (size_t i = 0; i < tomato_stalk.getHeight(); i+= 50)
        {
            sf::Vector2f position = tomato_stalk.getPosition();
            position += {(float)0.0,-(float)i};
            tomato_skud.setPosition(position);

            if (direction == false){
                tomato_skud.setRotation(-135);
                window.draw(tomato_skud);
                sf::Vector2f offsetFromStalk = sf::Vector2f{20.0,-40};
                tomatfr.setPosition(position+offsetFromStalk);
                window.draw(tomatfr);
                direction = true;
            } else{
                tomato_skud.setRotation(135);
                window.draw(tomato_skud);
                sf::Vector2f offsetFromStalk = sf::Vector2f{20.0-60,-40};
                tomatfr.setPosition(position+offsetFromStalk);
                window.draw(tomatfr);
                direction = false;
                }

        }
        
        if (tomato_stalk.getHeight() > 100)
        {
            window.draw(tomatfr);
        }
        
        
        ImGui::SFML::Render(window);
        // end the current frame
        window.display();
    }
    
}
