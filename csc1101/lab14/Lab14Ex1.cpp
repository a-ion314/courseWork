//Lab14Ex1
//Programmed by: Adrian Ionascu
#include<iostream>

int input()
{
	int num;
	std::cout << "Please input number: ";
	std::cin >> num;
	return num;
}
int isPower(int num)
{
	if (num == 0)
		return false;
	while (num != 1)
	{
		if (num % 2 != 0)
			return false;
		num = num / 2;
	}
	return true;
}
int main()
{
	int num;
	bool output;
	num = input();
	output = isPower(num);
	if (output == false)
		std::cout << num << " is not a power of 2." << std::endl;
	else
		std::cout << num << " is a power of 2." << std::endl;

	return 0;
}