#pragma once
#include "water_reservoir.h"

class Fruit
{
private:
    int max_size = 10;
    int growth_rate = 10;
    int growth_pct = 0;
    int xPos;
    int yPos;

public:
    void grow_fruit(int days, WaterReservoir reservoir);
    void set_xPos(int x) { xPos = x; }
    void set_yPos(int y) { yPos = y; }
    int get_xPos() { return xPos; }
    int get_yPos() { return yPos; }
    int get_growth_pct() { return growth_pct; }
    int get_size() { return max_size * growth_pct * 0.01; }
    void set_growth_pct(int pct) { growth_pct = pct; };
    Fruit(/* args */);
    ~Fruit();
};
