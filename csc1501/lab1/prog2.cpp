#include<iostream>
#include<fstream>
#include<iomanip>

void and_and();
void xor_xor();
void and_or();
void bi_bi();
void if_if();

void main(){
	int choice;
	std::cout << "1. (A AND B) AND C" << std::endl
		<< "2. (A XOR B) XOR C" << std::endl
		<< "3. (A AND B) OR C" << std::endl
		<< "4. (A <-> B) <-> C" << std::endl
		<< "5. ((A -> B) -> C) -> D" << std::endl; std::cout << std::endl;
		
	while (((std::cout << "Enter choice: ") && !(std::cin >> choice)) || (choice < 1) || (choice > 5)){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Bad Entry. \n";
	}

	switch (choice){
	case 1: and_and();
		break;
	case 2: xor_xor();
		break;
	case 3: and_or();
		break;
	case 4: bi_bi();
		break;
	case 5: if_if();
		break;
	}

	std::cout << "Truth table has been printed to prog2_output.txt" << std::endl;
}

void and_and(){
	std::ofstream file;
	file.open("prog2_output.txt");
	char value[2] = { 'F', 'T' };

	file << "(A AND B) AND C Truth Table" << std::endl; file << std::endl;
	file << "  A  " << "  B  " << "  C  " << "  (A AND B) AND C" << std::endl;
	file << "================================" << std::endl;

	for (int A = 0; A <= 1; A++){
		for (int B = 0; B <= 1; B++){
			for (int C = 0; C <= 1; C++){
				file << std::setw(3) << value[A];
				file << std::setw(5) << value[B];
				file << std::setw(5) << value[C];
				file << std::setw(15) << value[((A && B) && C)] << std::endl;
			}
		}
	}
}

void xor_xor(){
	std::ofstream file;
	file.open("prog2_output.txt");
	char value[2] = { 'F', 'T' };

	file << "(A AND B) AND C Truth Table" << std::endl; file << std::endl;
	file << "  A  " << "  B  " << "  C  " << "  (A XOR B) XOR C" << std::endl;
	file << "================================" << std::endl;

	for (int A = 0; A <= 1; A++){
		for (int B = 0; B <= 1; B++){
			for (int C = 0; C <= 1; C++){
				file << std::setw(3) << value[A];
				file << std::setw(5) << value[B];
				file << std::setw(5) << value[C];
				file << std::setw(15) << value[((A ^ B) ^ C)] << std::endl;
			}
		}
	}
}

void and_or(){
	std::ofstream file;
	file.open("prog2_output.txt");
	char value[2] = { 'F', 'T' };

	file << "(A AND B) AND C Truth Table" << std::endl; file << std::endl;
	file << "  A  " << "  B  " << "  C  " << "  (A AND B) OR C" << std::endl;
	file << "================================" << std::endl;

	for (int A = 0; A <= 1; A++){
		for (int B = 0; B <= 1; B++){
			for (int C = 0; C <= 1; C++){
				file << std::setw(3) << value[A];
				file << std::setw(5) << value[B];
				file << std::setw(5) << value[C];
				file << std::setw(15) << value[((A && B) || C)] << std::endl;
			}
		}
	}
}

void bi_bi(){
	std::ofstream file;
	file.open("prog2_output.txt");
	char value[2] = { 'F', 'T' };

	file << "(A AND B) AND C Truth Table" << std::endl; file << std::endl;
	file << "  A  " << "  B  " << "  C  " << "  (A <-> B) <-> C" << std::endl;
	file << "================================" << std::endl;

	for (int A = 0; A <= 1; A++){
		for (int B = 0; B <= 1; B++){
			for (int C = 0; C <= 1; C++){
				file << std::setw(3) << value[A];
				file << std::setw(5) << value[B];
				file << std::setw(5) << value[C];
				file << std::setw(15) << value[((A == B) == C)] << std::endl;
			}
		}
	}
}

void if_if(){
	std::ofstream file;
	file.open("prog2_output.txt");
	char value[2] = { 'F', 'T' };
	int out1, out2, out3;

	file << "((A AND B) AND C) AND D) Truth Table" << std::endl; file << std::endl;
	file << "  A  " << "  B  " << "  C  " << "  D  "<< "  ((A -> B) -> C) -> D" << std::endl;
	file << "==========================================" << std::endl;
	
	for (int A = 0; A <= 1; A++){
		for (int B = 0; B <= 1; B++){
			for (int C = 0; C <= 1; C++){
				for (int D = 0; D <= 1; D++){
					file << std::setw(3) << value[A];
					file << std::setw(5) << value[B];
					file << std::setw(5) << value[C];
					file << std::setw(5) << value[D];
					out1 = (((B == 1) || (A == B)) ? (1) : (0));
					out2 = (((C == 1) || (out1 == C)) ? (1) : (0));
					out3 = (((D == 1) || (out2 == D)) ? (1) : (0));
					file << std::setw(15) << value[out3] << std::endl;
				}
			}
		}
	}
}