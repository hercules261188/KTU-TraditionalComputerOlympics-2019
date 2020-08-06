#include "Convoy.h"

Convoy::Convoy(vector<Car> cars)
{
    this->cars = cars;
    
}

vector<Car> Convoy::getCars(){
    return this->cars;
}