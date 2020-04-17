#include "plant_base.h"


void dataWindow(sf::Vector2u pos, WaterReservoir &reservoir, sf::RenderWindow &window){
            
        sf::Font font;
        font.loadFromFile("arial_narrow_7.ttf");

        sf::Text text;
        text.setFont(font);
        text.setString("Water");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        text.setPosition(1100,0);
        window.draw(text);


}