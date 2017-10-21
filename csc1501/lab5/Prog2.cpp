//Programmed by Adrian Ionascu CSC 1501 Lab 05 Problem 2
#include<iostream>
#include<fstream>

void insertSort(int input[],int count);

void main(){
	std::ifstream Doc; std::ofstream out;
	Doc.open("A1.txt");

	int count = 0, x;

	while ((!Doc.eof()) && (Doc >> x)){
		count++;
	}

	int * input;
	input = new int[count];

	Doc.clear();
	Doc.seekg(0, std::ios_base::beg);

	for (int i = 0; i <= (count - 1); i++){
		Doc >> input[i];
	}

	insertSort(input, count);
	Doc.close();
	out.open("A2Output.txt");

	for (int i = 0; i <= (count - 1); i++){
		out << input[i] << " ";
	}
	out.close();

}

void insertSort(int input[],int count){
	for (int j = 0; j < count; j++){
		int i = 0;
		while (input[j] > input[i])
			i = i + 1;
		int m = input[j];
		for (int k = 0; k < (j - i - 1); k++)
			input[j - k] = input[j - k - 1];
		input[i] = m;
	}
}