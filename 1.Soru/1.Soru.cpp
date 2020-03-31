#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;

int main(){
	clock_t tic=clock();
	
	int row,column,rotate;
	int *matrix;
	FILE *dosya;
	if((dosya=fopen("input.txt","r"))==NULL){
		cout<<"Dosya acilamadi"<<endl;
	}
	else{
		fscanf(dosya,"%d%d%d",&row,&column,&rotate);
		if(row <= 0 || column <= 0){
			cout<<"Satir veya Sutun bilgisi yanlis.";
			exit(0);
		}
		matrix = new int[row*column];
		for(int i=0;i<row;i++){
			for(int j=0;j<column;j++){
				fscanf(dosya,"%d",&matrix[i*column+j]);
			}
		}
		fclose(dosya);
	}
	
	int templength=column*2+(row-2)*2;
	int *temp=new int[templength];
	int count=0;
	
	//	kenarlarin alinmasi
	for(int i=0;i<column;i++){
		temp[count]=matrix[i];	
		count++;
	}	
	for(int i = 2 * column - 1; i<row*column; i += column){
		temp[count] = matrix[i];
		count++;
	}
	
	for(int i = row*column - 2; i>row*column-column-1 ;i--){
		temp[count]=matrix[i];
		count++;
	}
	
	for(int i=(row-2)*column; i > 0; i-=column){
		temp[count]=matrix[i];
		count++;
	}
	
	//	dondurme islemi
	int *temp2=new int[templength];
	
	for(int i=0;i<templength;i++){
		temp2[(i+rotate+templength)%templength]=temp[i];	
	}
	count=0;
	//	kenarlarin tekrar setlenmesi
	for(int i=0;i<column;i++){
		matrix[i]=temp2[count];
		count++;
	}
	
	for(int i = 2 * column - 1; i<row*column; i += column){
		matrix[i] = temp2[count];
		count++;
	}
	
	for(int i = row*column - 2; i>row*column-column-1 ;i--){
		matrix[i]=temp2[count];
		count++;
	}
	
	for(int i=(row-2)*column; i > 0; i-=column){
		matrix[i]=temp2[count];
		count++;
	}
	
	ofstream dosya2("output.txt");

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			if(j!=column-1)
				dosya2<<matrix[i*column+j]<<" ";
			else
				dosya2<<matrix[i*column+j];
		}
		if(i!=row-1)
		dosya2<<endl;
	}
	
	dosya2.close();
	
	
	clock_t toc = clock();
	printf("Toplam Süre: %f saniye\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	return 0;
}
