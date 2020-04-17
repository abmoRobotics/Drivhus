#pragma once
#include "Cucumber.h"
#include "Tomato.h"
#include "Melon.h"
#include "water_reservoir.h"
class Graphics
{
private:
    /* data */
    std::vector<std::shared_ptr<PlantBase>> greenhouse;
    sf::RenderWindow window;
    WaterReservoir Reservoir;

    void standardGraphics();
    void customGraphics();
public:
    Graphics();
    ~Graphics();
};

