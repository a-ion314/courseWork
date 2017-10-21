//written by: Adrian Ionascu
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

int main()
{
	std::string first, last;
	std::ofstream out; std::ifstream in; 
	in.open("Lab2_Ex3_Input.txt"); //open file for reading
	out.open("Lab2_Ex3_Ouput.txt"); //open file for writing
	double salary, increase, newSalary; 
	
	out << std::showpoint << std::fixed << std::setprecision(2); //set all number to be rouded to two digits after decimal
	in >> last >> first >> salary >> increase; newSalary = salary * increase; //save variables for first line
	out << first << " " << last << " " << newSalary << std::endl; //write output for first line

	in >> last >> first >> salary >> increase; newSalary = salary * increase;
	out << first << " " << last << " " << newSalary << std::endl; //writes output for second line but added set fixed and 

	in >> last >> first >> salary >> increase; newSalary = salary * increase;
	out << first << " " << last << " " << newSalary << std::endl;
	
	std::cout << "Output has been written to Lab2_Ex3_Output.txt\n";
	fcloseall; //closes files associated with fstream
	
	in.close(); 
	out.close(); //these can be used instead of fcloseall

	return 0;
}