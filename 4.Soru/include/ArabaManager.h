#ifndef ARABAMANAGER_H
#define ARABAMANAGER_H

#include "Araba.h"

class ArabaManager
{
    public:
        ArabaManager();
        void update();
        void setArabaArray(Araba* aArray);
        virtual ~ArabaManager();
        bool bosMu(int x,int y);

    protected:

    private:
        Araba* arabaArray;
        int arabaSayisi;
};

#endif // ARABAMANAGER_H
