#include "Convoy.h"
Convoy::Convoy(){
    this->direction = 'N';
}

Convoy::Convoy(vector<Car> cars)
{
    this->cars = cars;
    if(cars.front().getPlaceX() > 0){
        this->direction = 'W';
    }
    else{
        this->direction = 'E';
    }
}

vector<Car> Convoy::getCars(){
    return this->cars;
}

void Convoy::setDirection(char direction){
    this->direction = direction;
}

char Convoy::getDirection(){
    return this->direction;
}

void Convoy::addCar(Car car){
    this->cars.push_back(car);
}

void Convoy::setIsMovable(bool isMovable){
    this->isMovable = isMovable;
}

bool Convoy::checkIsMovable(Convoy* convoyWhichOnYDirection){
    if(convoyWhichOnYDirection->getCars().size() == 0){
        this->isMovable = true;
    }
    else{
        if(this->getCars().front().getPlaceX() + 1 == 0 || this->getCars().front().getPlaceX() - 1 == 0){
            this->isMovable = true;
            for(int i = 0; i < convoyWhichOnYDirection->getCars().size(); i++){
                if(convoyWhichOnYDirection->getCars().at(i).getPlaceY() + 1 == this->getCars().front().getPlaceY()){
                    this->isMovable = false;
                    break;
                }
            }
        }
        else{
            this->isMovable = true;
        }
    }
    return this->isMovable;
}

void Convoy::move(Convoy* whichOnYDirection){
    if(this->direction == 'N'){
        for(int i = 0; i < this->cars.size(); i++){
            if(!this->cars.at(i).getFirstPlacedY()){
                int placeY = this->cars.at(i).getPlaceY();
                this->cars.at(i).setPlaceY(placeY + 1);
            }
            else{
                this->cars.at(i).setFirstPlacedY(false);
            }
        }
    }
    else if(this->direction == 'W'){
        for(int i = 0; i < this->cars.size(); i++){
            int placeX = this->cars.at(i).getPlaceX();
            this->cars.at(i).setPlaceX(placeX - 1);
        }
        if(this->cars.front().getPlaceX() == 0){
            this->cars.front().setFirstPlacedY(true);
            whichOnYDirection->addCar(this->cars.front());
            this->cars.erase(this->cars.begin());
        }
    }
    else{
        for(int i = 0; i < this->cars.size(); i++){
            int placeX = this->cars.at(i).getPlaceX();
            this->cars.at(i).setPlaceX(placeX + 1);
        }
        if(this->cars.front().getPlaceX() == 0){
            this->cars.front().setFirstPlacedY(true);
            whichOnYDirection->addCar(this->cars.front());
            this->cars.erase(this->cars.begin());
        }
    }
}

void Convoy::sortCarsByPlaceY(){

    for(int i = 0; i < this->getCars().size() - 1; i++){
        for(int j = i + 1; j < this->getCars().size(); j++){
            if(this->getCars().at(i).getPlaceY() < this->getCars().at(j).getPlaceY()){
                Car temp = this->getCars().at(i);
                this->cars[i] = this->getCars().at(j);
                this->cars[j] = temp;
            }
        }
    }
    
}