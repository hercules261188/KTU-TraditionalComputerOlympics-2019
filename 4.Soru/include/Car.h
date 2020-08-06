#ifndef CAR_H
#define CAR_H

#include <iostream>

using namespace std;

class Car
{
    private:
        char color;
        int placeX;
        int placeY;
        char direction;
    public:
        Car(char color, int placeX, int placeY);
        int getPlaceX();
        void setPlaceX(int placeX);
        int getPlaceY();
        void setPlaceY(int placeY);
        char getColor();
        char getDirection();
        void setDirectionToNorth();
        void move();
};


#endif