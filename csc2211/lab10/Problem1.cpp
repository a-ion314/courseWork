//Programmed by: Adrian Ionascu CSC 2111 Lab 10 Problem 1
#include<iostream>
#include<fstream>
#include<string>

class test{		//class that will hold information such as ID, answers, score and grade
public:
	test();
	void setID(std::string iden);		//functions to set and return private values
	void setAnswers(std::string ans);
	void setGrade(char letter);
	void setAnswerLength(int length);
	void test::setScore(double num);
	std::string getID();
	std::string getAnswers();
	double getScore();
	char getGrade();
private:
	std::string answers;
	std::string ID;
	double score;
	char grade;
};

test::test(){
};

void test::setID(std::string iden){
	ID = iden;
}

void test::setAnswerLength(int length){		//if the amount of answers are less than the length of the answer key (or the student didnt answer multiple questions at the end of the test) then space characters are added until they are of proper length
	int shift = 0;
	if (answers.length() < length){
		shift = length - answers.length();
		for (int i = 0; i < shift; i++){
			answers += " ";
		}
	}
}

void test::setGrade(char letter){
	grade = letter;
}

void test::setAnswers(std::string ans){
	answers = ans;
}

void test::setScore(double num){
	score = num;
}

std::string test::getID(){
	return ID;
}

std::string test::getAnswers(){
	return answers;
}

double test::getScore(){
	return score;
}

char test::getGrade(){
	return grade;
}

void getLength(std::istream& doc, int &length, int &lines, std::string& set);	//gets the length of the answer key and obtains data on how many objects should be made
void getData(test list[], std::istream& doc, int lines);		//obtains ID and student answers 
void checkAnswers(char answers[], test list[], int length, int lines);		//checks student answers and sets a score for them
void grade(test list[], int lines);		//gets the student's score and gives them a letter grade
void output(test list[],int lines);		//outputs data in proper format

void main(){
	std::ifstream doc;
	int length, lines;
	std::string str1;
	doc.open("Lab 10.1Data.txt");
	getLength(doc, length, lines, str1);

	char *answers;
	answers = new char[length];

	for (int i = 0; i < length; i++){
		answers[i] = str1[i];
	}

	test *list;
	list = new test[lines];

	getData(list, doc, lines);

	for (int i = 0; i < lines; i++){
		list[i].setAnswerLength(length);
	}

	checkAnswers(answers, list, length, lines);
	grade(list, lines);
	output(list, lines);
	doc.close();

	delete answers;
	answers = NULL;

	delete list;
	list = NULL;
}

void getLength(std::istream& doc,int &length, int &lines, std::string& set){
	std::string str1, str2;
	int count = 0;
	doc >> str1;
	length = str1.length();
	set = str1;

	doc.seekg(0, std::ios_base::beg);
	doc.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (!(doc.eof())){
		getline(doc, str2);
		if (!(str2 == ""))
			count++;
	}
	lines = count;
}

void getData(test list[], std::istream& doc, int lines){
	doc.clear();
	doc.seekg(0, std::ios_base::beg);
	doc.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string ID, ans;
	
	for (int i = 0; i < lines; i++){
		doc >> ID;
		if (!(ID == "")){
			doc.get();
			getline(doc, ans);
			list[i].setID(ID);
			list[i].setAnswers(ans);
		}
		else
			i--;
	}
}

void checkAnswers(char answers[],test list[], int length, int lines){
	double sum, total, score;
	std::string temp;
	total = length * 2.0;

	for (int i = 0; i < lines; i++){
		sum = 0;
		temp = list[i].getAnswers();
		for (int j = 0; j < length; j++){
			if (answers[j] == temp[j])
				sum += 2;
			else if (temp[j] == ' ')
				sum += 0;
			else
				sum += 1;
		}
		score = sum / total;
		list[i].setScore((score * 100.0));
	}
}

void grade(test list[], int lines){
	double score;
	
	for (int i = 0; i < lines; i++){
		score = list[i].getScore();

		if ((score >= 90) && (score <= 100))
			list[i].setGrade('A');
		else if ((score >= 80) && (score <= 89.99))
			list[i].setGrade('B');
		else if ((score >= 70) && (score <= 79.99))
			list[i].setGrade('C');
		else if ((score >= 60) && (score <= 69.99))
			list[i].setGrade('D');
		else if ((score >= 50) && (score <= 59.99))
			list[i].setGrade('F');
	}
}

void output(test list[],int lines){
	for (int i = 0; i < lines; i++){
		std::cout << list[i].getID() << " " << list[i].getScore() << "% " << list[i].getGrade() << std::endl;
	}
}