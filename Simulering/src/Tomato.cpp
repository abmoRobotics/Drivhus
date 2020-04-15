#include <tomato_plant.h>
#include <vector>


void Tomato::grow(int days){
    height = height + ( days * growth_rate );

}

void Tomato::simulateday(int days){
    for (size_t i = 0; i < days; i++)
    {
        grow(1);
        setSize({5.0,height});
        //fruit();
    }
    
}


    
    
    

Tomato::Tomato(){
    height=98.0;
    setSize({5.0,height});
    setFillColor(sf::Color(0,255,0));
}