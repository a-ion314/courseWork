//Programed by: Adrian Ionascu CSC 1501 Lab 06 Program 1
#include<iostream>
#include<string>

void main(){
	int num = 0;
	std::string reverse = "", output = "";

	std::cout << "Please input integer in base 10: ";
	std::cin >> num;
	std::cout << std::endl;
	std::cout << "Your input is: " << num << std::endl;
	
	while (num != 0){
		if ((num % 2) == 1)
			reverse += '1';
		else
			reverse += '0';
		num = num / 2;
	}

	for (int i = (reverse.length() - 1); i >= 0; i--){
		output += reverse[i];
	}

	std::cout << "Output is: " << output << std::endl;
}