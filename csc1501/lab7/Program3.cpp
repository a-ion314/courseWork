//Programmed by: Adrian Ionascu
//CSC 1501 Lab 07 Program 3
#include<iostream>
#include<fstream>

int search(int list[], int check, int low, int high);

void main(){
	std::ifstream doc; std::ofstream output;
	doc.open("A3.txt"); output.open("B3.txt");
	int flag, location;
	int list[15];

	while (!(doc.eof())){
		doc >> flag;
		for (int i = 0; i < 15; i++){
			doc >> list[i];
		}

		location = (search(list, flag, 0, 15) + 1);
		if (location == 0)
			output << "Not Found!" << std::endl;
		else
			output << location << std::endl;
	}
	
	doc.close();
	output.close();
}

int search(int list[], int check,int low, int high){
	int middle = (low + high) / 2;
	if (high < low)
		return -1;
	else
		if (list[middle] == check)
			return middle;
		else if (list[middle] < check)
			return search(list, check, (middle + 1), high);
		else
			return search(list, check, low, (middle - 1));
}