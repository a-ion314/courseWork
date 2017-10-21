//Programmed by: Adrian Ionascu CSC 1501 Lab 06 Program 4
#include<iostream>

void main(){
	int a, b, large;

	std::cout << "Please input 2 non zero positive numbers: ";
	while (true){
		std::cin >> a >> b;
		if ((a == 0) || (b == 0))
			std::cout << "Invalid input.\n";
		else break;
	}

	if (a > b)
		large = a;
	else large = b;

	do{
		if ((large % a == 0) && (large % b == 0)){
			std::cout << "The Least Common Multiple is: " << large << std::endl;
			break;
		}
		else
			large = large + 1;
	} while (true);

}