//Programmed by: Adrian Ionascu
//csc 2111 Lab 17
#include<iostream>
#include<math.h>
#include<string>

class inputfail{
public:
	inputfail(){ fail = "Incorrect input"; };
	std::string returnFail(){ return fail; }
private:
	std::string fail;
}; inputfail input;

class zerofail{
public:
	zerofail(){fail = "cannot divide by zero";};
	std::string returnFail(){ return fail; }
private:
	std::string fail;
}; zerofail zero;

class squarefail{
public:
	squarefail(){ fail = "Cannot find square root of negative number."; };
	std::string returnFail(){ return fail; }
private:
	std::string fail;
}; squarefail root;

void menu();
void division();
void squareroot();
void exponent();

void main(){
	while (true){	//used to check for incorrect input from main
		try{
			menu();
			break;
		}
		catch (inputfail a){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << a.returnFail() << std::endl;
			std::cout << std::endl;
		}
	}
}

void menu(){
	int choice;
	std::cout << "Please choose your operation." << std::endl;
	std::cout << "1. Division" << std::endl;
	std::cout << "2. square root" << std::endl;
	std::cout << "3. exponent" << std::endl;
	std::cout << "0. exit" << std::endl;
	std::cout << "Choice: ";
	
	if (!(std::cin >> choice) || (choice < 0) || (choice > 3))		//checks for incorrect input
		throw input;


	switch (choice){
	case 0: exit(NULL);
		break;
	case 1:
		while (true){
			try{
				division();
				break;
			}
			catch (inputfail a){	
				//check for incorrect input
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << a.returnFail() << std::endl;
				std::cout << std::endl;
			}
			catch (zerofail b){		//divide by zero fail
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << b.returnFail() << std::endl;
				std::cout << std::endl;
			}
		}
		menu();
		break;
	case 2:
		while (true){
			try{
				squareroot();
				break;
			}
			catch (inputfail a){		//incorrect input fail
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << a.returnFail() << std::endl;
				std::cout << std::endl;
			}
			catch (squarefail c){		//negative root fail
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << c.returnFail() << std::endl;
				std::cout << std::endl;
			}
		}
		menu();
		break;
	case 3:
		while (true){
			try{
				exponent();
				break;
			}
			catch (inputfail a){		//incorrect input fail
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << a.returnFail() << std::endl;
				std::cout << std::endl;
			}
		}
		menu();
		break;
	}
}

void division(){
	double dividend, divisor, quotient;
	std::cout << "Please enter your dividend: ";
	if (!(std::cin >> dividend))
		throw input;
	std::cout << std::endl;

	std::cout << "Please enter your divisor: ";

	if (!(std::cin >> divisor))
		throw input;
	if (divisor == 0)
		throw zero;

	std::cout << std::endl;

	quotient = dividend / divisor;
	std::cout << "Your quotient is " << quotient << std::endl;
	std::cout << std::endl;
}

void squareroot(){
	double num, answer;
	std::cout << "Please enter root: ";
	if (!(std::cin >> num))
		throw input;
	if (num < 0)
		throw root;
	answer = sqrt(num);
	std::cout << "The square root of " << num << " is " << answer << std::endl;
	std::cout << std::endl;
}

void exponent(){
	double exp,base, answer;
	std::cout << "Please enter base: ";
	if (!(std::cin >> base))
		throw input;
	std::cout << "Please enter exponent: ";
	if (!(std::cin >> exp))
		throw input;
	answer = pow(base, exp);
	std::cout << base << " raised to the power of " << exp << " is " << answer << std::endl;
	std::cout << std::endl;
}