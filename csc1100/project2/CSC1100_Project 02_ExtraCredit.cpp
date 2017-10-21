//Project 2 EC part 1
//Programmed by: Adrian Ionascu
#include<iostream>
#include<time.h>

void main();

void lotto()
{
	int random[5] = { 0, 0, 0, 0, 0 };
	int answer[5] = { 0, 0, 0, 0, 0 };			//sets arrays
	srand(time(NULL));		//set up for generating random numbers
	
	for (int i = 0; i < 5; i++)		//initializes entire array with randomly generated numbers
	{
		random[i] = rand() % 40 + 1;
		std::cout << random[i] << std::endl;
	}
	std::cout << "Enter five distinct integers between 1 and 40" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter a number: ";		//saves answers in array
		std::cin >> answer[i];
		if ((answer[i] == answer[i - 1]) || (answer[i] == answer[i + 1]) || (answer[i] == answer[i + 2]) || (answer[i] == answer[i + 3]) || (answer[i] == answer[i + 4]) || (answer[i] == answer[i - 2]) || (answer[i] == answer[i - 3]) || (answer[i] == answer[i - 4]))
		{
			std::cout << "Number already selected. Select Another." << std::endl;		//checks for already selected numbers
			i--;
		}
		else if ((answer[i] < 1) || (answer[i]>40))
		{
			std::cout << "Number must be between 1 and 40. Select another." << std::endl;		//checks for numbers out of range
			i--;
		}
	}
	if ((answer[0] == random[0]) && (answer[1] == random[1]) && (answer[2] == random[2]) && (answer[3] == random[3]) && (answer[4] == random[4]))		//checks to see if user guessed correctly
	{
		std::cout << "Congrats! You win!" << std::endl;
		std::cout << "Want to play again?" << std::endl;
		main();
	}
	else
	{
		std::cout << "Sorry you lose." << std::endl;
		std::cout << "Your answers were: " << answer[0] << " " << answer[1] << " " << answer[2] << " " << answer[3] << " " << answer[4] << " " << std::endl;		//outputs user inputs and correct answers
		std::cout << "The correct answers were: " << random[0] << " " << random[1] << " " << random[2] << " " << random[3] << " " << random[4] << " " << std::endl;
		std::cout << "Do you want to try again?" << std::endl;
		main();
	}



}

void main()
{
	char answer;
	std::cout << "Play lotto (Y/y)/(N/n): ";
	std::cin >> answer;
	if ((answer == 'Y') || (answer == 'y'))		//checks for yes or no
		lotto();
	else if ((answer == 'N') || (answer == 'n'))
		std::cout << std::endl;		//skips line and ends program
	else
		main();		//if no correct input is given then the function repeats
}