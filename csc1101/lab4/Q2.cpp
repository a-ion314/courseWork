#include<iostream>
#include<iomanip>

int main()
{
	double kilos, pounds;
	std::cout << "Please input your weight in kilograms: ";
	
	std::cin >> kilos;
	std::cout << std::showpoint << std::fixed << std::setprecision(2);
	pounds = kilos * 2.2;
	std::cout << "Your weight in kilograms is " << kilos << std::endl 
		<< "Your weight in pounds is " << pounds << std::endl;


	return 0;
}