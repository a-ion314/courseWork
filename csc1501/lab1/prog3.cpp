//Programemd by: Adrian Ionascu
//CSC 1501 Lab 1 Problem 3
#include<iostream>
#include<string>

void bOR(int length, std::string input1, std::string input2);
void bAND(int length, std::string input1, std::string input2);
void bXOR(int length, std::string input1, std::string input2);

void main(){
	int choice, length;
	std::string input1, input2, output = " ", operation;
	bool check;

	//"Enter your second number: "

	std::cout << "Bitwise operation" << std::endl << std::endl;

	std::cout << "1. bitwise OR" << std::endl
		<< "2. bitwise AND" << std::endl
		<< "3. bitwise XOR" << std::endl;
	std::cout << std::endl;

	while (((std::cout << "Enter your choice: ") && !(std::cin >> choice)) || (choice < 1) || (choice > 3)){		//checks for valid inputs for 'choice'
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid Input. \n";
	}

	for (int i = 0; i <= 0; i--){		//checks to see if first binary number consists of only 1s and 0s and contains no spaces
		std::cout << "Enter your first binary number (no spaces) : ";
		std::cin >> input1;
		length = input1.length();
		for (int j = 0; j <= (length - 1); j++){
			if ((input1.at(j) == '1') || (input1.at(j) == '0'))
				check = 1;
			else{
				check = 0;
				break;
			}
		}
		if (check == 1)
			break;
		std::cout << "Your Number is not valid." << std::endl;
	}

	for (int i = 0; i <= 0; i--){		////checks to see if second binary number consists of only 1s and 0s and contains no spaces
		std::cout << "Enter your first second number (no spaces): ";
		std::cin >> input2;
		length = input2.length();
		for (int j = 0; j <= (length - 1); j++){
			if ((input2.at(j) == '1') || (input2.at(j) == '0'))
				check = 1;
			else{
				check = 0;
				break;
			}
		}
		if (check == 1)
			break;
		std::cout << "Your Number is not valid." << std::endl;
	}

	switch (choice){		//calls functions based on user choice
	case 1: std::cout << "Binary 1: " << input1 << std::endl;
		std::cout << "Binary 2: " << input2 << std::endl;
		bOR(length, input1, input2);
		break;
	case 2: std::cout << "Binary 1: " << input1 << std::endl;
		std::cout << "Binary 2: " << input2 << std::endl;
		bAND(length, input1, input2);
		operation = "bitwise AND";
		break;
	case 3: std::cout << "Binary 1: " << input1 << std::endl;
		std::cout << "Binary 2: " << input2 << std::endl;
		bXOR(length, input1, input2);
		operation = "bitwise XOR";
		break;
	}

	std::cout << output;
}

void bOR(int length, std::string input1, std::string input2){
	std::cout << "Output  : ";
	for (int i = 0; i <= (length - 1); i++){
		if ((input1.at(i) == '1') || (input2.at(i) == '1'))
			std::cout << '1';
		else
			std::cout << '0';
	}
	std::cout << std::endl;
}

void bAND(int length, std::string input1, std::string input2){
	std::cout << "Output  : ";
	for (int i = 0; i <= (length - 1); i++){
		if ((input1.at(i) == '1') && (input2.at(i) == '1'))
			std::cout << '1';
		else
			std::cout << '0';
	}
	std::cout << std::endl;
}

void bXOR(int length, std::string input1, std::string input2){
	std::cout << "Output  : ";
	for (int i = 0; i <= (length - 1); i++){
		if ((input1.at(i) == '1') ^ (input2.at(i) == '1'))
			std::cout << '1';
		else
			std::cout << '0';
	}
	std::cout << std::endl;
}