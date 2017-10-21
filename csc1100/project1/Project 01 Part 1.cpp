//Project 1 Part 1
//programmed by: Adrian Ionascu
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

void generateNew(int correct, int x1, int x2, int x3);
void correctAnswer();
void wrongAnswer();
void percentage();
void main();
void menu();

double wrong = 0, right = 0;
int start = 1, problem = 0, mod = 0;


void menu() // sets a difficulty menu
{
	int difficulty;
	if (start == 1)
	{
		std::cout << "1. Easy" << std::endl;
		std::cout << "2. Medium" << std::endl;
		std::cout << "Please select difficulty level: ";
		std::cin >> difficulty;
		switch (difficulty){
		case 1: mod = 10;		// changes the amount of digits in the value
			start++;
			break;
		case 2: mod = 100;
			start++;
			break;
		default: std::cout << "That is not a valid answer for difficulty." << std::endl;
			main();
		}
	}
	std::cout << "1. Addition" << std::endl;
	std::cout << "2. Subtraction" << std::endl;
	std::cout << "3. Multiplication" << std::endl;
	std::cout << "4. Division" << std::endl;
	std::cout << "5. Random" << std::endl;
	std::cout << "Please select type of problems: "; // outputs menu for choice
	std::cin >> problem;
}
void generateNew(int correct, int x1, int x2, int x3)	//generates random problems to solve
{
	int answer, calc, temp=problem;
	std::string phrase;
	srand(time(0));
	if (!((right + wrong) == 10))
	{
		if (correct == 1)
		{
			x1 = rand() % mod;
			x2 = rand() % mod;
			switch (problem){
			case 1: x3 = x1 + x2;		//changes problem according to user input
				break;
			case 2: x3 = x1 - x2;
				break;
			case 3: x3 = x1 * x2;
				break;
			case 4: x3 = x1 / x2;
				break;
			case 5: calc = (rand() % 4) + 1;
				temp = calc;
				switch (calc){		//randomly chooses a prolem type for the user
				case 1: x3 = x1 + x2;
					break;
				case 2: x3 = x1 - x2;
					break;
				case 3: x3 = x1 * x2;
					break;
				case 4: x3 = x1 / x2;
					break;
				}
				break;
		}
			switch (temp){
			case 1: phrase = "plus";		//changes phrase for output
				break;
			case 2: phrase = "minus";
				break;
			case 3: phrase = "times";
				break;
			case 4: phrase = "divided by";
				break;
			}
		}
		std::cout << "What is " << x1 << " " << phrase << " "<< x2 << "? ";
		std::cin >> answer;
		if (answer == x3)
		{
			correctAnswer();		//calls function if problem is correct
			generateNew(1, x1, x2, x3);
		}
		else
		{
			wrongAnswer();		//calls function if problem is wrong
			generateNew(0, x1, x2, x3);
		}
	}
	else
		percentage();
}

void correctAnswer()	//gives a random output when the answer is correct
{
	int x1;
	srand(time(0));
	x1 = (rand() % 4) + 1;
	right++;

		switch (x1){
		case 1:	std::cout << "Very good!" << std::endl;		//randomly outputs phrases
			std::cout << std::endl;
			break;
		case 2: std::cout << "Excellent!" << std::endl;
			std::cout << std::endl;
			break;
		case 3: std::cout << "Nice work!" << std::endl;
			std::cout << std::endl;
			break;
		case 4: std::cout << "Keep up the good work!" << std::endl;
			std::cout << std::endl;
			break;
		}
}

void wrongAnswer()	//gives random output when answer is wrong
{
	int x1,questions=0;
	srand(time(0));
	x1 = (rand() % 4) + 1;
	wrong++;
	
		switch (x1){
		case 1:	std::cout << "No. Please try again." << std::endl;
			std::cout << std::endl;
			break;
		case 2: std::cout << "Wrong. Try once more." << std::endl;
			std::cout << std::endl;
			break;
		case 3: std::cout << "Don't give up!" << std::endl;
			std::cout << std::endl;
			break;
		case 4: std::cout << "No. Keep trying." << std::endl;
			std::cout << std::endl;
			break;
		}
}
void percentage()
{
	double correctPerc;
	correctPerc = (right / 10.0);		//calculates percentage and outputs appropriate phrase
	if (correctPerc < 0.75)
	{
		std::cout << "Please ask your teacher for extra help." << std::endl;
		std::cout << std::endl;
		main();
	}
	else
	{
		std::cout << "Congratulations, you are ready to go to the next level!" << std::endl;
		std::cout << std::endl;
		main();
	}
}
void main()
{
	right = 0, wrong = 0, start = 1;	//resets vales and starts the function
	menu();
	generateNew(1,0,0,0);

}