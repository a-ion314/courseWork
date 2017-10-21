//Lab14Ex2
//Programmed by: Adrian Ionascu

#include<iostream>

int factorial(int num)
{
	int facto = 1;
	int i = num;
	int orig = num;
	for (i > 0; i--;)		//loops for the duration of the factorial opteration
	{
		facto = facto * num;		//multiplies itself by num
		num--;		//decreses num by 1 for the next loop
	}
	std::cout << orig << "! is " <<facto << std::endl;		//outputs answer
	return 0;
}
int input()
{
	int num;
	std::cout << "Please input a positive integer number: ";		//prompts for input
	std::cin >> num;

	if (num < 0)		//checks for negative numbers
		std::cout << "Input is invalid" << std::endl;
	else
		return num;		//any number that Is not negative goes to the factorial function

	return 0;
}
int main()
{
	int inp;
	inp = input();		//starts input
	factorial(inp);
	return 0;
}