//Lab11
//Programmed by: Adrian Ionascu
#include<iostream>
#include<string>


int isPalindrome(std::string str1)
{
	int posi;		//declaring variables
	int diff;
	bool check;		//declaring boolean variable
	posi = (str1.length())-1;		//get max character position

	for (int i = 0; i <= (posi / 2); i++)		//loops for most of the word length
	{
		char a = str1.at(posi - i); char b = str1.at(0 + i);		//sets a and b to characters that are at opposite ends of the word
		if (a == b)		//checks if a and b are the same
			check = true;
		else
		{
			check = false;		//if a /= b then outputs false
			break;		//breaks out of the for loop so that check is not overwritten
		}
	}
	return check;		//returns the bool value of check to the main function
}

int main()
{
	std::string input;		//declaring variables
	bool check;
	std::cout << "Input a word to check if it's a palindrome: ";		//asks for input
	std::cin >> input;		//inputs word
	check = isPalindrome(input);		//uses input in function "isPalindrome"
	if (check == true)		//outputs according to the bool state of "check"
		std::cout << "The input is a palindrome string." << std::endl;
	else
		std::cout << "The input is NOT a palindrome string." << std::endl;
}