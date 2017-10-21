//Programmed by: Adrian Ionascu
//CSC 1501 Lab 10 Program 2

#include<iostream>
#include<fstream>

double factorial(int num);

void main(){
	std::ifstream input; std::ofstream output;

	input.open("A2.txt"); output.open("B2.txt");

	int first, second;
	double combinations, permutations;

	while (!(input.eof())){
		input >> first;
		input >> second;

		if ((first > 0) && (second >= 0)){
			permutations = pow(static_cast<double>(first), static_cast<double>(second));
			combinations = factorial(first+second-1) / (factorial(second) * factorial(first-1));
			output.setf(std::ios_base::fixed); output.precision(0);
			output << first << " " << second << " " << permutations << " " << combinations << std::endl;
		}
		else
			output << first << " " << second << " num < 0 error" << std::endl;
	}
}

double factorial(int num){
	if (num == 1)
		return 1;
	else
		return (num * factorial(num - 1));
}