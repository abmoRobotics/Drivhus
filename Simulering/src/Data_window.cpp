#include "plant_base.h"

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