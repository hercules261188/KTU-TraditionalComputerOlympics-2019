#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
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
	
	int *inputarray;
	int inputarraylen;
	FILE *dosya;
	int temp;
	if((dosya=fopen("input.txt","r"))==NULL){
		cout<<"Dosya acilamadi"<<endl;
		exit(0);
	}
	
	else{
		/// Dosyadaki dizinin buyuklugunu hesapla..
		int count=0;
		while(!feof(dosya)){
			fscanf(dosya,"%d",&temp);
			count++;
			if(count==10000){
				break;
			}
		}
		inputarraylen=count;
		fclose(dosya);
	}
	
	if((dosya=fopen("input.txt","r"))==NULL){
		cout<<"Dosya acilamadi"<<endl;
		exit(0);
	}
	else{
		inputarray=new int[inputarraylen];
		int count=0;
		while(!feof(dosya)){
			fscanf(dosya,"%d",&inputarray[count]);
			count++;
			
		}
		fclose(dosya);
	}
	
	
	int maxmularraylen=1;
	count=0;
	///dosyadaki ilk girdiler 0 oldugu surece devam et ilk 0 olmayani al
	while(inputarray[count]==0){
		count++;
	}
	int *maxmularray=new int[1];
	// ilk sifir olmayan inputu al...
	maxmularray[0]=inputarray[count];
	long long maxcarpim = inputarray[count];
	long long maxcarpim2 = inputarray[count];
	int *tempmularray=new int[1];
	tempmularray[0]=inputarray[count];
	for(int i=count;i<inputarraylen;i++){
		maxcarpim2 *= inputarray[i];
		if(maxcarpim2!=0){
				maxcarpim=maxcarpim2;
				count++;
				int *temparray= new int[count];
				temparray = ArrayScale(maxmularray,maxmularraylen,inputarray[i]);
				maxmularray = new int[count];
				maxmularray = temparray;		
		}
		else{
			continue;
		}
	}
	
	
	
	clock_t toc = clock();
	printf("Toplam Süre: %f saniye\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	return 0;
}
