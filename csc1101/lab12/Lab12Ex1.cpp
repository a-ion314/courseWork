//Lab12Ex1
//Programmed by: Adrian Ionascu
#include<iostream>

int gcd(int a, int b)		//gcd function
{
	int div;
	for (int i = 0; i < b; i++)		//sets a loop to test for every number from b to 1
	{
		div = b - i;
		if ((a % div) == 0 && (b % div) == 0)		//if both numbers are evenly divisible, break the loop
			break;
	}
	std::cout << "The GCD of the two integers is: " << div << std::endl;		//outputs GCD
	return 0;
}
int main()
{
	int a, b, div = 0;
	std::cout << "Enter two non-zero integers: ";		//asks for user input
	std::cin >> a >> b;
	if (a == 0 || b == 0)		//if either a or b is 0, output error
		std::cout << "Invalid input. Both integers cannot be 0." << std::endl;
	else
		gcd(a, b);		//calls the function
	
}