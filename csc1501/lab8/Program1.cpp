//Programmed by: Adrian Ionascu
//CSC 1501 Lab 08 program 1
#include<iostream>
#include<string>

void main(){
	std::string input;
	bool check = true;
	int found = -1;

	std::cout << "Please input a string: ";
	std::getline(std::cin, input);
	found = input.find(" ");

	if (found != -1){
		while (found != -1){
			input.erase(found, 1);
			found = input.find(" ");
		}
	}

	for (int i = 0; i < input.length(); i++){
		for (int j = 0; j < input.length(); j++){
			if ((input[i] == input[j]) && (i != j)){
				check = false;
				break;
				break;
			}
		}
	}

	if (check == true)
		std::cout << "The characters in this string are unique." << std::endl;
	else
		std::cout << "The characters in this string are NOT unique." << std::endl;
}