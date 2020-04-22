#include "Tomato.h"
#include "Cucumber.h"
#include "Melon.h"
#include "graphics.h"
#include <iostream>
#include "water_reservoir.h"
#include <math.h>

#define PI 3.14159265
void dataWindow(sf::Vector2u pos, WaterReservoir &reservoir, sf::RenderWindow &window);

double degtorad(double deg)
{
    double rad = (deg * PI) / 180.0;
    return rad;
}
int main(int argc, char const *argv[])
{

    //Hvad er det her
    float offsetX = 300;
    float offsetY = -40;

    // create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tomato Simulator");
    window.setFramerateLimit(144);
    ImGui::SFML::Init(window);

    float windowHeight = window.getSize().y;
    float windowLength = window.getSize().x;

    //variable for slider
    int days = 1;
    //Defines a Waterreservoir, for later use in the grow() function.
    WaterReservoir water_reservoir;

    //Defines a vector consisting of pointers of type "PlantBase"
    std::vector<std::unique_ptr<PlantBase>> greenhouse;

    //Pushes pointer into greenhouse - respresenting tomatos and cucumbers
    greenhouse.push_back(std::make_unique<Tomato>(470.0F - offsetX, windowHeight - 160 - offsetY));
    greenhouse.push_back(std::make_unique<Tomato>(570.0F - offsetX, windowHeight - 200 - offsetY));
    greenhouse.push_back(std::make_unique<Cucumber>(670.0F - offsetX, windowHeight - 250 - offsetY));
    greenhouse.push_back(std::make_unique<Melon>(705.0F - offsetX, windowHeight - 190 - offsetY));
    greenhouse.push_back(std::make_unique<Melon>(625.0F - offsetX, windowHeight - 150 - offsetY));
    greenhouse.push_back(std::make_unique<Melon>(550.0F - offsetX, windowHeight - 100 - offsetY));
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

        /**********************************************************************
        *                            Setup green house
        * *********************************************************************/

        //setup greenhouse
        float sizegh{600};
        float posx = (windowLength - sizegh) / 2;
        float posy{100};
        sf::RectangleShape GreenhouseBack;
        sf::Texture gh;
        gh.loadFromFile("drivhusBagerst.png");
        GreenhouseBack.setSize({sizegh, sizegh});
        GreenhouseBack.setPosition({posx - offsetX, posy - offsetY});
        GreenhouseBack.setTexture(&gh);

        //setup greenhouse Front
        sf::RectangleShape GreenhouseFront;
        sf::Texture ghf;
        ghf.loadFromFile("drivhusForrest.png");
        GreenhouseFront.setSize({sizegh, sizegh});
        GreenhouseFront.setPosition({posx - offsetX, posy - offsetY});
        GreenhouseFront.setTexture(&ghf);

        // clear the window with black color
        window.clear(sf::Color::Transparent);
        //window.draw(background);
        window.draw(GreenhouseBack);

        /**********************************************************************
        *                             Interface
        * *********************************************************************/

        if (ImGui::SliderInt("Days to grow", &days, 0., 10.))
        {
        }

        if (ImGui::Button("GROW THANKS", {200.0, 20.0}))
        {
            for (size_t i = 0; i < greenhouse.size(); i++)
                greenhouse[i]->grow(days, water_reservoir);
        }

        if (ImGui::Button("Fill up Water", {200.0, 20.0}))
        {
            water_reservoir.FillUp('w', 100);
        }

        if (ImGui::Button("Fill up Nutrition", {200.0, 20.0}))
        {
            water_reservoir.FillUp('n', 100);
        }

        if (ImGui::Button("GrOw DoWn", {200.0, 20.0}))
        {
            for (size_t i = 0; i < greenhouse.size(); i++)
                greenhouse[i]->grow(-days, water_reservoir);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i a = sf::Mouse::getPosition(window);
            for (auto &i : greenhouse)
            {
                i->harvest((int)a.x, (int)a.y);
            }
        }
        //ImGui::End();
        /**********************************************************************
        *                              Graphics
        * *********************************************************************/
        sf::Vector2u pos{1000, 50};
        dataWindow(pos, water_reservoir, window);

        for (size_t i = 0; i < greenhouse.size(); i++)
        {
            greenhouse[i]->draw(window);
        }

        window.draw(GreenhouseFront);

        ImGui::SFML::Render(window);
        // end the current frame
        window.display();
    }
}

void dataWindow(sf::Vector2u pos, WaterReservoir &reservoir, sf::RenderWindow &window)
{
    sf::Vector2f posFloat{(float)pos.x, (float)pos.y};
    sf::RectangleShape rect;
    rect.setSize({200.0F, 300.0F});
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(5.0F);
    rect.setPosition(posFloat);
    window.draw(rect);

    sf::Font font;
    font.loadFromFile("arial_narrow_7.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);

    text.setString("Levels");
    text.setPosition(pos.x + 70, pos.y + 10);
    window.draw(text);
    const std::vector<char> letters = {'W', 'K', 'P', 'N'};

    for (int i = 0; i < letters.size(); i++)
    {
        int offset = 45;
        int spacing = 40;
        text.setString(letters[i]);
        text.setPosition(pos.x + offset + (spacing * i) - text.getLocalBounds().width, pos.y + 70);
        window.draw(text);
        sf::RectangleShape outerShape;
        outerShape.setSize({21.0F, 153.0F});
        outerShape.setPosition(pos.x + offset + (spacing * i) - text.getLocalBounds().width / 2 - outerShape.getGlobalBounds().width / 2, pos.y + 110);
        window.draw(outerShape);
        sf::RectangleShape innerShape;
        innerShape.setFillColor(sf::Color::Blue);
        innerShape.setSize({15.0F, 147.0F * ((float)reservoir.getNutrition(letters[i])) / 100.0F});
        innerShape.setPosition(pos.x + offset + (spacing * i) - text.getLocalBounds().width / 2 - innerShape.getGlobalBounds().width / 2, pos.y + 113 + 147 - innerShape.getGlobalBounds().height);
        window.draw(innerShape);
    }

    /*     sf::Vector2i a = sf::Mouse::getPosition(window);
    text.setString(std::to_string(a.x));
    text.setPosition(100, 100);
    window.draw(text);
    text.setString(std::to_string(a.y));
    text.setPosition(150, 100);
    window.draw(text); */
}