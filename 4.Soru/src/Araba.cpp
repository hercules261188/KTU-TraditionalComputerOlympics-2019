#include "Araba.h"

Araba::Araba()
{
    //ctor
}

Araba::~Araba()
{
    //dtor
}

void Araba::xEgit()
{
    if(x<0){x++;}
    if(x>0){x--;}
}

void Araba::yukariCikar()
{   if(x==0)
    y++;
}


void Araba::setX(int x){
    this->x=x;
}

void Araba::setY(int y){
    this->y=y;
}

int Araba::getX(){
    return x;
}

int Araba::getY(){
    return y;
}

