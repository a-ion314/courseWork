//Lab06 Q3
//programmed by: Adrian Ionascu
#include<iostream>

int main()
{
	int P = 0;
	char G;

	std::cout << "Please input a percentage, 0-100: " << std::endl;
	std::cin >> P;

	if (P >= 90 && P <= 100)
		G = 'A';
	else if (P >= 80 && P <= 89)
		G = 'B';
	else if (P >= 70 && P <= 79)
		G = 'C';
	else if (P >= 60 && P <= 69)
		G = 'D';
	else if (P >= 0 && P <= 59)
		G = 'F';
	else
		std::cout << "Invalid Number" << std::endl;

	std::cout << "Your letter grade is " << G << std::endl;

	return 0;
}