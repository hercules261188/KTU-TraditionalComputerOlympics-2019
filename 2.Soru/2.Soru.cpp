#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;

string* expandOutputArray(string* outputArray, int& outputArraySize, string palindrom){
	outputArraySize++;
	if(outputArraySize == 1){
		outputArray = new string[outputArraySize];
		outputArray[0] = palindrom;
		return outputArray;
	}

	string* tempArray = new string[outputArraySize - 1];
	for(int index = 0; index < outputArraySize - 1; index++){
		tempArray[index] = outputArray[index];
	}
	outputArray = new string[outputArraySize];
	for(int index = 0; index < outputArraySize - 1; index++){
		outputArray[index] = tempArray[index];
	}
	outputArray[outputArraySize - 1] = palindrom;
	return outputArray;
}

string* sortOutputArrayByLength(string* outputArray, int outputArraySize){
	for(int index = 0; index < outputArraySize - 1; index++){
		for(int secondIndex = index + 1; secondIndex < outputArraySize; secondIndex++){
			if(outputArray[index].length() < outputArray[secondIndex].length()){
				string temp = outputArray[index];
				outputArray[index] = outputArray[secondIndex];
				outputArray[secondIndex] = temp;
			}
		}
	}
	return outputArray;
}

string* sortOutputArrayByAlphabet(string* outputArray, int outputArraySize){
	for(int index = 0; index < outputArraySize - 1; index++){
		int sameLengthRightIndex = index;
		for(int secondIndex = index + 1; outputArray[index].length() == outputArray[secondIndex].length(); secondIndex++){
			sameLengthRightIndex++;
		}
		if(sameLengthRightIndex > index){
			for(int sameLengthLeftIndex = index; sameLengthLeftIndex < sameLengthRightIndex; sameLengthLeftIndex++){
				for(int sameLengthRightIndex2 = sameLengthLeftIndex + 1; sameLengthRightIndex2 < sameLengthRightIndex + 1; sameLengthRightIndex2++){
					int palindromLastIndex = outputArray[sameLengthLeftIndex].length();
					bool isLeftPalindromFirst = false;
					for(int palindromIndex = 0; palindromIndex < palindromLastIndex; palindromIndex++){
						if(outputArray[sameLengthLeftIndex][palindromIndex] < outputArray[sameLengthRightIndex2][palindromIndex]){
							isLeftPalindromFirst = true;
							break;
						}
						else if(outputArray[sameLengthLeftIndex][palindromIndex] > outputArray[sameLengthRightIndex2][palindromIndex]){
							break;
						}
					}
					if(!isLeftPalindromFirst){
						string temp = outputArray[sameLengthLeftIndex];
						outputArray[sameLengthLeftIndex] = outputArray[sameLengthRightIndex2];
						outputArray[sameLengthRightIndex2] = temp;
					}
				}
			}
		}
		index = sameLengthRightIndex;
	}

	return outputArray;
}

int main(){
	clock_t tic=clock();
	
	ifstream inputFile("input.txt");
	string inputArray;
	string* outputArray;
	int outputArraySize = 0;
	getline(inputFile, inputArray);
	inputFile.close();
	ofstream outputFile("output.txt");
	for(int indexFromBegin = 0; indexFromBegin < inputArray.length() - 2; indexFromBegin++){
		for(int indexFromEnd = inputArray.length() - 1; indexFromEnd > indexFromBegin; indexFromEnd--){
			int leftIndex = indexFromBegin, rightIndex = indexFromEnd;
			while(inputArray[leftIndex] == inputArray[rightIndex]){
				leftIndex++; rightIndex--;
				if(leftIndex >= rightIndex){
					break;
				}
			}
			
			if(leftIndex >= rightIndex && (indexFromEnd + 1 - indexFromBegin) >= 3){
				string palindrom;
				for(int palindromIndex = indexFromBegin; palindromIndex < indexFromEnd + 1; palindromIndex++){
					palindrom += inputArray[palindromIndex];
				}
				outputArray = expandOutputArray(outputArray, outputArraySize, palindrom);
			}
		}
	}

	outputArray = sortOutputArrayByLength(outputArray, outputArraySize);
	outputArray = sortOutputArrayByAlphabet(outputArray, outputArraySize);
	
	for(int index = 0; index < outputArraySize; index++){
		outputFile << outputArray[index];
		if(index != outputArraySize - 1){
			outputFile << endl;
		}
	}
	
	clock_t toc = clock();
	printf("Total Time: %f second\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	return 0;
}
