#include "fruit.h"
Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}

void Fruit::grow_fruit(int days, WaterReservoir reservoir)
{
    //Only grow fruit if phosphor is over 30.
    if ((reservoir.getPhosphor() > 30) && (growth_pct < 91))
        growth_pct = growth_pct + days * 10;

    if (growth_pct > 100)
        growth_pct = 100;
}