#include "Car.h"

Car::Car(char color, int placeX, int placeY)
{
    this->color = color;
    this->placeX = placeX;
    this->placeY = placeY;
    this->firstPlacedY = false;
}

int Car::getPlaceX(){
    return this->placeX;
}

void Car::setPlaceX(int placeX){
    this->placeX = placeX;
}

int Car::getPlaceY(){
    return this->placeY;
}

void Car::setPlaceY(int placeY){
    this->placeY = placeY;
}

char Car::getColor(){
    return this->color;
}

void Car::setFirstPlacedY(bool firstPlacedY){
    this->firstPlacedY = firstPlacedY;
}

bool Car::getFirstPlacedY(){
    return this->firstPlacedY;
}