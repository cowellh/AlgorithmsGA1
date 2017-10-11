#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#pragma comment(linker, "/STACK:2000000")

using namespace std;

long long getInt(ifstream &inFile){
	int place = inFile.tellg();
	long long num = 0;
	char tempC;
	long long tempI = 0;
	for(int i = 1; i <= 8; i++){
		inFile.get(tempC);
		
		//This if makes sure new line characters are skipped
		if(tempC == '\n')
			inFile.get(tempC);
			//cout << i << ": " << tempC << endl;
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
	inFile.seekg(place);
	return num;
}

int findLowest(vector<ifstream*>& arrayArray){
	int low;
	for(int i = 0; i < arrayArray.size(); i++){
		if(i == 0) low = 0;
		else if(getInt(*arrayArray[i]) < getInt(*arrayArray[low]))
			low = i;
	}
	return low;
}

void removeLow(vector<ifstream*>& arrayArray, int lowest){
	char newLine;
	cout << getInt(*arrayArray[lowest]) << endl;
	cout << "finish" << endl;
	for(int i = 0; i < 8; i++){
		arrayArray[lowest] -> get(newLine);
		if(newLine == '\n')
			arrayArray[lowest] -> get();
	}
}

long long arrayFind(vector<ifstream*>& arrayArray, int k){
	int lowestArr = findLowest(arrayArray);
	if( k == 2)
		return(getInt(*arrayArray[lowestArr]));
	else{
		k--;
		removeLow(arrayArray, lowestArr);
		return(arrayFind(arrayArray, k));
	}
}

int main(){
	vector <ifstream*> arrayArray;

	ifstream input("input.txt", ios::in);
	if(!input){
		cout << "No input.txt File!!!" << endl;
		return 0;
	}
	
	char heyo[20];
	string intermediate;
	input.getline(heyo, 20,',');
	input.getline(heyo, 20,',');
	input.getline(heyo, 20);
	intermediate = heyo;
	int k = stoi(intermediate);
	
			
		
	
	system("xxd -ps 1.dat 1.txt");
	system("xxd -ps 2.dat 2.txt");
	system("xxd -ps 3.dat 3.txt");
	system("xxd -ps 4.dat 4.txt");
	system("xxd -ps 5.dat 5.txt");
	system("xxd -ps 6.dat 6.txt");
	system("xxd -ps 7.dat 7.txt");
	system("xxd -ps 8.dat 8.txt");
	system("xxd -ps 9.dat 9.txt");
	system("xxd -ps 10.dat 10.txt");
	
	ifstream first("1.txt", ios::in);
	if(first)
		arrayArray.push_back(&first);
	
	ifstream second("2.txt", ios::in);
	if(second)
		arrayArray.push_back(&second);
	
	ifstream third("3.txt", ios::in);
	if(third)
		arrayArray.push_back(&third);
	
	ifstream fourth("4.txt", ios::in);
	if(fourth)
		arrayArray.push_back(&fourth);
	
	ifstream fifth("5.txt", ios::in);
	if(fifth)
		arrayArray.push_back(&fifth);
	
	ifstream sixth("6.txt", ios::in);
	if(sixth)
		arrayArray.push_back(&sixth);
	
	ifstream seventh("7.txt", ios::in);
	if(seventh)
		arrayArray.push_back(&seventh);
	
	ifstream eighth("8.txt", ios::in);
	if(eighth)
		arrayArray.push_back(&eighth);
	
	ifstream ninth("9.txt", ios::in);
	if(ninth)
		arrayArray.push_back(&ninth);
	
	ifstream tenth("10.txt", ios::in);
	if(tenth)
		arrayArray.push_back(&tenth);
	
	cout << arrayArray.size() << " arrays were loaded!" << endl;
	cout << "Your selected k value is: " << k << endl;
	
	ofstream output("output.txt", ios::out);
	if(!output){
		cout << "Error, no output file!" << endl;
		return 0;
	}
	
	
	long long done = arrayFind(arrayArray, k);
	 
	printf("The %u smallest element in the array(s) is %u\n", k, done);
	 
	char *characterPointer = (char *) &done;
	output.write(characterPointer, strlen(characterPointer));
	
	
	
	
	first.close();
	second.close();
	third.close();
	fourth.close();
	fifth.close();
	sixth.close();
	seventh.close();
	eighth.close();
	ninth.close();
	tenth.close();
	return 0;
}