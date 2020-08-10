#ifndef CONVOY_H
#define CONVOY_H

#include "Car.h"
#include <vector>

class Convoy
{
    private:
        vector<Car> cars;
        char direction;
        bool isMovable = true;
    public:
        Convoy();
        Convoy(vector<Car> cars);
        vector<Car> getCars();
        void setDirection(char direction);
        char getDirection();
        void move(Convoy* whichOnYDirection);
        void addCar(Car car);
        void sortCarsByPlaceY();
        void setIsMovable(bool isMovable);
        bool checkIsMovable(Convoy* convoyWhichOnYDirection);
};


#endif