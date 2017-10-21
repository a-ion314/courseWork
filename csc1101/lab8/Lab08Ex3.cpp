//Lab 08 Ex3
//Programmed by: Adrian Ionascu
#include<iostream>

int main()
{
	int size,even,col,col2,odd;
	std::cout << "Please input size of checkerboard: ";
	std::cin >> size;
	even = size / 2;

	if ((size > 0) && (size % 2 == 0)){
		for (even > 0; even--;) {
			for (col = size / 2; col > 0; col--) {
				std::cout << " #";
			}
			std::cout << std::endl;
			for (col2 = size / 2; col2 > 0; col2--) {
				std::cout << "# ";
			}
			std::cout << std::endl;
		}
	}
	else if ((size > 0) && (size % 2 == 1)){
		for (even > 1; even--;) {
			for (col = size / 2; col > 0; col--) {
				std::cout << " #";
			}
			std::cout << " ";
			std::cout << std::endl;
			for (col2 = size / 2; col2 > 0; col2--) {
				std::cout << "# ";
			}
			std::cout << "#";
			std::cout << std::endl;
		}
		for (col = size / 2; col > 0; col--) {
			std::cout << " #";
		}
		std::cout << " ";
		std::cout << std::endl;
	}
	else
		std::cout << "Please enter a number greater than 0" << std::endl;

	return 0;
}