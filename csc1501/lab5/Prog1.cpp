//Programmed by Adrian Ionascu CSC 1501 Lab 05 Problem 1
#include<iostream>
#include<fstream>

void main(){
	std::ifstream Doc("A1.txt");
	int x, flag;
	int count=0;
	
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

	std::cout << "Please type in value you are searching for: ";
	std::cin >> flag;
	std::cout << std::endl;

	int index = 0;
	for (int i = 0; i <= (count - 1); i++){
		if (flag == input[i]){
			std::cout << "Your number was found at index " << i << std::endl;
			index++;
		}
	}

	if (index == 0){
		std::cout << "Number is not available!" << std::endl;
	}

}