#include <Cucumber.h>
#include <vector>

void Cucumber::grow(int days, WaterReservoir &Reservoir)
{
    if (height < 250)
    {
        height = height + (days * (float)growth_rate * (float)Reservoir.getNutrition());
        Reservoir.NutritionConsumption(days);
        setSize({5.0, height});
    }
}

//Shape of the fruits on the cucumber plant
sf::CircleShape Cucumber::fruit(sf::Vector2f offset)
{
    sf::CircleShape fruit(13.0);
    fruit.setScale(1, 3);
    fruit.setFillColor(sf::Color({32, 64, 32}));
    fruit.setPosition(this->getPosition() + offset);
    texture.loadFromFile("../images/agurk.png");
    fruit.setTexture(&texture);
    num_cucumber += 1;
    return fruit;
}

//Shape of the branches on the cucumber plant
sf::RectangleShape Cucumber::branch(sf::Vector2f offset, int rotation)
{
    sf::RectangleShape branch({5.0, 50});
    branch.setFillColor(sf::Color({82, 136, 84}));
    branch.setPosition(this->getPosition() + offset);
    branch.setRotation(rotation);
    return branch;
}

/**
 * Positions of the fruits and branches are determined and drawn with this function.
 * @param window Window which the fruits are drawn on.
 */
void Cucumber::draw(sf::RenderWindow &window)
{
    //Draw the rectangle respresenting the stalk of the tomato
    window.draw(*this);
    //Direction to draw branch: false = left, true = right
    bool draw_direction = false;
    //For loop respresenting the growth of a tomato "fruit" every 50 centimeters.
    for (size_t i = 0; i < height; i += 50)
    {

        //Branch offset from the base of the plant
        sf::Vector2f branchOffset = sf::Vector2f{0.0, -(float)i};
        //Fruit offset from the base of the plant.
        sf::Vector2f fruitOffset;
        int rotatation;

        if (draw_direction == false)
        {
            fruitOffset = sf::Vector2f{18.0, -45 - (float)i};
            rotatation = -135;
        }
        else
        {
            fruitOffset = sf::Vector2f{18.0 - 56, -45 - (float)i};
            rotatation = 135;
        }
        //Invert direction
        draw_direction = !draw_direction;
        //Draw fruits on the tomato plant.
        window.draw(branch(branchOffset, rotatation));
        window.draw(fruit(fruitOffset));
    }
}

double Cucumber::getNumOfFruits()
{
    num_cucumber = ((int)height / 50) + 1;
    return num_cucumber;
}
Cucumber::Cucumber(float x, float y)
{
    setPosition(sf::Vector2f{x, y});
    height = 50.0;
    setSize({5.0, height});
    setFillColor(sf::Color({82, 136, 84}));
    setRotation(180);
}

void Cucumber::harvest(int x, int y) {}