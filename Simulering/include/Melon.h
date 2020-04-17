#pragma once
#include "plant_base.h"
#include "water_reservoir.h"



class Melon : public PlantBase
{
private:
    float radiusMelon = 0.0;
    float heightStalk = 0.0;
    float lengthBranch = 0.0;
    double num_Melon = 0.0;
    double growth_rate = 1.0;
    sf::Texture texture;
public:
   double getHeight() override {return radiusMelon;};
   double getNumOfFruits() override;
   void grow(int days, WaterReservoir &Reservoir) override;
   void draw(sf::RenderWindow &window) override;
   sf::CircleShape fruit(sf::Vector2f offset) ;
   std::vector<sf::RectangleShape> branch(sf::Vector2f offset, int rotation) ;

    Melon(float,float);
};

