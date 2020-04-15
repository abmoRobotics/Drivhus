#pragma once
#include "plant_base.h"



class Tomato : public PlantBase
{
private:
    float height = 0.0;
    double num_tomatoes = 0.0;
    double growth_rate = 10.0;
public:
   double getHeight() override {return height;};
   double getNumOfFruits() override;
   void grow(int days) override;
   sf::CircleShape fruit(sf::Vector2f offset) override;
   sf::RectangleShape branch(int rotation, sf::Vector2f offset) override;

    Tomato(float,float);
};

