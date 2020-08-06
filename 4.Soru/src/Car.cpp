#include "Car.h"

Car::Car(char color, int placeX, int placeY)
{
    this->color = color;
    this->placeX = placeX;
    this->placeY = placeY;
    if(placeX < 0){
        this->direction = 'E';  // East
    }
    else if(placeX > 0){
        this->direction = 'W';  // West
    }
    else{
        this->direction = 'N';  // North
    }
}

int Car::getPlaceX(){
    return this->placeX;
}

void Car::setPlaceX(int placeX){
    this->placeX = placeX;
    if(this->placeX == 0){
        this->setDirectionToNorth();
    }
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

char Car::getDirection(){
    return this->direction;
}

void Car::setDirectionToNorth(){
    this->direction = 'N';
}

void Car::move(){
    if(this->direction == 'E'){
        this->setPlaceX(this->placeX + 1);
        
    }
    else if(this->direction == 'W'){
        this->setPlaceX(this->placeX - 1);
    }
    else{
        this->placeY++;
    }
    
}