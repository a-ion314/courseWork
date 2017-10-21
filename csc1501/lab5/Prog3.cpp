//Programmed by Adrian Ionascu CSC 1501 Lab 05 Problem 3
#include<iostream>
#include<fstream>

void bubbleSort(int sort[], int size);

void main(){
	std::ifstream Doc;
	Doc.open("A1.txt");
	int x;
	int size = 0;

	while ((!Doc.eof()) && (Doc >> x)){
		size++;
	}

	int * sort;
	sort = new int[size];

	Doc.clear();
	Doc.seekg(0, std::ios_base::beg);

	for (int i = 0; i <= (size - 1); i++){
		Doc >> sort[i];
	}

	bubbleSort(sort, size);
	for (int i = 0; i < size; i++){
		std::cout << sort[i] << " ";
	}
}

void bubbleSort(int sort[], int size){
	int hold;
	for (int n = 1; n < (size - 1); n++){
		for (int m = 0; m < (size - n); m++){
			if (sort[m] < sort[m + 1]){
				hold = sort[m];
				sort[m] = sort[m + 1];
				sort[m + 1] = hold;
			}
		}
	}
}