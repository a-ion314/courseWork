//Programmed by Adrian Ionascu CSC 1501 Lab 05 Problem 4
#include<iostream>
#include<fstream>

void binSearch(int Arr[], int flag, int size);

void main(){
	std::ifstream Doc;
	Doc.open("A2Output.txt");

	int x, size = 0, flag;

	while ((!Doc.eof()) && (Doc >> x)){
		size++;
	}

	int * Arr;
	Arr = new int[size];

	Doc.clear();
	Doc.seekg(0, std::ios_base::beg);

	for (int i = 0; i <= (size - 1); i++){
		Doc >> Arr[i];
	}

	std::cout << "Please enter Number you want to search for: ";
	std::cin >> flag;

	binSearch(Arr,flag, size);

}

void binSearch(int Arr[], int flag, int size){
	int index, duplicate;
	int n = 0, m = (size - 1);
	int middle;
	while (n < m){
		middle = floor(((n + m) / 2));
		if (flag > Arr[middle])
			n = middle + 1;
		else
			m = middle;
	}
	if (flag == Arr[n]){
		index = n;
	}
	else
		index = -1;

	if (index == -1)
		std::cout << "Your number could not be found." << std::endl;
	else{
		std::cout << "Your number was found at index " << index << std::endl;
		int search = 1;
		while (Arr[index] == Arr[index + search]){
			duplicate = index + search;
			std::cout << "and your number was found at index " << duplicate << std::endl;
			search++;
		}
		search = 1;
		while (Arr[index] == Arr[index - search]){
			duplicate = index + search;
			std::cout << "and your number was found at index " << duplicate << std::endl;
			search++;
		}
	}
}