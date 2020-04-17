#include "Tomato.h"
#include "Cucumber.h"
#include "Melon.h"
#include "graphics.h"
#include <iostream>
#include "water_reservoir.h"

int main(int argc, char const *argv[])
{

 // create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tomato Simulator");
    window.setFramerateLimit(144);
    ImGui::SFML::Init(window);

    //Defines a vector consisting of pointers of type "PlantBase"
    std::vector<std::shared_ptr<PlantBase>> greenhouse;

    //Defines a Waterreservoir, for later use in the grow() function.
    WaterReservoir Reservoir;

    int days = 0;

    //Pushes pointer into greenhouse - respresenting tomatos and cucumbers
    float windowHeight = window.getSize().y;
    greenhouse.push_back(std::make_shared<Tomato>(100.0F, windowHeight));
    greenhouse.push_back(std::make_shared<Tomato>(200.0F, windowHeight));
    greenhouse.push_back(std::make_shared<Cucumber>(300.0F, windowHeight));
    greenhouse.push_back(std::make_shared<Melon>(400.0F, windowHeight));
    greenhouse.push_back(std::make_shared<Melon>(600.0F, windowHeight));
    greenhouse.push_back(std::make_shared<Melon>(800.0F, windowHeight));
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
        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::SetNextItemWidth(100.0);

        // clear the window with black color
        window.clear(sf::Color::Black);

        



        //Create dialog box
        ImGui::Begin("Greenhouse");
        //Button
        if (ImGui::SliderInt("Days to grow", &days, 0., 10.)){}

        if (ImGui::Button("GROW THANKS", {200.0, 20.0}))
        {
            for (size_t i = 0; i < greenhouse.size(); i++)
                greenhouse[i]->grow(days, Reservoir);
                std::cout << "Nutrition level er: " << Reservoir.getNutrition() << std::endl;
        }

        if(ImGui::Button("Fill up Water", {200.0, 20.0})){
            Reservoir.FillUp('w', 100);
        }
        
        if(ImGui::Button("Fill up Nutrition", {200.0, 20.0})){
            Reservoir.FillUp('n', 100);
        }
        
        ImGui::End();
        /**********************************************************************
        *                              Graphics
        * *********************************************************************/

        for (size_t i = 0; i < greenhouse.size(); i++)
        {
            greenhouse[i]->draw(window);
        }

        ImGui::SFML::Render(window);
        // end the current frame
        window.display();
    }
}


