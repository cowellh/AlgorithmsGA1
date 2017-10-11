#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int getInt(ifstream &inFile, int pos){
	int num = 0;
	char tempC;
	int tempI = 0;
	for(int i = 1; i <= 8; i++){
		inFile.get(tempC);
		
		//This if makes sure new line characters are skipped
		if(tempC == '\n')
			inFile.get(tempC);
		
		//This block converts the hex digit into decimal
		if(tempC == 'a')
			tempI = 10;
		else if(tempC == 'b')
			tempI = 11;
		else if(tempC == 'c')
			tempI = 12;
		else if(tempC == 'd')
			tempI = 13;
		else if(tempC == 'e')
			tempI = 14;
		else if(tempC == 'f')
			tempI = 15;
		for(int j = 0; j < 10; j++){
			if((int)tempC == 48+j)
				tempI = j;
		}
		
		//Adds the current digit to the total
		num = num + (tempI * pow( 16 , (8 - i) ));
	}
}

int main(){
	system("xxd *.dat *.txt");
	
	//system("xxd -ps 1.dat 1.txt");
	//ifstream inFile("1.txt", ios::in);
	
	for(int i=0; i<10; i++)
	cout << getInt(inFile, 5) << endl;
}