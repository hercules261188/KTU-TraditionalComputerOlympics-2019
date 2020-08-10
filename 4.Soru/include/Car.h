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
        bool firstPlacedY;
    public:
        Car(char color, int placeX, int placeY);
        int getPlaceX();
        void setPlaceX(int placeX);
        int getPlaceY();
        void setPlaceY(int placeY);
        char getColor();
        void setFirstPlacedY(bool firstPlacedY);
        bool getFirstPlacedY();
};


#endif