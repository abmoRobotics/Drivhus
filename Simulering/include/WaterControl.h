#pragma once

class WaterControl
{
private:
    double waterLevel;
    bool outletValve;
    void updateWaterlevel(){}/*UPDATE WATER LEVEL FROM SENSORS*/
public:
    void getWaterLevel(){};
    void openValve(){};
    void closeValve(){};
};

class MoistureControl
{
private:
    double moistureDirt;
    double moistureRequired = 20.0;
    void moistureSensorRead(){}; /*GET INPUT FROM MOISTURE SENSOR AND SAVE IN MOISTUREDIRT*/
public:
    bool checkMoisture(){};
};



