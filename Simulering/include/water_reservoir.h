#pragma once

class WaterReservoir
{
public:
    double getNutrition();
    double getNutrition(char returnvalue);
    void NutritionConsumption(int days);
    void FillUp(char choise, double level);

private:
    double Nitrogen{100};
    double Phosphor{100};
    double Kalium{100};
    double Water{100};
    double nutrition_growth_rate = 0;
};