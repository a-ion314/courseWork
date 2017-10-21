//Programmed by: Adrian Ionascu CSC 1501 Lab 06 Problem 3
#include<iostream>
#include<string>

void main(){
	int num, div = 2;
	
	std::cout << "Please enter integer: ";

	while (true){
		std::cin >> num;
		if (num >= 2)
			break;
		else
			std::cout << "Please intput integer greater than or equal to 2. \n";
	}

	while (div * div <= num){
		if (num % div == 0){
			num /= div;
			std::cout << div << " ";
		}
		else
			div++;
	}

	if (num > 1)
		std::cout << num << " ";
}