//Programmed by: Adrian Ionascu
//CSC 1501 Lab 08 Program 3

#include<iostream>
#include<string>
#include<chrono>
#include<iomanip>

void program1(std::string in){
	std::string input;
	bool check = true;
	int found = -1;
	input = in;
	found = input.find(" ");

	if (found != -1){
		while (found != -1){
			input.erase(found, 1);
			found = input.find(" ");
		}
	}

	for (int i = 0; i < input.length(); i++){
		for (int j = 0; j < input.length(); j++){
			if ((input[i] == input[j]) && (i != j)){
				check = false;
				break;
				break;
			}
		}
	}
}

void program2(std::string in){
	bool check[256] = { 0 }, unique = true;
	std::string input;
	int found = -1;
	input = in;

	if (found != -1){
		while (found != -1){
			input.erase(found, 1);
			found = input.find(" ");
		}
	}

	for (int i = 0; i < input.length(); i++){
		bool temp = check[static_cast<int>(input[i])];
		if (temp == false){
			check[static_cast<int>(input[i])] = true;
		}
		else{
			unique = false;
			break;
		}
	}
}

using namespace std::chrono;

//when i run it using <time.h> i got all 0s but when i used high_resolution_clock
//and <chrono> i still got 0s but found that i get numbers when i use the debugger

void main(){
	std::string preset1 = "eu3g4";
	std::string preset2 = "EENx7n708K";
	std::string preset3 = "lxGXwwluS6Y8x8EtEUg4";
	std::string preset4 = "jK9kiAylNdzN1k1G43WLPSTZAvceAU3zkQP0MOBxb5Aj0ChkHX";
	std::string preset5 = "K1raL0JSbHyIkNtTC0ExRXg2q6bfUe7tqmvGFRsMDcIgwXtmFWnl8UBvN8VIy8I41SU9NpjPBtnfLy5Q";
	std::string preset6 = "FpjPgjmcdPjTvLLtW7bGAEgKjK4CMjxnBi43B88sex9wLzbyHyfHI8HxFY0Ae2Rvm1RSQVloFVlaEGiheb04tgRx6DQTre4tzKkT";
	std::string preset7 = "L4nbSLr8VlnZFkKVUSAriW1n69FQzTx7QIPXvlSOgdf4b3HaPEhMj8kVzrVOSLn2wXFRh0RHqVLrq3CL9HNvNpVHvEHQxE8hSMuX5TDMFvQMffCAiAvYEb6Kfk9JPlQlrEvtwHmpOqj5i5h5sVxti8";
	std::string preset8 = "oBHgHMTe6ogojawHd4pTTcTvE7XYoAlnf5sPJEoXBog5DiF7B1B1cYv0DHVWWpnmL5JvCmc9Ff5XyUmQWJvITzevUjTXxhYxrPLyDVqdLDE7QyPAvbZJQbWlIZPEDTvVLXkPaQAbD6ocUf78f7Mk0tPuwZSGegIBkweaiGzKd85DsmgfkCK8qmOK6vJVrydff5kP1u2u";
	std::string preset9 = "0mTSoigfjmahoT7NOIZPy5c8ISGHf2pnDMJB5eRikBHbnjCNsz9ta6xOge0iuw2jcxmDpA0lv1PioDLhHHRJ0yOtxESbL73KdG9hHJJYO5hay1YLmibfNce3KeTj1tVbGMgKifevy5Rcy5apv5xgfUnG3A6lb8hbl3Ef1Bzhtl8uncjU3JxMON2ZzBg4HwV2bdxzizhZiMfnXLDgJZtokmffpDSu5cQM5B7SQS5vOTZKvXKudZfV7npEdekLyZTz";

	std::cout << std::setw(15);
	std::cout << std::left << "String length" << std::setw(5) << " ";
	std::cout << std::setw(15);
	std::cout << std::left << "Program1 time" << std::setw(5) << " ";
	std::cout << std::setw(15);
	std::cout << std::left << "Program2 Time" << std::setw(5) << " ";
	std::cout << std::endl;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;

	std::cout << std::setw(15);
	std::cout << std::left << preset1.length() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program1(preset1);
	t2 = high_resolution_clock::now();

	duration<double> time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left <<  time.count() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program2(preset1);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";
	std::cout << std::endl;



	std::cout << std::setw(15);
	std::cout << std::left << preset2.length() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program1(preset2);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program2(preset2);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";
	std::cout << std::endl;



	std::cout << std::setw(15);
	std::cout << std::left << preset3.length() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program1(preset3);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program2(preset3);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";
	std::cout << std::endl;



	std::cout << std::setw(15);
	std::cout << std::left << preset4.length() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program1(preset4);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program2(preset4);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";
	std::cout << std::endl;



	std::cout << std::setw(15);
	std::cout << std::left << preset5.length() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program1(preset5);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program2(preset5);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";
	std::cout << std::endl;



	std::cout << std::setw(15);
	std::cout << std::left << preset6.length() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program1(preset6);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program2(preset6);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";
	std::cout << std::endl;



	std::cout << std::setw(15);
	std::cout << std::left << preset7.length() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program1(preset7);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program2(preset7);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";
	std::cout << std::endl;



	std::cout << std::setw(15);
	std::cout << std::left << preset8.length() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program1(preset8);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program2(preset8);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";
	std::cout << std::endl;



	std::cout << std::setw(15);
	std::cout << std::left << preset9.length() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program1(preset9);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";

	t1 = high_resolution_clock::now();
	program2(preset9);
	t2 = high_resolution_clock::now();

	time = t2 - t1;
	std::cout << std::setw(15);
	std::cout << std::left << time.count() << std::setw(5) << " ";
	std::cout << std::endl;
}