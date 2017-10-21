//Lab12Ex2
//Programmed by: Adrian Ionascu
#include<iostream>

double inflation(double curr, double year_1)		//calculates inflation rate
{
	double infRate = ((curr - year_1) / year_1);
	return infRate;
}
double output(double  infRate1, double  infRate2)		//outputs as needed
{
	std::cout << "Inflation rate for current price to one year prior is: " <<infRate1<< std::endl;
	std::cout << "Inflation rate for the previous year to two years prior is: " <<infRate2 <<std::endl;		//outputs inflation rates for years inputted

	if (infRate1 > infRate2)		//will output if inflation is increasing or decreasing depending on situation
		std::cout << "Inflation is increasing." << std::endl;
	else if (infRate1 == infRate2)
		std::cout << "Inflation is neither increasing or decreasing." << std::endl;
	else
		std::cout << "Inflation is decreasing." << std::endl;

	return 0;

}
int main()
{
	double curr, year_1, year_2;
	std::cout << "Please input the current price of an item: ";		//asks for input
	std::cin >> curr;
	std::cout << "Please input the price of the same item a year ago: ";
	std::cin >> year_1;
	std::cout << "Please input the price of the same item two years ago: ";
	std::cin >> year_2;

	double infRate1 = inflation(curr, year_1);		//calculates inflation for two numbers at a time
	double infRate2 = inflation(year_1, year_2);
	output(infRate1, infRate2);		//sends inflation to the final output function
}