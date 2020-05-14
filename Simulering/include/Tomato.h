#pragma once
#include "plant_base.h"
#include "water_reservoir.h"
#include <fruit.h>
#include <vector>
#include <math.h>

class Tomato : public PlantBase
{
private:
    float height = 0.0;

    double num_tomatoes = 0.0;
    double growth_rate = 5.0;
    float lengthBranch = 20.0;
    sf::Texture texture;
    std::vector<Fruit> plant_fruit;

public:
    void add_fruit();
    void harvest(int x, int y) override;
    double getHeight() override { return height; };
    double getNumOfFruits() override;
    void grow(int days, WaterReservoir &Reservoir) override;
    void draw(sf::RenderWindow &window) override;
    
    //Function that return the shape of the fruit
    sf::CircleShape fruit(sf::Vector2f offset, Fruit &fruit);
    //Function that return the shape of the branch
    sf::RectangleShape branch(sf::Vector2f offset, int rotation);

    Tomato(float, float);
};
