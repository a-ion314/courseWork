//Project 1 Extra Credit Part 2
//Programmed by: Adrian Ionascu
#include<iostream>
#include<string>

void AMPM();
void militaryTime();
void output(int input, int conHour, int minutes, std::string time, int convert);
void input();
void menu();

void menu()
{
	std::cout << "Time Converter" << std::endl; std::cout << std::endl;
	std::cout << "1. 12-hour >> 24-hour" << std::endl;
	std::cout << "2. 24-hour >> 12-hour" << std::endl;
}
void input()
{
	int choice;
	std::cin >> choice;
	std::cout << std::endl;
	switch (choice){
	case 1: militaryTime();
		break;
	case 2: AMPM();
		break;
	default:
		std::cout << "That is not a valid choice." << std::endl;
	}
}
void AMPM()
{
	int hour, minutes, input, convert = 2, hour12;
	std::string time = "AM";
	std::cout << "Please input time in format of military time between 0000 and 2400." << std::endl;
	std::cout<< "(Example: 1300)" << std::endl;
	std::cin >> input;
	hour = input / 100;
	minutes = input % 100;
	if ((input < 0000) || (input > 2400))
		std::cout << "Input must be between 0000 and 2400." << std::endl;
	else if ((minutes < 0) || (minutes > 59))
		std::cout << "Minutes must be greater than or equal to 0 or less than 60." << std::endl;
	else
	{
		if (hour == 0 || hour == 24)
			hour12 = 12;
		else if ((hour / 12) > 0)
		{
			time = "PM";
			hour12 = hour % 12;
		}
		output(input, hour12, minutes, time,convert);
	}
}
void militaryTime()
{
	int hour, minutes, convert = 1, hour24,input;
	std::string time = " ";
	std::cout << "Please input the time in the format of hh:mm followed by AM or PM." << std::endl;
	std::cout << "(Example: 1:45 PM)" << std::endl;
	std::cin >> input;
	std::cin.ignore(100, ':');
	std::cin >> minutes;
	std::cin >> time;
	if (time == "PM")
		hour = input + 12;
	output(input,hour,minutes,time,convert);
}
void output(int input, int conHour, int minutes, std::string time, int convert)
{
	std:: cout << std::endl;
	if (convert == 2){
		if (minutes <= 9)
			std::cout << input << " converted from military to 12-hour format is " << conHour << ":" << "0"<<minutes<<" " << time << std::endl;
		else
			std::cout << input << " converted from military to 12-hour format is " << conHour << ":" << minutes << " " << time << std::endl;
	}
	else if (convert == 1)
	{
		if (minutes <= 9)
			std::cout << input << ":0" << minutes <<" "<<time<< " converted from 12-hour format to military is " << conHour <<"0"<< minutes << std::endl;
		else
			std::cout << input << ":" << minutes <<" "<<time << " converted from 12-hour format to military is " << conHour << minutes << std::endl;
	}
}
void main()
{
	menu();
	input();
}