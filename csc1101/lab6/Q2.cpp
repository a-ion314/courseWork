//Lab06 Q2
//programmed by: Adrian Ionascu

#include<iostream>

int main()
{
	double sale, bonus;
	std::cout << "Please input sale amount in dollars: " << std::endl;
	std::cin >> sale;

	if (sale > 20000)
		bonus = 0.10;
	else if (sale > 10000 && sale <= 20000)
		bonus = 0.05;
	else
		bonus = 0;

	std::cout << "sale amount is " << sale << std::endl;
	std::cout << "bonus amount is " << bonus << std::endl;



	return 0;
}