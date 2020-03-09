#pragma once
#include <Arduino.h>

class Tomat{
private:
    double vand;
    double alder;
public:
    void setVand(double);
    double getVand();

};

class benchModule{
private:
    double fugtighed;

public:
};

class blinkWidget{
private:
    int blinks = 0;
public:
    void setBlink(int);
    int getBlink();
};