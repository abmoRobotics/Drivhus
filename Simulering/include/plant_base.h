#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include <thread>
#include <chrono>
class PlantBase
{
private:
    /* data */
public:
   virtual double getHeight() = 0;
   virtual void grow(int days) = 0;
   virtual void simulateday(int days) = 0;
};