#include <tomato_plant.h>
#include <vector>


void Tomato::grow(int days){
    height = height + ( days * growth_rate );
}