#pragma once
#include "plant_base.h"



class Cucumber : public PlantBase
{
private:
    float height = 0.0;
    double num_cucumber = 0.0;
    double growth_rate = 5;
public:
   double getHeight() override {return height;};
   double getNumOfFruits() override;
   void grow(int days) override;

   //Function that return the shape of the fruit
   sf::CircleShape fruit(sf::Vector2f offset) override;
   //Function that return the shape of the branch
   sf::RectangleShape branch(int rotation, sf::Vector2f offset) override;
    //Constructor
    Cucumber(float,float);
};

