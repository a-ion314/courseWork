//Lab08
//Programmed by: Adrian Ionascu
#include<iostream>
#include<fstream>
#include<string>

int main()
{
	std::ifstream apple;					//opens input stream

	apple.open("salaries.txt");				//opens text file
	int salary,jeans = 0;					//set variables
	std::string bottom = "a", name;
	apple >> bottom >> jeans;				//boots with the fur	//reads first line and saves them to variables

	for (int i = 0; i < 10000; i++){		//checks to see if next salary amount is larger, if so, replaces the previously saved values; does this for an arbitrary amount of values
		apple >> name >> salary;
		if (salary < jeans) continue;
		jeans = salary; bottom = name;
	}
	apple.close();							//closes file
	std::cout << "The largest salary is: " << bottom << " " << jeans << std::endl;	//outputs largest salary


	return 0;
}