#include<iostream>
#include<fstream>
#include<string>

void and();
void or();
void xor();
void imply();
void bicondition();

int main(){
	
	int choice;
	std::cout << "Please type 1-5 for the following truth tables.";
	std::cout << std::endl; std::cout << "1. Conjunction" << std::endl; std::cout << "2. Disjunction" << std::endl; std::cout << "3. Exclusive or" << std::endl; std::cout << "4. Implication" << std::endl; std::cout << "5. Biconditional" << std::endl;
	std::cout << "Table: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1: and();
		break;
	case 2: or();
		break;
	case 3: xor();
		break;
	case 4: imply();
		break;
	case 5: bicondition();
		break;
	default:
		std::cout << "That is not a valid choice!" << std::endl;
		main();
	}
}

void and(){
	std::ofstream table;
	table.open("prog1_output.txt");
	table << "CONJUNCTION TRUTH TABLE" << std::endl;
	table << "   p   " << "|" << "   q   " << "|" << "p AND q" << std::endl;
	table << "-------------------------" << std::endl;
	table << "   T   " << "|" << "   T   " << "|" << "   T   " << std::endl;
	table << "   T   " << "|" << "   F   " << "|" << "   F   " << std::endl;	
	table << "   F   " << "|" << "   T   " << "|" << "   F   " << std::endl;
	table << "   F   " << "|" << "   F   " << "|" << "   F   " << std::endl;
	table.close();
}

void or(){
	std::ofstream table;
	table.open("prog1_output.txt");
	table << "DISJUNCTION TRUTH TABLE" << std::endl;
	table << "   p   " << "|" << "   q   " << "|" << "p OR q" << std::endl;
	table << "-------------------------" << std::endl;
	table << "   T   " << "|" << "   T   " << "|" << "   T   " << std::endl;
	table << "   T   " << "|" << "   F   " << "|" << "   T   " << std::endl;
	table << "   F   " << "|" << "   T   " << "|" << "   T   " << std::endl;
	table << "   F   " << "|" << "   F   " << "|" << "   F   " << std::endl;
	table.close();
}

void xor(){
	std::ofstream table;
	table.open("prog1_output.txt");
	table << "EXLCLUSIVE OR TRUTH TABLE" << std::endl;
	table << "   p   " << "|" << "   q   " << "|" << "p XOR q" << std::endl;
	table << "-------------------------" << std::endl;
	table << "   T   " << "|" << "   T   " << "|" << "   F   " << std::endl;
	table << "   T   " << "|" << "   F   " << "|" << "   T   " << std::endl;
	table << "   F   " << "|" << "   T   " << "|" << "   T   " << std::endl;
	table << "   F   " << "|" << "   F   " << "|" << "   F   " << std::endl;
	table.close();
}

void imply(){
	std::ofstream table;
	table.open("prog1_output.txt");
	table << "IMPLICATION TRUTH TABLE" << std::endl;
	table << "   p   " << "|" << "   q   " << "|" << "IF p THEN q" << std::endl;
	table << "-------------------------" << std::endl;
	table << "   T   " << "|" << "   T   " << "|" << "   T   " << std::endl;
	table << "   T   " << "|" << "   F   " << "|" << "   F   " << std::endl;
	table << "   F   " << "|" << "   T   " << "|" << "   T   " << std::endl;
	table << "   F   " << "|" << "   F   " << "|" << "   T   " << std::endl;
	table.close();
}

void bicondition(){
	std::ofstream table;
	table.open("prog1_output.txt");
	table << "BICONDITIONAL TRUTH TABLE" << std::endl;
	table << "   p   " << "|" << "   q   " << "|" << "p ONLY IF q" << std::endl;
	table << "-------------------------" << std::endl;
	table << "   T   " << "|" << "   T   " << "|" << "   T   " << std::endl;
	table << "   T   " << "|" << "   F   " << "|" << "   F   " << std::endl;
	table << "   F   " << "|" << "   T   " << "|" << "   F   " << std::endl;
	table << "   F   " << "|" << "   F   " << "|" << "   T   " << std::endl;
	table.close();
}