//Programmed by: Adrian Ionascu CSC 2111 Lab 10 Problem 2
#include<iostream>
#include<string>

void main(){
	std::string str1;
	int length;
	char temp;
	std::cout << "Please input string: ";
	getline(std::cin,str1);		//gets entire line
	length = str1.length();		//gets length
	char *input;
	input = new char[length];		//sets length of array to length of string

	for (int i = 0; i < length; i++){		//for loop takes every character and inputs it into the array
		input[i] = str1[i];
	}

	for (int i = 0; i < length; i++){		//takes every individual character in the array and uses the toupper function
		toupper(input[i]);
	}

	for (int i = 0; i < length; i++){		//outputs all characters in array
		std::cout << input[i];
	}
	std::cout << std::endl;

	delete input;		//properly deletes pointer
	input = NULL;
}