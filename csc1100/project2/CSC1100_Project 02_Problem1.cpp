//Project 2 Part 01
//Programmed by: Adrian Ionascu
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>

int seats[13][6];

void grid();
void menu();
void ticket();
void initialize();

void initialize()
{
	for (int i = 0; i <= 12; i++)		//initializes array
	{
		for (int j = 0; j <= 5; j++)
		{
			seats[i][j] = 0;
		}
	}
	grid();
}

void grid()		//outputs entire grid
{
	std::cout << std::setw(6) << " ";		
	std::cout << " "<<std::setw(2) << "A" << std::setw(2) << "B" << std::setw(2) << "C" << std::setw(2) << "D" << std::setw(2) << "E" << std::setw(2) << "F" << std::endl;
	int n = 1;
	for (int i = 0; i <= 12; i++)
	{
		std::cout << std::setw(4) << "Row " << std::setw(2) << std::right << n << " ";
		n++;
		for (int j = 0; j <= 5; j++)
		{
			if (seats[i][j] == 0)		//checks to see which seats are taken
				std::cout << std::setw(2) << "*";
			else
				std::cout << std::setw(2) << "X";
		}
		std::cout << std::endl;
	}
	std::cout << "* -- available seat" << std::endl << "X -- occupied seat" << std::endl;
}

void ticket()		//lets user pick ticket type
{
	char type,seat;
	int row,ascii;
	std::cout << "Enter ticket type: F (first class);  B (business class); E (economy class): ";
	std::cin >> type;
	if (type == 'F')
	{
		std::cout << "Enter row number 1 - 2: ";
		std::cin >> row;
		if ((row >= 1) && (row <= 2))		//checks for appropriate row
		{
			std::cout << "Enter seat number (A - F)(Capital letters only): ";
			std::cin >> seat;
			if ((seat >= 'A') && (seat <= 'F'))
			{
				ascii = static_cast<int>(seat) - 65;
				row = row - 1;
				std::cout << ascii << std::endl;
				seats[row][ascii] = 5;
			}
			else
				ticket();
		}
		else
			ticket();
	}
	else if (type == 'B')
	{
		std::cout << "Enter row number 3 - 7: ";
		std::cin >> row;
		if ((row >= 3) && (row <= 7))
		{
			std::cout << "Enter seat number (A - F)(Capital letters only): ";
			std::cin >> seat;
			if ((seat >= 'A') && (seat <= 'F'))
			{
				ascii = static_cast<int>(seat) - 65;
				row = row - 1;
				seats[row][ascii] = 5;
			}
			else
				ticket();
		}
		else
			ticket();
	}
	else if (type == 'E')
	{
		std::cout << "Enter row number 8 - 13: ";
		std::cin >> row;
		if ((row >= 8) && (row <= 13))
		{
			std::cout << "Enter seat number (A - F)(Capital letters only): ";
			std::cin >> seat;
			if ((seat >= 'A') && (seat <= 'F'))
			{
				ascii = static_cast<int>(seat) - 65;		//converts letter to value then subtracts 65 to find appropriate column in array
				row = row - 1;
				seats[row][ascii] = 5;
			}
			else
				ticket();
		}
		else
			ticket();
	}
	grid();
	menu();
}

void menu()		//asks user if they would like to reserve a seat
{
	std::string input;
	std::cout << "To reserve a seat enter Y/y(Yes), N/n(No): ";
	std::cin >> input;
	if ((input == "Y") || (input == "y"))
		ticket();
	else if ((input == "N") || (input == "n"))
		std::cout << std::endl;
	else
		menu();
}

void main()		//outputs instructions
{
	std::cout << "This Program assigns seats for a commercial airplane." << std::endl;
	std::cout << "The current seat assignments is as follows." << std::endl;
	initialize();
	std::cout << "Rows 1 and 2 are for first class passengers." << std::endl;
	std::cout << "Rows 3 through 7 are for business class passengers." << std::endl;
	std::cout << "Rows 8 through 13 are for economy class passengers." << std::endl;
	menu();
}