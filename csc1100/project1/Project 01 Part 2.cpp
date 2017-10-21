//Project 1 Part 02
//Programmed by: Adrian Ionascu
#include<iostream>

void divideFractions();
void multiplyFractions();
void subtractFractions();
void addFractions();
void reduce(int n3,int d3);
void output(int n1, int n2, int n3, int d1, int d2, int d3, char sign);

void menu()
{
	std::cout << "This is a fraction calculator.\n\n";
	std::cout << "To ender data you must input the numerator and denominator" << std::endl
		<< "of the first fraction, then the second fraction.\n\n";
	std::cout << "Please enter a number to select your operation." << std::endl;
	std::cout << "1. Multiplication" << std::endl;
	std::cout << "2. Division" << std::endl;
	std::cout << "3. Addition" << std::endl;
	std::cout << "4. Subtraction" << std::endl;
	int choice;

	std::cin >> choice;

	switch (choice){
	case 1: multiplyFractions();
		break;
	case 2: divideFractions();
		break;
	case 3: addFractions();
		break;
	case 4: subtractFractions();
		break;
	default: std::cout << "Please enter a valid choice." << std::endl;

	}

}
void addFractions()
{
	int n1, d1, n2, d2, n3, d3;
	std::cout << std::endl;
	std::cout << "first numerator: ";
	std::cin >> n1;
	std::cout << "first denominator: ";
	std::cin >> d1;
	std::cout << "second numerator: ";
	std::cin >> n2;
	std::cout << "second denominator: ";
	std::cin >> d2;

	if ((d2 == 0) || (d1 == 0))
		std::cout << "The denominators of either fractions cannot be 0." << std::endl;
	else
	{
		n3 = ((n1*d2) + (d1*n2));
		d3 = (d1*d2);
		output(n1, n2, n3, d1, d2, d3, '+');
	}
}
void subtractFractions()
{
	int n1, d1, n2, d2, n3, d3;
	std::cout << std::endl;
	std::cout << "first numerator: ";
	std::cin >> n1;
	std::cout << "first denominator: ";
	std::cin >> d1;
	std::cout << "second numerator: ";
	std::cin >> n2;
	std::cout << "second denominator: ";
	std::cin >> d2;

	if ((d2 == 0) || (d1 == 0))
		std::cout << "The denominators of either fractions cannot be 0." << std::endl;
	else
	{
		n3 = ((n1*d2) - (d1*n2));
		d3 = (d1*d2);
		output(n1, n2, n3, d1, d2, d3, '-');
	}
}
void multiplyFractions()
{
	int n1, d1, n2, d2,n3, d3;
	std::cout << std::endl;
	std::cout << "first numerator: ";
	std::cin >> n1;
	std::cout << "first denominator: ";
	std::cin >> d1;
	std::cout << "second numerator: ";
	std::cin >> n2;
	std::cout << "second denominator: ";
	std::cin >> d2;

	if ((d2 == 0) || (d1 == 0))
		std::cout << "The denominators of either fractions cannot be 0." << std::endl;
	else
	{
		n3 = n1 * n2;
		d3 = d1 * d2;
		output(n1, n2, n3, d1, d2, d3, '*');
	}
}
void divideFractions()
{
	int n1, d1, n2, d2, n3, d3;
	std::cout << std::endl;
	std::cout << "first numerator: ";
	std::cin >> n1;
	std::cout << "first denominator: ";
	std::cin >> d1;
	std::cout << "second numerator: ";
	std::cin >> n2;
	std::cout << "second denominator: ";
	std::cin >> d2;

	if ((d2 == 0) || (d1 == 0))
		std::cout << "The denominators of either fractions cannot be 0." << std::endl;
	else
	{
		n3 = (n1*d2);
		d3 = (d1*n2);
		output(n1, n2, n3, d1, d2, d3, '/');
	}
	
}
void reduce(int n3, int d3)
{
	int div, num, den;
	for (int i = 0; i < d3; i++)	
	{
		div = d3 - i;
		if ((n3 % div) == 0 && (d3 % div) == 0)
			break;
	}
	num = n3 / div;
	den = d3 / div;
	if ((num == n3) && (den == d3))
		std::cout << n3 << "/" << d3 << " cannot be reduced." << std::endl;
	else
		std::cout << n3 << "/" << d3 << " reduced is " << num << "/" << den << std::endl;
}
void output(int n1, int n2, int n3, int d1, int d2, int d3, char sign)
{
	std::cout << n1 << "/" << d1 << " " << sign << " " << n2 << "/" << d2 << "  =  " << n3 << "/" << d3 << std::endl;
	reduce(n3, d3);
}
int main()
{
	menu();
	return 0;
}

