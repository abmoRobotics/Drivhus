#pragma once
#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

class PlantBase : public sf::RectangleShape
{
private:
    /* data */
public:
   virtual double getHeight() = 0;
   virtual double getNumOfFruits() = 0;
   virtual void grow(int days) = 0;
   virtual void draw(sf::RenderWindow &window) = 0;
   void graphics();
};