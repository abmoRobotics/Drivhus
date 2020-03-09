#include <klasser.h>


double Tomat::getVand(){
    return this->vand;
}

void Tomat::setVand(double v){
    this->vand = v;
}

int blinkWidget::getBlink(){
    return blinks;
}
void blinkWidget::setBlink(int i){
    blinks = blinks + i;
}

/*
void setBlink();
int getBlink();
*/