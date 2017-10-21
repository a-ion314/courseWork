//Programmed by: Adrian Ionascu
//CSC 1501 Lab 07 Program 1
#include<iostream>
#include<fstream>

int gcd(int a, int b);

void main(){
	std::ifstream doc; std::ofstream output;
	doc.open("A1.txt");
	output.open("B1.txt");
	int a, b, c;

	while (true){
		c = 0;
		doc >> a >> b;

		if (doc.get() == '\n'){
		}
		else{
			doc >> c;
		}

		if (doc.eof())
			break;

		output << gcd(a, (gcd(b, c))) << std::endl;
	}

	doc.close();
	output.close();
}

int gcd(int a, int b){
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}