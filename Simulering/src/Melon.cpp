#include <Melon.h>
#include <vector>
#include <iostream>

void Melon::grow(int days, WaterReservoir &Reservoir)
{
    if (heightStalk < 75)
    {
        heightStalk = heightStalk + (days * (float)growth_rate * (float)Reservoir.getNutrition());
        lengthBranch = lengthBranch + (days * (float)growth_rate * (float)Reservoir.getNutrition());
        Reservoir.NutritionConsumption(days);
        setSize({5.0, heightStalk});
    }

    if (radiusMelon < heightStalk / 2)
    {
        radiusMelon = radiusMelon + (days * growth_rate);
    }
}

//Shape of the fruits on the Melon plant
sf::CircleShape Melon::fruit(sf::Vector2f offset)
{

    sf::CircleShape fruit(radiusMelon);
    //fruit.setFillColor(sf::Color({240, 64, 32}));
    fruit.setPosition(this->getPosition() + offset);
    texture.loadFromFile("melon.png");
    fruit.setTexture(&texture);
    num_Melon = num_Melon + 1.0;

    return fruit;
}

//Shape of the branches on the Melon plant
std::vector<sf::RectangleShape> Melon::branch(sf::Vector2f offset, int rotation)
{
    //gro vandret
    std::vector<sf::RectangleShape> branch;
    sf::RectangleShape branch1({5.0, lengthBranch});
    branch1.setFillColor(sf::Color({82, 136, 84}));
    branch1.setPosition(this->getPosition() + offset);
    branch1.setRotation(rotation);
    branch.push_back(branch1);

    //gro nedad
    sf::RectangleShape branch2({5.0, heightStalk - (radiusMelon * 2)});
    branch2.setFillColor(sf::Color({82, 136, 84}));
    branch2.setPosition(this->getPosition() + offset + sf::Vector2f(lengthBranch - 2.5F, 0));
    branch.push_back(branch2);

    return branch;
}

//Positions of the fruits and branches are determined with this function,
//Fruits and branches are also drawn.
void Melon::draw(sf::RenderWindow &window)
{
    //Draw the rectangle respresenting the stalk of the Melon
    window.draw(*this);
    //For loop respresenting the growth of a Melon "fruit" every 50 centimeters.

    //Branch offset from the base of the plant
    sf::Vector2f branchOffset = sf::Vector2f{0.0, -heightStalk};
    //Fruit offset from the base of the plant.
    sf::Vector2f fruitOffset = sf::Vector2f{lengthBranch - radiusMelon, -(radiusMelon * 2)};
    int rotatation = -90;

    //Draw fruits on the Melon plant.
    window.draw(fruit(fruitOffset));
    //window.draw(fruit(fruitOffset).setTexture());
    //Draw branches on the Melon plant.
    std::vector<sf::RectangleShape> drawBranch = branch(branchOffset, rotatation);

    window.draw(drawBranch[0]);
    window.draw(drawBranch[1]);
}

double Melon::getNumOfFruits()
{
    //num_Melon = ((int)height / 50) + 1;
    return 0;
}
Melon::Melon(float x, float y)
{
    setPosition(sf::Vector2f{x, y});
    radiusMelon = 10;
    heightStalk = 50;
    lengthBranch = 50;
    setSize({5.0, heightStalk});
    setFillColor(sf::Color({82, 136, 84}));
    setRotation(180);
}

void Melon::harvest(int x, int y) {}