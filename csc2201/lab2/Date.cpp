
#include "Date.h"
#include <ctime>

Date::Date()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	day = timePtr->tm_mday;
	month = timePtr->tm_mon + 1;
	year = 1900 + timePtr->tm_year;
}

Date::Date(int input_day, int input_month, int input_year) throw (logic_error)
{
	if ((input_day > daysInMonth(input_month, input_year)) || input_day < 1){
		throw;
	}
	else if (input_month > 12 || input_month < 1)
		throw;
	else{
		day = input_day;
		month = input_month;
		year = input_year;
	}
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

//in show2.cpp
//void showStructure() const;


bool Date::isLeapYear(int year)
{
	if (year % 4 == 0){
		if (year % 100 == 0){
			if (year % 400 == 0){
				return true;
			}
			else return false;
		}
		else return true;
	}
	else return false;
}

int Date::daysInMonth(int month, int year)
{
	switch (month){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: return 30;
		break;
	case 2: if (isLeapYear(year)){
				return 29;
			}
			else return 28;
			break;
	}
}

int Date::getDayOfWeek() const
{
	tm timeStruct = {};
	timeStruct.tm_year = year - 1900;
	timeStruct.tm_mon = month - 1;
	timeStruct.tm_mday = day;
	mktime(&timeStruct);
	return timeStruct.tm_wday;
}

bool Date::operator<(const Date& rhs) const
{
	if (year > rhs.year)
		return false;
	else if (year < rhs.year)
		return true;
	else{
		if (month > rhs.month)
			return false;
		else if (month < rhs.month)
			return true;
		else{
			if (day < rhs.day)
				return true;
			else
				return false;
		}
	}
}

bool Date::operator==(const Date& rhs) const
{
	if ((day == rhs.day) && (month == rhs.month) && (year == rhs.year))
		return true;
	else
		return false;
}

bool Date::operator>(const Date& rhs) const
{
	if (year < rhs.year)
		return false;
	else if (year > rhs.year)
		return true;
	else{
		if (month < rhs.month)
			return false;
		else if (month > rhs.month)
			return true;
		else{
			if (day > rhs.day)
				return true;
			else
				return false;
		}
	}
}

ostream& operator<<(ostream& out, const Date& date)
{
	out << date.month << '/' << date.day << '/' << date.year;
	return out;
}