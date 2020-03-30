#pragma once
#include "WaterControl.h"
#include "Tomato.h"
#include <vector>



class Controller
{
private:
    /* has 2 sections */
    std::vector<PlantBase> sections;
public:
    Controller(/* args */);
    ~Controller();
};



Controller::Controller(/* args */)
{
}

Controller::~Controller()
{
}
