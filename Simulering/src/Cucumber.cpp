#include <Cucumber.h>
#include <vector>

//This function is called when a day passes
void Cucumber::grow(int days, WaterReservoir &Reservoir)
{
    //Set the height of the cucumber plant 
    if (height < 250)
    {
        height = height + (days * (float)growth_rate * (float)Reservoir.getNutrition());
        Reservoir.NutritionConsumption(days);
        setSize({5.0, height});
    }
    
    //add a fruit for every 50
    if (plant_fruit.size() < ((int)height / 50))
    {
        Fruit t;
        plant_fruit.push_back(t);
    }

    //grow fruit if enough nutrition is present
    for (auto &a_fruit : plant_fruit)
    {
        a_fruit.grow_fruit(days, Reservoir);
    }
}

//Shape of the fruits on the cucumber plant
sf::CircleShape Cucumber::fruit(sf::Vector2f offset, Fruit &fruit)
{
    sf::CircleShape fruit_graphics(fruit.get_size());
    fruit_graphics.setScale(1, 3);
    fruit_graphics.setFillColor(sf::Color({32, 64, 32}));

    sf::Vector2f fruitOffset;
    fruitOffset.y = -(fruit_graphics.getRadius() * 2);

    fruit_graphics.setPosition(this->getPosition() + offset + fruitOffset);
    texture.loadFromFile("images/agurk.png");
    fruit_graphics.setTexture(&texture);
    num_cucumber += 1;
    return fruit_graphics;
}

//Shape of the branches on the cucumber plant
sf::RectangleShape Cucumber::branch(sf::Vector2f offset, int rotation)
{
    sf::RectangleShape branch({5.0, lengthBranch});
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
    for (size_t i = 0; i < plant_fruit.size(); i ++)
    {

        //Branch offset from the base of the plant
        sf::Vector2f branchOffset = sf::Vector2f{0.0, -(float)i*50};
        //Fruit offset from the base of the plant.
        sf::Vector2f fruitOffset;
        int rotatation;
        //Set fruit paremeters depending on drawdirection(Left or right fruit)
        if (draw_direction == false)
        {
            fruitOffset = sf::Vector2f{(float)cos(degtorade(45)) * (float)lengthBranch - 5, -(float)sin(degtorade(45)) * lengthBranch - ((float)i * 50) + 5};
            rotatation = -135;
            sf::CircleShape frutti = fruit(fruitOffset, plant_fruit[i]);
            fruitOffset.x = fruitOffset.x - (frutti.getRadius());
        }
        else
        {
            fruitOffset = sf::Vector2f{(float)-cos(degtorade(45)) * (float)lengthBranch + 0, -(float)sin(degtorade(45)) * lengthBranch - ((float)i * 50) + 5};
            rotatation = 135;
            sf::CircleShape frutti = fruit(fruitOffset, plant_fruit[i]);
            fruitOffset.x = fruitOffset.x - (frutti.getRadius());
        }
        sf::CircleShape frutti = fruit(fruitOffset, plant_fruit[i]);
        //Invert direction
        draw_direction = !draw_direction;
        //Draw fruits on the cucumber plant.
        window.draw(branch(branchOffset, rotatation));
        window.draw(frutti);
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
    //Define a starting height of the plant
    height = 50.0;
    //Place a fruit every X centimeter
     for (size_t i = 0; i < ((int)height / 30); i++)
    {
        Fruit fruit;
        plant_fruit.push_back(fruit);
    }
    //Set the size of the stalk
    setSize({5.0, height});
    //Set the color of the stalk
    setFillColor(sf::Color({82, 136, 84}));
    //Set the rotation of the stalk.
    setRotation(180);
}

void Cucumber::harvest(int x, int y) {}