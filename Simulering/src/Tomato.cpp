#include <Tomato.h>


//This function is called when a day passes
void Tomato::grow(int days, WaterReservoir &Reservoir)
{
    //Grow if not higher than 250;
    if (height < 250)
    {
        height = height + (days * (float)growth_rate * (float)Reservoir.getNutrition());
        Reservoir.NutritionConsumption(days);
        setSize({5.0, height});
    }

    //add a fruit for every 30
    if (plant_fruit.size() < ((int)height / 30))
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

//Shape of the fruits on the tomato plant
sf::CircleShape Tomato::fruit(sf::Vector2f offset, Fruit &fruit)
{
    //Define the shape of the figure
    sf::CircleShape fruit_graphics(fruit.get_size());
    fruit_graphics.setFillColor(sf::Color({240, 64, 32}));

    //Offset to make sure that the tomato is centered 
    sf::Vector2f fruitOffset;
    fruitOffset.y = -(fruit_graphics.getRadius() * 2);
    sf::Vector2f fruitPos = this->getPosition() + offset + fruitOffset;
    fruit_graphics.setPosition(fruitPos);

    //Set the x position and y position of the fruit in the object
    fruit.set_xPos(fruitPos.x);
    fruit.set_yPos(fruitPos.y);

    //Load tomato texture
    texture.loadFromFile("images/tomat.png");
    fruit_graphics.setTexture(&texture);
    num_tomatoes = num_tomatoes + 1.0;
    return fruit_graphics;
}

//Shape of the branches on the tomato plant
sf::RectangleShape Tomato::branch(sf::Vector2f offset, int rotation)
{
    sf::RectangleShape branch({3.0, lengthBranch});
    branch.setFillColor(sf::Color({82, 136, 84}));
    branch.setPosition(this->getPosition() + offset);
    branch.setRotation(rotation);
    return branch;
}

//Positions of the fruits and branches are determined with this function,
//Fruits and branches are also drawn.
void Tomato::draw(sf::RenderWindow &window)
{
    //Draw the rectangle respresenting the stalk of the tomato
    window.draw(*this);
    //Direction to draw branch: false = left, true = right
    bool draw_direction = false;
    //For loop respresenting the growth of a tomato "fruit" every 50 centimeters.
    for (size_t i = 0; i < plant_fruit.size(); i++)
    {
        //Branch offset from the base of the plant_fruit
        sf::Vector2f branchOffset = sf::Vector2f{0.0, -(float)i * 30};
        //Fruit offset from the base of the plant_fruit.
        sf::Vector2f fruitOffset;
        int rotatation;
        //Set fruit paremeters depending on drawdirection(Left or right fruit)
        if (draw_direction == false)
        {
            fruitOffset = sf::Vector2f{(float)cos(degtorade(45)) * (float)lengthBranch - 5, -(float)sin(degtorade(45)) * lengthBranch - ((float)i * 30) + 5};
            rotatation = -135;
        }
        else
        {
            fruitOffset = sf::Vector2f{(float)-cos(degtorade(45)) * (float)lengthBranch + 5, -(float)sin(degtorade(45)) * lengthBranch - ((float)i * 30) + 5};
            rotatation = 135;
            //Offset to make sure that the tomato is centered (when size increases)
            sf::CircleShape fruit_graphics = fruit(fruitOffset, plant_fruit[i]);
            fruitOffset.x = fruitOffset.x - (fruit_graphics.getRadius() * 2);
        }
        //Define the fruit graphics again, but now it is centered depending on its size.
        sf::CircleShape fruit_graphics = fruit(fruitOffset, plant_fruit[i]);
        //Invert direction
        draw_direction = !draw_direction;
        //Draw branches on the tomato plant.
        window.draw(branch(branchOffset, rotatation));
        //Draw fruits on the tomato plant.
        window.draw(fruit_graphics);
    }
}

double Tomato::getNumOfFruits()
{
    num_tomatoes = ((int)height / 50) + 1;
    return num_tomatoes;
}

Tomato::Tomato(float x, float y)
{
    setPosition(sf::Vector2f{x, y});
    //Define a starting height of the plant
    height = 98.0;
    //Place a fruit every X centimeter
    for (size_t i = 0; i < ((int)height / 50); i++)
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

template <typename T>
bool IsInBounds(const T &value, const T &low, const T &high)
{
    return !(value < low) && (value < high);
}
void Tomato::harvest(int x, int y)
{
    for (auto &i : plant_fruit)
    {
        if (IsInBounds(x, i.get_xPos(), i.get_xPos() + i.get_size() * 2) && IsInBounds(y, i.get_yPos(), i.get_yPos() + i.get_size() * 2))
        {
            i.set_growth_pct(0);
        }
    }
}