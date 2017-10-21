//Programmed by: Adrian Ionascu
//CSC 2111 Lab 19 Program 1

#include<iostream>

double powercalc(int x, int y);		//used to calculate powers

void main(){
	int base, power;
	double answer;
	std::cout << "Power calculator." << std::endl;

	while (true){		//checks to see if input is invalid (non integer) or if input is zero
		try{
			std::cout << "Please enter integer base: ";
			if (!(std::cin >> base))
				throw "badinput";
			if (base == 0)
				throw "ZeroX";
			else 
				break;
		}
		catch (...){
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "base has to be a nonzero integer." << std::endl;
		}
	}
	std::cout << std::endl;

	while (true){		//used to see if a noninteger character is inputted
		try{
			std::cout << "Please enter integer power: ";
			if (!(std::cin >> power))
				throw "error";
			else
				break;
		}
		catch (...){
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "power has to be an integer." << std::endl;
		}
	}
	std::cout << std::endl;
	answer = powercalc(base, power);
	std::cout << base << "^" << power << " = " << answer << std::endl;		//outputs answer

}

double powercalc(int x, int y){
	if (y >= 0){
		if (y == 0)
			return 1;
		else if (y == 1)
			return x;
		else
			return (x*powercalc(x, (y - 1)));
	}
	else
		return (1.00 / powercalc(x, (y*-1.00)));
}