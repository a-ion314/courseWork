//Lab08
//Programmed by: Adrian Ionascu
#include<iostream>

int main()
{
	double num, newnum = 1;
	int check = 0;											//Declaring variables
	std::cout << "Please input 5 numbers: ";				//prompts user for input
	
	for (int i = 0; i < 5; i++){							//runs to input 5 numbers into variable num
		std::cin >> num;
		if (num < 0)										//incriments check for every negative number inputed
			check++;

		if (num < 0) continue;								//if inputs is greater than 0, it will multiply them all together
			newnum = newnum * num;
	}

	if (check == 5)
		std::cout << "No output is available" << std::endl; //if check is 5, then no output will be established
	else{
		std::cout << "The product of all positive numbers inputed is: " << std::endl;		//outputs number
		std::cout << newnum << std::endl;
	}

	return 0;
}