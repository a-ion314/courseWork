#include<iostream>
#include<iomanip>

int main()
{
	int firstNum, secondNum, temp, check, sum = 0;
	
	std::cout << "Please input two integers from least to greatest: ";
	std::cin >> firstNum >> secondNum;

	if (secondNum < firstNum)
	{
		temp = firstNum;
		firstNum = secondNum;
		secondNum = temp;
	}
	if (firstNum < secondNum)
	{
		
			check = firstNum;
			std::cout << "Even Numbers between " << firstNum << " and " << secondNum << " are:";
			for (int i = 1; i < (abs(secondNum - firstNum)); i++)
			{
				check++;
				if (check % 2 == 0)
					std::cout << std::setw(3) << check;

			}
			std::cout << std::endl;
			std::cout << "Sum of all odd numbers between " <<firstNum << " and " <<secondNum << " are:  ";
			check = firstNum;
			for (int i = 1; i < (abs(secondNum - firstNum)); i++)
			{
				check++;
				if ((check % 2 == 1) || (check % 2 == -1))
					sum = sum + check;
			}
			std::cout << sum <<std::endl;
	}

	return 0;
}