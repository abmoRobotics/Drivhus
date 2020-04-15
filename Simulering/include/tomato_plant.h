#pragma once
#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include "plant_base.h"



class Tomato : public PlantBase, public sf::RectangleShape
{
private:
    float height = 0.0;
    double num_tomatoes = 0.0;
    double growth_rate = 10.0;
public:
   double getHeight() override {return height;};
   void grow(int days) override;
   void simulateday(int days) override;
   sf::CircleShape fruit();

    Tomato();
};

