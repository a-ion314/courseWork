//Lab05
//Programmed by: Adrian Ionascu

#include <iostream>
#include<string>
#include<iomanip>
int main()
{
	int C1, C2;
	std::string state1 = "Michigan", state2 = "Ohio";
	double reg, mid, prem, gascost, travelcost, mpg, traveldis;
	std::cout << "Select state:\n" << "0 - " << state1 << std::endl << "1 - " << state2 << std::endl;
	std::cout << "Choice: ";
	std::cin >> C1;

	switch (C1){																			//outputs state based on input
	case (0) :
		std::cout << state1 << " selected\n";
		reg = 2.27; mid = 2.49; prem = 2.7;
		break;
	case (1) :
		std::cout << state2 << " selected\n";
		reg = 2.28; mid = 2.46; prem = 2.55;
		break;
	}
	std::cout << "Select gas type:\n" << "0 - Regular\n" << "1 - Midgrade\n" << "3 - Premium\n" << "Choice: ";			//prompts user for input
	std::cin >> C2;

	switch (C2){
	case (0) :
		std::cout << "Regular selected.\n";
		gascost = reg;
		break;
	case (1) :
		std::cout << "Midgrade selected.\n";
		gascost = mid;
		break;
	case(3) :
		std::cout << "Premium selected.\n";
		gascost = prem;
		break;
	}
	std::cout << "Input mpg: ";
	std::cin >> mpg;
	std::cout << "Input travel ditance: ";
	std::cin >> traveldis;
	
	travelcost = traveldis / mpg * gascost;
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	std::cout << "Your travel cost is $" << travelcost << std::endl;


	return 0;
}