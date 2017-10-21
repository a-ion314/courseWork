//programmed by: Adrian Ionascu
//CSC 2111 Lab 19 Program 2
#include<iostream>

int gcd(int x, int y);		//greatest common divisor function

void main(){
	int first, second, answer;
	std::cout << "GCD Calculator." << std::endl;
	std::cout << std::endl;

	while (true){		//checks for invalid input for first integer
		try{
			std::cout << "Please enter first integer: ";
			if (!(std::cin >> first))
				throw "error";
			else
				break;
		}
		catch (...){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input must be an integer." << std::endl;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	while (true){		//checks for invalid input in second integer
		try{
			std::cout << "Please enter second integer: ";
			if (!(std::cin >> second))
				throw "error";
			else
				break;
		}
		catch (...){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input must be an integer." << std::endl;
			std::cout << std::endl;
		}
	}

	std::cout << "GCD of " << first << " and " << second << " is " << gcd(first, second) << std::endl;

}

int gcd(int x, int y){
	if (y == 0)
		return x;
	else
		return (gcd(y, x%y));
}