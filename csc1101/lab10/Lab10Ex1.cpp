#include<iostream>

int reverseDigit(int num)
{
	int rem,pos;						//declare variables
	pos = abs(num);
	
	if (num > 0)						//checks if the number is greater than 0
	{
		while (num != 0)
		{
			rem = num % 10;
			std::cout << rem;
			num = num / 10;
		}
	}
	else if (num < 0)					//checks to see if the number is less than zero
	{
		std::cout << "-";				//outputs the negative symbol
		while (pos != 0)				//performs the while statement with the absolute value of the number
		{
			rem = pos % 10;
			std::cout << rem;
			pos = pos / 10;
		}
	}
	else
		std::cout << 0;
	return 0;
}

int main()
{
	int num;
	std::cout << "Enter an integer: ";
	std::cin >> num;										//gets input
	std::cout << "The reverse of your integer is: ";
	reverseDigit(num);										//calls upon reverseDigit
	std::cout << std::endl;
	
	return 0;
}
