//Lab14Ex3
//programmed by: Adrian Ionascu
#include<iostream>
#include<string>

int digits(long num)
{
	int odd = 0, even = 0, zero = 0, modu;
	
	while (!(num == 0))		//as long as the number isnt zero then it will loop
	{
		modu = num % 10;
		if (modu == 0)		//checks if the modulus is equal to 0, an odd number or an even number
			zero++;
		else if (modu % 2 == 0)
			even++;
		else
			odd++;
		num = num / 10;

	}
	std::cout << "The amount of odd digits is " << odd << std::endl;		//outputs
	std::cout << "The amount of even digits is " << even << std::endl;
	std::cout << "The amount of zero digits is " << zero << std::endl;
	return 0;
}
int input()
{
	long num;
	std::cout << "Please input an integer: ";		//prompts user for input
	std::cin >> num;

	return num;		//returns number to main function
}
int main()
{
	long num;
	num = input();
	digits(num);		//calls for the digits function
	return 0;
}
