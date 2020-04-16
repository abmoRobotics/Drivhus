#pragma once
#include "plant_base.h"



class Tomato : public PlantBase
{
private:
    float height = 0.0;
    double num_tomatoes = 0.0;
    double growth_rate = 10.0;
    sf::Texture texture;
public:
   double getHeight() override {return height;};
   double getNumOfFruits() override;
   void grow(int days) override;
   void draw(sf::RenderWindow &window) override;
   sf::CircleShape fruit(sf::Vector2f offset) ;
   sf::RectangleShape branch(sf::Vector2f offset, int rotation) ;

    Tomato(float,float);
};

