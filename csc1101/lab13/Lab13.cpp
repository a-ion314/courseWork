//Lab13
//Programmed by: Adrian Ionascu
#include<iostream>

int fibonacci(int n)		//calulates fibonacci number
{
	int f1 = 0, f2 = 1, parent = 0;
	if (n < 0)
		std::cout << "Not a valid input" << std::endl;		//doesnt allow negative numbers
	else if (n >= 1)
		std::cout << 1 << std::endl;		//adds first fibonnaci number

	for (int i = 1; i < n; i++)		//calculates every number after the first
	{
		parent = f1 + f2;
		f1 = f2;
		f2 = parent;
		std::cout << parent << std::endl;
	}
	return 0;
}

int main()
{
	int num;
	std::cout << "Please input N: ";		//asks for input
	std::cin >> num;
	fibonacci(num);		//calls function using input

	return 0;
}