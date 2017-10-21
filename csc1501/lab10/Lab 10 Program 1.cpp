//Programmed by: Adrian Ionascu
//CSC 1501 Lab 10 program 1

#include<fstream>
#include<iostream>

double factorial(int num);

void main(){
	std::ifstream input; std::ofstream output;

	input.open("A1.txt"); output.open("B1.txt");

	int first, second;
	double combinations, permutations;

	while (!(input.eof())){
		input >> first;
		input >> second;

		if ((first > 0) && (second >= 0) && (second <= first)){
			permutations = (factorial(first)) / (factorial(first - second));
			combinations = factorial(first) / (factorial(second)*(factorial(first - second)));
			output.setf(std::ios_base::fixed); output.precision(0);
			output << first << " " << second << " " << permutations << " " << combinations << std::endl;
		}
		else
			output << first << " " << second << " r > n error" << std::endl;
	}
}

double factorial(int num){
	if (num == 1)
		return 1;
	else
		return (num * factorial(num - 1));
}