#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

int *ArrayScale(int *maxarray, int count,int value){
	int *temparray=new int[count + 1];
	for(int i=0;i<count;i++){
		temparray[i]=maxarray[i];
	}
	temparray[count]=value;
	return temparray;
}

int main(){
	clock_t tic=clock();
	
	ifstream inputFile("./doc/input.txt");
	
	int temp;
	vector<int> inputArray;
	if(inputFile.is_open()){
		while(inputFile >> temp){
			inputArray.push_back(temp);
			if(inputArray.size() == 10000){
				break;
			}
		}
		inputFile.close();

		vector<vector<int>> subArrays;
		for(int index = 0; index < inputArray.size(); index++){
			vector<int> tempArray;
			while(inputArray.at(index) != 0){
				tempArray.push_back(inputArray.at(index));
				index++;
				if(index == inputArray.size()){
					break;
				}
			}
			if(tempArray.size() > 1)
			{
				if(tempArray.size() == 2){
					subArrays.push_back(tempArray);
				}
				else{
					for(int subArraySize = tempArray.size(); subArraySize > 1; subArraySize--){
						for(int i = 0; i < tempArray.size() - subArraySize + 1; i++){
							vector<int> subSubArray;
							for(int j = i; j < i + subArraySize; j++){
								subSubArray.push_back(tempArray.at(j));
							}
							subArrays.push_back(subSubArray);
						}
					}
				}
			}
		}

		int maxMulIndexInSubArray;
		int maxMul = INT32_MIN;

		for(int index = 0; index < subArrays.size(); index++){
			int mul = 1;
			for(int index2 = 0; index2 < subArrays.at(index).size(); index2++){
				mul *= subArrays.at(index).at(index2);
			}
			if(mul > maxMul){
				maxMul = mul;
				maxMulIndexInSubArray = index;
			}
		}

		vector<int> maxMulSubArray = subArrays.at(maxMulIndexInSubArray);
		int minValue = INT32_MAX;
		int maxValue = INT32_MIN;

		for(int index = 0; index <maxMulSubArray.size(); index++){
			if(maxMulSubArray.at(index) > maxValue){
				maxValue = maxMulSubArray.at(index);
			}
			if(maxMulSubArray.at(index) < minValue){
				minValue = maxMulSubArray.at(index);
			}
		}

		ofstream outputFile("./doc/output.txt");
		outputFile << maxValue - minValue;
		outputFile.close();

	}
	else{
		cout<<"File can't open!";
		exit(0);
	}
	
	clock_t toc = clock();
	printf("Total Time: %f second\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	return 0;
}
