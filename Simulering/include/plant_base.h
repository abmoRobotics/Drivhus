#pragma once
#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include "water_reservoir.h"

#define PI 3.14159265

class PlantBase : public sf::RectangleShape
{
private:
    /* data */
public:
    virtual double getHeight() = 0;
    virtual double getNumOfFruits() = 0;
    virtual void grow(int days, WaterReservoir &Reservoir) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual void harvest(int x, int y) = 0;
    double degtorade(double deg){return (deg * PI) / 180.0;};
    void graphics();
};
