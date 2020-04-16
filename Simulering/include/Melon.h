#pragma once
#include "plant_base.h"



class Melon : public PlantBase
{
private:
    float radiusMelon = 0.0;
    float heightStalk = 0.0;
    float lengthBranch = 0.0;
    double num_Melon = 0.0;
    double growth_rate = 1.0;
public:
   double getHeight() override {return radiusMelon;};
   double getNumOfFruits() override;
   void grow(int days) override;
   void draw(sf::RenderWindow &window) override;
   sf::CircleShape fruit(sf::Vector2f offset) ;
   std::vector<sf::RectangleShape> branch(sf::Vector2f offset, int rotation) ;

    Melon(float,float);
};
