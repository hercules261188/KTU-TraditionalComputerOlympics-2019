#ifndef CONVOY_H
#define CONVOY_H

#include "Car.h"
#include <vector>

class Convoy
{
    private:
        vector<Car> cars;
    public:
        Convoy(vector<Car> cars);
        vector<Car> getCars();
};


#endif