#include <cucumber_plant.h>
#include <vector>


void Cucumber::grow(int days){
    height = height + ( days * growth_rate );
    setSize({5.0,height});
}

sf::CircleShape Cucumber::fruit(sf::Vector2f offset){
    sf::CircleShape fruit(10.0);
    fruit.setScale(1,3);
    fruit.setFillColor(sf::Color({32,64,32}));
    fruit.setPosition(this->getPosition()+offset);
    num_cucumber += 1;
    return fruit;
}

sf::RectangleShape Cucumber::branch(int rotation, sf::Vector2f offset){
   sf::RectangleShape branch({5.0,50});
   branch.setFillColor(sf::Color({82, 136, 84}));
   branch.setPosition(this->getPosition()+offset);
   branch.setRotation(rotation);
   return branch;
}

double Cucumber::getNumOfFruits(){
    num_cucumber =( (int)height / 50 ) + 1;
    return num_cucumber; 
}
Cucumber::Cucumber(float x, float y){
    setPosition(sf::Vector2f{x,y});    
    height=50.0;
    setSize({5.0,height});
    setFillColor(sf::Color({82, 136, 84}));
    setRotation(180);
}