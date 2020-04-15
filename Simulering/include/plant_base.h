#pragma once
#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include <thread>
#include <chrono>
class PlantBase : public sf::RectangleShape
{
private:
    /* data */
public:
   virtual double getHeight() = 0;
   virtual double getNumOfFruits() = 0;
   virtual void grow(int days) = 0;
   virtual sf::CircleShape fruit(sf::Vector2f offset) = 0;
   virtual sf::RectangleShape branch(int rotation, sf::Vector2f offset) = 0;
};