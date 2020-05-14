#include "Tomato.h"
#include "Cucumber.h"
#include "Melon.h"
#include "graphics.h"
#include <iostream>
#include "water_reservoir.h"
#include <math.h>

#define PI 3.14159265

//Define the function "dataWindow" with the given parameters 
void dataWindow(sf::Vector2u pos, WaterReservoir &reservoir, sf::RenderWindow &window);

//Function to convert from degrees to radians
double degtorad(double deg)
{
    double rad = (deg * PI) / 180.0;
    return rad;
}

int main(int argc, char const *argv[])
{
    //Set a offset for placing objects  
    float offsetX = 300;
    float offsetY = -40;

    //create the window
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

    //run the program as long as the window is open
    while (window.isOpen())
    {
        //check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            //"close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::SetNextItemWidth(100.0);

        /**********************************************************************
        *                            Setup green house
        ***********************************************************************/

        //setup greenhouse
        float sizegh{600};
        float posx = (windowLength - sizegh) / 2;
        float posy{100};
        sf::RectangleShape GreenhouseBack;
        sf::Texture gh;
        gh.loadFromFile("images/drivhusBagerst.png");
        GreenhouseBack.setSize({sizegh, sizegh});
        GreenhouseBack.setPosition({posx - offsetX, posy - offsetY});
        GreenhouseBack.setTexture(&gh);

        //setup greenhouse Front
        sf::RectangleShape GreenhouseFront;
        sf::Texture ghf;
        ghf.loadFromFile("images/drivhusForrest.png");
        GreenhouseFront.setSize({sizegh, sizegh});
        GreenhouseFront.setPosition({posx - offsetX, posy - offsetY});
        GreenhouseFront.setTexture(&ghf);

        //clear the window with black color
        window.clear(sf::Color::Transparent);
        //window.draw(background);
        window.draw(GreenhouseBack);

        /**********************************************************************
        *                             Interface
        ***********************************************************************/

        //Creates a slider for amount of days 
        if (ImGui::SliderInt("Days to grow", &days, 0., 10.))
        {
        }
        /*
        When the button is pushed, the program will go through 
        all elements in the "greenhouse" vector,
        and runs the grow command based on the slider
        */
        if (ImGui::Button("GROW THANKS", {200.0, 20.0}))
        {
            for (size_t i = 0; i < greenhouse.size(); i++)
                greenhouse[i]->grow(days, water_reservoir);
        }

        //Creates a button, that when pressed, fills up the water in the resovoir
        if (ImGui::Button("Fill up Water", {200.0, 20.0}))
        {
            water_reservoir.FillUp('w', 100);
        }

        //When the button is pressed, the nutrition in the resovoir fills up
        if (ImGui::Button("Fill up Nutrition", {200.0, 20.0}))
        {
            water_reservoir.FillUp('n', 100);
        }
        
        //Experimental button, for when the plants has to grow down
        if (ImGui::Button("Grow Down[Experimental]", {200.0, 20.0}))
        {
            for (size_t i = 0; i < greenhouse.size(); i++)
                greenhouse[i]->grow(-days, water_reservoir);
        }

        /*
        If the left mouse button is clicked, run the harvest function
        (only implemented in Tomato class) */
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i a = sf::Mouse::getPosition(window);
            for (auto &i : greenhouse)
            {
                i->harvest((int)a.x, (int)a.y);
            }
        }

        /**********************************************************************
        *                              Graphics
        * *********************************************************************/
        
        sf::Vector2u pos{1000, 50};
        dataWindow(pos, water_reservoir, window);
        /*
        Takes the elements in the greenhouse vector
        which contains all the different plants, and runs the
        draw function, that will render the plants to the greenhouse
        */
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

//Initializing the function dataWindow
void dataWindow(sf::Vector2u pos, WaterReservoir &reservoir, sf::RenderWindow &window)
{
    //Draw a square/border around the data window
    sf::Vector2f posFloat{(float)pos.x, (float)pos.y};
    sf::RectangleShape rect;
    rect.setSize({200.0F, 300.0F});
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(5.0F);
    rect.setPosition(posFloat);
    window.draw(rect);

    //Draw "levels" text in data window
    sf::Font font;
    font.loadFromFile("fonts/arial_narrow_7.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
    text.setString("Levels");
    text.setPosition(pos.x + 70, pos.y + 10);
    window.draw(text);

    //Draw level indicators and letter
    const std::vector<char> letters = {'W', 'K', 'P', 'N'};
    for (int i = 0; i < letters.size(); i++)
    {
        //Set offset from left side of datawindow
        int offset = 45;
        //Set spacing between level indicators
        int spacing = 40;

        //Draw letter
        text.setString(letters[i]);
        text.setPosition(pos.x + offset + (spacing * i) - text.getLocalBounds().width, pos.y + 70);
        window.draw(text);

        //Draw outer shape of level indicator
        sf::RectangleShape outerShape;
        outerShape.setSize({21.0F, 153.0F});
        outerShape.setPosition(pos.x + offset + (spacing * i) - text.getLocalBounds().width / 2 - outerShape.getGlobalBounds().width / 2, pos.y + 110);
        window.draw(outerShape);

        //Draw inner shape of level indicator
        sf::RectangleShape innerShape;
        innerShape.setFillColor(sf::Color::Blue);
        innerShape.setSize({15.0F, 147.0F * ((float)reservoir.getNutrition(letters[i])) / 100.0F});
        innerShape.setPosition(pos.x + offset + (spacing * i) - text.getLocalBounds().width / 2 - innerShape.getGlobalBounds().width / 2, pos.y + 113 + 147 - innerShape.getGlobalBounds().height);
        window.draw(innerShape);
    }
}