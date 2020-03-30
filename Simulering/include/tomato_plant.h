#pragma once

#include "plant_base.h"



class Tomato : public PlantBase
{
private:
    double height = 0.0;
    double num_tomatoes = 0.0;
    double growth_rate = 2.0;
public:
   double getHeight() override {return height;};
   void grow(int days) override;

};

