#pragma once
#include "cucumber_plant.h"
#include "tomato_plant.h"
class Graphics
{
private:
    /* data */
    std::vector<std::shared_ptr<PlantBase>> greenhouse;
    sf::RenderWindow window;

    void standardGraphics();
    void customGraphics();
public:
    Graphics();
    ~Graphics();
};

