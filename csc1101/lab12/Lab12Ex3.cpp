//Lab12Ex3
//Programmed by: Adrian Ionascu
#include<iostream>

int leap_year(int year)
{
	int leap;
	if ((year % 4 == 0) && !(year % 100 == 0))		//calculates if given year is a leap year
		leap = 1;
	else if ((year % 100 == 0) && (year % 400 == 0))
		leap = 1;
	else
		leap = 0;		//sets leap accordingly for calculation later

	return leap;
}
int days_in_month(int month, int leap)
{
	int days = 0;

	switch (month)		//adds days according to month given
	{
	case 12:
		days = days + 30;
	case 11:
		days = days + 31;
	case 10:
		days = days + 30;
	case 9:
		days = days + 31;
	case 8:
		days = days + 31;
	case 7:
		days = days + 30;
	case 6:
		days = days + 31;
	case 5:
		days = days + 30;
	case 4:
		days = days + 31;
	case 3:
		days = days + 28 + leap;		//adds the number from the given leap value in the even the year is a leap year
	case 2:
		days = days + 31;
	case 1:
		days = days + 0;
	}

	return days;
}
int day_number(int dim, int day)
{
	int day_number = dim + day;		//adds the days_in_month return value and the day value given

	return day_number;
}
int main()
{
	int month, day, year;
	std::cout << "Please input date in form of month-day-year: ";
	std::cin >> month; std::cin.ignore(100, '-');		//makes sure not to inclue the dash symbol
	std::cin >> day; std::cin.ignore(100, '-'); 
	std::cin >> year;
	int leap = leap_year(year);
	int dim = days_in_month(month, leap);
	int day_num = day_number(dim, day);

	std::cout << "The day number of the year is: " << day_num << std::endl;


	return 0;
}