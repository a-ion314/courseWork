//Programmed by: Adrian Ionascu CSC 1501 Lab 06 Program 5
#include<iostream>

void gcd(int a, int b, int &output){
	int divisor;
	for (int i = 0; i < b; i++){
		divisor = b - i;
		if ((a % divisor) == 0 && (b % divisor) == 0)
			break;
	}
	output = divisor;
}

void change(int &a, int &b){
	int c;
	c = a;
	a = b;
	b = c;
}

void main(){
	int a, b, output;

	std::cout << "Please enter two non zero positive integers: ";
	while (true){
		std::cin >> a >> b;
		if ((a == 0) || (b == 0)){
			std::cout << "Invalid input.\n";
		}
		else break;
	}

	if (a < b)
		change(a, b);

	gcd(a, b, output);

	if (output == 1){
		std::cout << "These numbers are co-prime." << std::endl;
	}
	else
		std::cout << "These numbers are not co-prime." << std::endl;

}