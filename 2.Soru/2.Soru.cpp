#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;

int main(){
	clock_t tic=clock();
	
	ifstream dosya("input.txt");
	string dizi;
	getline(dosya,dizi);
	dosya.close();
	ofstream dosya2("output.txt");
	for(int i=0;i<dizi.length()-3;i++){
		for(int j=dizi.length()-1;j>i;j--){

			int k=i,t=j,count=0;
			while(dizi[k]==dizi[t]){
				k++;t--;
				if(k>=t){
					break;
				}
			}
			
			if(k>=t && (j+1-i)>=3){
				for(int p=i;p<j+1;p++){
					dosya2<<dizi[p];
				}
				dosya2<<endl;
			}
		}
	}
	
	
	clock_t toc = clock();
	printf("Toplam Süre: %f saniye\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	return 0;
}
