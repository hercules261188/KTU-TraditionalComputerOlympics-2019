#include "ArabaManager.h"

ArabaManager::ArabaManager()
{
    //ctor
}

ArabaManager::~ArabaManager()
{
    //dtor
}

void ArabaManager::update(){
    for(int i=0;i<arabaSayisi;i++){

        if(bosMu(arabaArray[i].getX(),arabaArray[i].getY())){
        arabaArray[i].xEgit();
        }
        arabaArray[i].yukariCikar();
    }
}

void ArabaManager::setArabaArray(Araba* aArray){
    arabaArray=aArray;
}

bool ArabaManager::bosMu(int x,int y){
    bool b = true;
    for(int i=0;i<arabaSayisi;i++){
            if(arabaArray[i].getX()==0 && arabaArray[i].getY()==y-1){
                b=false;
            }
    }
    return b;
}
