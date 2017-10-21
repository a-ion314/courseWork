//Programmed by: Adrian Ionascu
//CSC 1501 Lab 07 Program 2
#include<iostream>
#include<fstream>

void bubble(int list[], int first, int last);

void main(){
	std::ifstream doc; std::ofstream output;
	doc.open("A2.txt"); output.open("B2.txt");

	int array1[15];

	for (int i = 0; i < 10; i++){
		for (int i = 0; i < 15; i++){
			doc >> array1[i];
		}
		doc.ignore();

		bubble(array1, 0, 14);

		for (int i = 0; i < 15; i++){
			output << array1[i] << " ";
		}
		output << std::endl;
	}
	doc.close();
	output.close();
}

void bubble(int list[], int first, int last){
	if (first < last && last > 0){
		if (list[first] > list[first + 1]){
			int temp = list[first];
			list[first] = list[first + 1];
			list[first + 1] = temp;
		}
		bubble(list, first + 1, last);
		bubble(list, first, last - 1);
	}
}
