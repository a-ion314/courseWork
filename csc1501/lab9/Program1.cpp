//Programmed by: Adrian Ionascu
//CSC 1501 Lab 09 Program 1

#include<iostream>
#include<string>

void main(){
	std::string input, output;
	int key, num;

	std::cout << "Please enter string to encrypt(only characters no spaces): ";
	std::cin >> input;
	std::cout << "Please enter key(must be an integer): ";
	std::cin >> key;

	for (int i = 0; i < input.length(); i++){
		if (static_cast<int>(input[i]) < 97){
			num = ((((static_cast<int>(input[i]) - 65) + key) % 26) + 65);
			output += static_cast<char>(num);
		}
		else
			num = ((((static_cast<int>(input[i]) - 97) + key) % 26) + 97);
		output += static_cast<char>(num);
	}

	std::cout << "\"" << input << "\"" << " encrypted is now " << "\"" << output << "\"" << std::endl;
}