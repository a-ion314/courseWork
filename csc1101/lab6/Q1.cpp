//Lab06 Q1
//programmed by: Adrian Ionascu

#include<iostream>

int main()
{
	double x, y, z;
	std::cout << "Please input 3 numbers" << std::endl;
	std::cin >> x >> y >> z;
	std::cout << "The numbers in descending order are: " << std::endl;
	
	if (x > y && y > z)
		std::cout << x << " " << y << " " << z << std::endl;
	else if (x > z && z > y)
		std::cout << x << " " << z << " " << y << std::endl;
	else if (y > x && x > z)
		std::cout << y << " " << x << " " << z << std::endl;
	else if (y > z && z > x)
		std::cout << y << " " << z << " " << x << std::endl;
	else if (z > x && x > y)
		std::cout << z << " " << x << " " << y << std::endl;
	else
		std::cout << z << " " << y << " " << x << std::endl;


	return 0;
}