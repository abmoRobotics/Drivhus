#include <tomato_plant.h>
#include <vector>


void Tomato::grow(int days){
    height = height + ( days * growth_rate );
    setSize({5.0,height});
}

sf::CircleShape Tomato::fruit(sf::Vector2f offset){
    sf::CircleShape fruit(10.0);
    fruit.setFillColor(sf::Color({240,64,32}));
    fruit.setPosition(this->getPosition()+offset);
    num_tomatoes = num_tomatoes +1.0;
    return fruit;
}

sf::RectangleShape Tomato::branch(int rotation, sf::Vector2f offset){
   sf::RectangleShape branch({5.0,50});
   branch.setFillColor(sf::Color({82, 136, 84}));
   branch.setPosition(this->getPosition()+offset);
   branch.setRotation(rotation);
   return branch;
}

double Tomato::getNumOfFruits(){
    num_tomatoes = ( (int)height / 50 ) + 1;
    return num_tomatoes; 
}
Tomato::Tomato(float x, float y){
    setPosition(sf::Vector2f{x,y});
    height=98.0;
    setSize({5.0,height});
    setFillColor(sf::Color({82, 136, 84}));
    setRotation(180);
}