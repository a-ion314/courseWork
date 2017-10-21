//Lab05
//programmed by: Adrian Ionascu
#include<fstream>
#include<string>
#include<iomanip>
#include<iostream>

int main()
{
	std::ifstream inFile; std::ofstream outFile;
	inFile.open("inData.txt");
	outFile.open("outData.txt");

	int age;
	double length, width, recArea, cirArea, radius, circm, startBal, interestRate ,endBal,pi = 3.14;
	std::string firstName, lastName;

	

	inFile >> length >> width >> radius >> firstName >> lastName >> age >> startBal >> interestRate;
	
	recArea = length * width;
	cirArea = pi * pow(radius, 2);
	circm = pi * radius * 2;
	endBal = startBal + (startBal * interestRate * 0.01) / 12.0;

	
	outFile << std::fixed << std::showpoint << std::setprecision(2);
	
	outFile << "Rectangle:\n" << "Length = " << length << ", width = " << width << ", area = " << recArea << std::endl;
	outFile << std::endl;
	outFile << "Circle:\n" << "Radius = " << radius << ", area = " << cirArea << ", circumference = " << circm << std::endl;
	outFile << "Name: " << firstName << " "<<lastName << ", age: " << age << std::endl;
	outFile << "Beginning balance = $" << startBal << ", Balance at the end of the month = $" << endBal << std::endl;

	inFile.close();
	outFile.close();

	return 0;
}