#include <iostream>
#include <fstream>
#include <time.h>
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
    clock_t tic=clock();

    ifstream inputFile("./doc/input.txt");

    if(inputFile.is_open()){
        string line;
        vector<Convoy> convoys;
        int allCarCount = 0;
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
            allCarCount += carCount;
        }
        inputFile.close();
        
        Convoy* whichOnYDirection = new Convoy();
        do
        {
            vector<int> movableConvoyIndexs;
            movableConvoyIndexs.clear();
            for(int i = 0; i < convoys.size(); i++){
                if(convoys.at(i).getCars().size() > 0){
                    if(convoys.at(i).checkIsMovable(whichOnYDirection)){
                        movableConvoyIndexs.push_back(i);
                    }
                }
            }
            for(int i = 0; i < movableConvoyIndexs.size(); i++){
                convoys.at(movableConvoyIndexs.at(i)).move(whichOnYDirection);
            }
            if(whichOnYDirection->getCars().size() != 0){
                whichOnYDirection->move(whichOnYDirection);
            }
        } while (whichOnYDirection->getCars().size() != allCarCount);

        whichOnYDirection->sortCarsByPlaceY();
        
        ofstream outputFile("./doc/output.txt");
        for(int leftIndex = 0; leftIndex < whichOnYDirection->getCars().size(); leftIndex++){
            char color = whichOnYDirection->getCars().at(leftIndex).getColor();
            int colorCount = 0;
            for(int j = leftIndex; j < whichOnYDirection->getCars().size(); j++){
                if(whichOnYDirection->getCars().at(j).getColor() == color){
                    colorCount++;
                    if(j == whichOnYDirection->getCars().size() - 1){
                        leftIndex = j;
                    }
                }
                else{
                    leftIndex = j - 1;
                    break;
                }
            }
            outputFile<< colorCount << " " << color << (leftIndex == whichOnYDirection->getCars().size() - 1 ? "" : " ");
        }
    }
    else{
        cout<<"File can't open!"<<endl;
        exit(0);
    }

    clock_t toc = clock();
	printf("Total Time: %f second\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    return 0;
}