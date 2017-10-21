//Programmed by: Adrian Ionascy
//CSC 1501 Lab 09 Program 2

#include<iostream>
#include<string>

void main(){
	std::string input, output;
	int num, key;

	std::cout << "Please input string to decrpyt(only characters no space): ";
	std::cin >> input;
	std::cout << "Please input key(integer only): ";
	std::cin >> key;
	
	key = 26 - (key % 26);

	for (int i = 0; i < input.length(); i++){
		num = ((((static_cast<int>(input[i]) - 65) + key) % 26) + 97);
		output += static_cast<char>(num);
	}

	std::cout << "\"" << input << "\"" << " decryted is now " << "\"" << output << "\"" << std::endl;
}