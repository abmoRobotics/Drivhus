#pragma once
#include "plant_base.h"
#include "water_reservoir.h"
#include <fruit.h>
#include <vector>

class Cucumber : public PlantBase
{
private:
    float height = 0.0;
    double num_cucumber = 0.0;
    double growth_rate = 5;
    float lengthBranch = 50.0;
    sf::Texture texture;
    std::vector<Fruit> plant_fruit;


public:
    double getHeight() override { return height; };
    double getNumOfFruits() override;
    void grow(int days, WaterReservoir &Reservoir) override;
    void draw(sf::RenderWindow &window) override;

    //Function that return the shape of the fruit
    sf::CircleShape fruit(sf::Vector2f offset, Fruit &fruit);
    //Function that return the shape of the branch
    sf::RectangleShape branch(sf::Vector2f offset, int rotation);

    //Constructor
    Cucumber(float, float);
    void harvest(int x, int y) override;
};
