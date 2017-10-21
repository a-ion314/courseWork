//Programmed by: Adrian Ionascu
//CSC 1501 Lab 08 program 2

#include<iostream>
#include<string>

void main(){
	bool check[256] = { 0 }, unique = true;
	std::string input;
	int found = -1;
	std::cout << "Please input string: ";
	std::cin >> input;

	if (found != -1){
		while (found != -1){
			input.erase(found, 1);
			found = input.find(" ");
		}
	}
	
	for (int i = 0; i < input.length(); i++){
		bool temp = check[static_cast<int>(input[i])];
		if (temp == false){
			check[static_cast<int>(input[i])] = true;
		}
		else{
			unique = false;
			break;
		}
	}

	if (unique == true){
		std::cout << "All of the characters in this string are unique." << std::endl;
	}
	else
		std::cout << "All of the chararcters in this string are NOT unique." << std::endl;

}