#include <Tomato.h>
#include <vector>
#include <math.h>

#define PI 3.14159265

double degtorade(double deg){
    double rad =  (deg * PI) / 180.0 ;
    return rad;
}

void Tomato::grow(int days, WaterReservoir &Reservoir){
    height = height + ( days * (float)growth_rate * (float)Reservoir.getNutrition() );
    Reservoir.NutritionConsumption(days);    
    setSize({5.0,height});
}

//Shape of the fruits on the tomato plant
sf::CircleShape Tomato::fruit(sf::Vector2f offset){
    sf::CircleShape fruit(10.0);
    fruit.setFillColor(sf::Color({240,64,32}));
    sf::Vector2f fruitOffset;
    fruitOffset.y = -(fruit.getRadius()*2);
    fruit.setPosition(this->getPosition()+offset+fruitOffset);
    texture.loadFromFile("tomat.png");
    fruit.setTexture(&texture);
    num_tomatoes = num_tomatoes + 1.0;
    return fruit;
}

//Shape of the branches on the tomato plant
sf::RectangleShape Tomato::branch(sf::Vector2f offset,int rotation){
   sf::RectangleShape branch({3.0,lengthBranch});
   branch.setFillColor(sf::Color({82, 136, 84}));
   branch.setPosition(this->getPosition()+offset);
   branch.setRotation(rotation);
   return branch;
}

//Positions of the fruits and branches are determined with this function,
//Fruits and branches are also drawn.
void Tomato::draw(sf::RenderWindow &window){
    //Draw the rectangle respresenting the stalk of the tomato
    window.draw(*this);
    //Direction to draw branch: false = left, true = right
    bool draw_direction = false;
    //For loop respresenting the growth of a tomato "fruit" every 50 centimeters.
    for (size_t i = 0; i < height; i+=30)
    {
        //Branch offset from the base of the plant
        sf::Vector2f branchOffset = sf::Vector2f{0.0, -(float)i};
        //Fruit offset from the base of the plant.
        sf::Vector2f fruitOffset;
        int rotatation;
        

        if (draw_direction == false){
            fruitOffset= sf::Vector2f{(float)cos(degtorade(45))*(float)lengthBranch-5,-(float)sin(degtorade(45))*lengthBranch-(float)i+5};
            rotatation = -135;
        } else{
            fruitOffset = sf::Vector2f{(float)-cos(degtorade(45))*(float)lengthBranch+5,-(float)sin(degtorade(45))*lengthBranch-(float)i+5};
            rotatation = 135;
            sf::CircleShape frutti = fruit(fruitOffset);
            fruitOffset.x = fruitOffset.x-(frutti.getRadius()*2);
        }
        sf::CircleShape frutti = fruit(fruitOffset);
        //Invert direction
        draw_direction = !draw_direction;
        //Draw branches on the tomato plant.
        window.draw( branch( branchOffset , rotatation ) );
        //Draw fruits on the tomato plant.
        window.draw(frutti);
    }
    

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