#include <iostream>
#include <fstream>
#include "Convoy.h"

using namespace std;

void splitInputLine(string line, int& carCount, char& color, int& placeX, int& placeY){
    for(int whiteSpaceIndex = 0, leftIndex = 0, whiteSpaceCount = 0; whiteSpaceIndex < line.length(); whiteSpaceIndex++){
        if(isspace(line[whiteSpaceIndex]) && whiteSpaceCount == 0){
            whiteSpaceCount++;
            carCount = stoi(line.substr(leftIndex, whiteSpaceIndex));
            leftIndex = whiteSpaceIndex + 1;
        }
        else if(isspace(line[whiteSpaceIndex]) && whiteSpaceCount == 1){
            whiteSpaceCount++;
            color = line.at(leftIndex);
            leftIndex = whiteSpaceIndex + 1;
        }
        else if(isspace(line[whiteSpaceIndex]) && whiteSpaceCount == 2){
            whiteSpaceCount++;
            placeX = stoi(line.substr(leftIndex, whiteSpaceIndex));
            leftIndex = whiteSpaceIndex + 1;
        }
        else if(whiteSpaceIndex == (line.length() - 1)){
            whiteSpaceCount++;
            placeY = stoi(line.substr(leftIndex, whiteSpaceIndex));
        }
    }
}

int main(){
    ifstream inputFile("./doc/input.txt");

    if(inputFile.is_open()){
        string line;
        vector<Convoy> convoys;
        while(getline(inputFile, line)){
            int carCount;
            char color;
            int placeX;
            int placeY;
            splitInputLine(line, carCount, color, placeX, placeY);
            vector<Car> cars;
            int placeXChanger = placeX < 0 ? -1 : 1;
            for(int i = 0; i < carCount; i++){
                cars.push_back(Car(color, placeX, placeY));
                placeX += placeXChanger;
            }
            convoys.push_back(Convoy(cars));
        }

        bool allDirectionIsY;
        do
        {
            allDirectionIsY = true;
            
            for(int convoyIndex = 0; convoyIndex < convoys.size(); convoyIndex++){
                vector<Car> cars = convoys.at(convoyIndex).getCars();
                for(int carIndex = 0; carIndex < cars.size(); carIndex++){
                    char direction = cars.at(carIndex).getDirection();
                    int placeX = cars.at(carIndex).getPlaceX();
                    int placeY = cars.at(carIndex).getPlaceY();
                    if(direction == 'E' || direction == 'W'){
                        allDirectionIsY = false;
                        if(placeX + 1 == 0 || placeX - 1 == 0){
                            for(int i = 0; i < convoys.size(); i++){
                                for(int j = 0; j < convoys.at(i).getCars().size(); j++){
                                    if(i == convoyIndex && j == carIndex){
                                        continue;
                                    }
                                    int otherPlaceX = convoys.at(i).getCars().at(j).getPlaceX();
                                    int otherPlaceY = convoys.at(i).getCars().at(j).getPlaceY();
                                    char otherDirection = convoys.at(i).getCars().at(j).getDirection();
                                    if(otherDirection == 'N' && otherPlaceY == placeY && (otherPlaceX == placeX + 1 || otherPlaceX == placeX - 1)){
                                        
                                    }
                                    else{
                                        cars.at(carIndex).move();
                                    }
                                }
                            }
                        }
                        else{
                            cars.at(carIndex).move();
                        }
                    }
                    else{
                        cars.at(carIndex).move();
                    }
                }
            }
            
        } while (!allDirectionIsY);

        for(int i = 0; i < convoys.size(); i++){
            vector<Car> tempCars = convoys.at(i).getCars();
            cout<<i + 1<<".convoy car size:"<<convoys.at(i).getCars().size()<<endl;
            for(int j = 0; j < tempCars.size(); j++){
                cout<<j + 1<<".car"<<endl<<"X: "<<tempCars.at(j).getPlaceX()<<" Y: "<<tempCars.at(j).getPlaceY()<<" Color: "<<tempCars.at(j).getColor()<<endl;
            }
            cout<<endl;
        }
    }
    else{
        cout<<"File can't open!"<<endl;
        exit(0);
    }

    return 0;
}