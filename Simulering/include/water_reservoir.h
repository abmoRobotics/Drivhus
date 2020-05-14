#pragma once

class WaterReservoir
{
public:
    double getNutrition();
    double getPhosphor() { return Phosphor; };
    double getNutrition(char returnvalue);
    void NutritionConsumption(int days);
    void FillUp(char choise, double level);

private:
    double Nitrogen{100};
    double Phosphor{70};
    double Kalium{100};
    double Water{70};
    double nutrition_growth_rate = 0;
};