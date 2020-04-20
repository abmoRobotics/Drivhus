#include <water_reservoir.h>

double WaterReservoir::getNutrition()
{
    if (Water > 10 && Nitrogen > 10 && Kalium > 10)
    {
        return 1;
    }
    else
    {
        return (Water * Nitrogen * Kalium) / 100000;
    }

    nutrition_growth_rate = (Water * Nitrogen * Kalium) / 1000;
    return nutrition_growth_rate;
};

double WaterReservoir::getNutrition(char returnvalue)
{
    switch (returnvalue)
    {
    case 'N':
        return Nitrogen;
        break;
    case 'P':
        return Phosphor;
        break;
    case 'K':
        return Kalium;
        break;
    case 'W':
        return Water;
        break;
    default:
        return nutrition_growth_rate;
        break;
    }
};

void WaterReservoir::NutritionConsumption(int days)
{
    if (Nitrogen - 0.25 * days > 0)
    {
        Nitrogen = Nitrogen - 0.25 * days;
    }
    else
    {
        Nitrogen = 0;
    }

    if (Phosphor - 0.5 * days > 0)
    {
        Phosphor = Phosphor - 0.5 * days;
    }
    else
    {
        Phosphor = 0;
    }

    if (Kalium - 0.3 * days > 0)
    {
        Kalium = Kalium - 0.4 * days;
    }
    else
    {
        Kalium = 0;
    }

    if (Water - 0.4 * days > 0)
    {
        Water = Water - 0.4 * days;
    }
    else
    {
        Water = 0;
    }
};

void WaterReservoir::FillUp(char choise, double level)
{
    switch (choise)
    {
    case 'w':
        if (level > 100)
        {
            Water = 100;
        }
        else
        {
            Water = level;
        }

        break;
    case 'n':
        if (level > 100)
        {
            Nitrogen = 100;
            Phosphor = 100;
            Kalium = 100;
        }
        else
        {
            Nitrogen = level;
            Phosphor = level;
            Kalium = level;
        }
        break;
    }
};
