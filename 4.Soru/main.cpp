#include <time.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>

 #include "ArabaManager.h"

using namespace std;



int main() {
	clock_t tic = clock();

    ifstream input("input.txt");
	int strSize=0;

	//Dosyayý okuyup char arrayin icine atma
	while (!input.eof()) {
		strSize++;
	}
	input.close();

	int arabaSayisi[100];
	char arabaRenkleri[100];
	int xCoor[100];
	int yCoor[100];

	FILE *dosya;
	if((dosya=fopen("input.txt","r"))==NULL){
        cout<<"Dosya acalamadi"<<endl;
	}
	else{
            for(int i=0;i<strSize;i++){
                fscanf(dosya,"%d%c%d%d",&arabaSayisi[i],&arabaRenkleri[i],&xCoor[i],&yCoor[i]);
            }


	}

	ArabaManager arabaManager;

	clock_t toc = clock();
	printf("\nToplam Süre: %f saniye\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	return 0; }
