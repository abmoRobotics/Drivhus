#pragma once
#include "plant_base.h"
#include "water_reservoir.h"



class Cucumber : public PlantBase
{
private:
    float height = 0.0;
    double num_cucumber = 0.0;
    double growth_rate = 5;
    sf::Texture texture;
public:
   double getHeight() override {return height;};
   double getNumOfFruits() override;
   void grow(int days, WaterReservoir &Reservoir) override;
   void draw(sf::RenderWindow &window) override;  

   //Function that return the shape of the fruit
   sf::CircleShape fruit(sf::Vector2f offset) ;
   //Function that return the shape of the branch
   sf::RectangleShape branch(sf::Vector2f offset,int rotation) ;
   
    //Constructor
    Cucumber(float,float);
};

