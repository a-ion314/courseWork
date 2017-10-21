//Programmed by: Adrian Ionascu
//CSC 1501 Lab 12 Program 2

#include<iostream>
#include<iomanip>

void ins_con(int map[][8], char L[8]);
void show_num_edges(int map[][8]);
void del_con(int map[][8], char L[8]);
void show_map(int map[][8], char L[8]);

void main(){
	int a = 0, b = 1, c = 2, d = 3, l = 4, m = 5, n = 6, s = 7;

	char location[8] = { 'A', 'B', 'C', 'D', 'L', 'M', 'N', 'S' };
	int map[8][8];

	for (int i = 0; i < 8; i++){
		for (int k = 0; k < 8; k++){
			map[k][i] = 0;
		}
	}
	
	map[m][a] = 595; map[m][n] = 1090;
	map[n][b] = 191; map[n][s] = 2534;
	map[n][c] = 722; map[n][l] = 2451;
	map[b][c] = 860; map[s][c] = 1855;
	map[s][d] = 957; map[d][c] = 908;
	map[l][d] = 834; map[a][c] = 606;
	map[s][l] = 349; map[l][s] = 349;
	map[n][a] = 760;

	while (true){
		std::cout << std::endl;
		int choice;
		std::cout << "1. Insert connection." << std::endl;
		std::cout << "2. Delete connection." << std::endl;
		std::cout << "3. Show num of edges" << std::endl;
		std::cout << "4. Show map" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "Choose a choice: " << std::endl;
		std::cin >> choice;

		switch (choice){
		case 1: ins_con(map, location);
			break;
		case 2: del_con(map, location);
			break;
		case 3: show_num_edges(map);
			break;
		case 4: show_map(map, location);
			break;
		case 0:
			exit(NULL);
			break;
		}
	}
}

void ins_con(int map[][8], char L[8]){
	char location1, location2;
	bool check1 = false, check2 = false;
	int loc1_ind, loc2_ind, weight;
	std::cout << "Enter first location(must be first letter of location and capitalized): ";
	std::cin >> location1;
	std::cout << "Enter first location(must be first letter of location and capitalized): ";
	std::cin >> location2;

	for (int i = 0; i < 8; i++){
		if (location1 == L[i]){
			check1 = true;
			loc1_ind = i;
		}
		if (location2 == L[i]){
			check2 = true;
			loc2_ind = i;
		}
	}

	if (check1 == true && check2 == true){
		if (map[loc1_ind][loc2_ind] == 0){
			std::cout << "Enter weight." << std::endl;
			std::cin >> weight;
			map[loc1_ind][loc2_ind] = weight;
			std::cout << "Edge had been made between vertex " << location1 << " and " << location2 << " with a weight of " << weight << std::endl;
		}
		else
		{
			std::cout << "Edge already exists." << std::endl;
		}
	}
	else
		std::cout << "Could not find inputted vertexes." << std::endl;
}

void show_num_edges(int map[][8]){
	int count = 0;

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (map[i][j] > 0)
				count++;
		}
	}

	std::cout << "The number of edges is " << count << std::endl;
}

void del_con(int map[][8], char L[8]){
	char location1, location2;
	bool check1 = false, check2 = false;
	int loc1_ind, loc2_ind;
	std::cout << "Enter first vertex(must be first letter of vertex and capitalized): ";
	std::cin >> location1;
	std::cout << "Enter first vertex(must be first letter of vertex and capitalized): ";
	std::cin >> location2;

	for (int i = 0; i < 8; i++){
		if (location1 == L[i]){
			check1 = true;
			loc1_ind = i;
		}
		if (location2 == L[i]){
			check2 = true;
			loc2_ind = i;
		}
	}

	if (check1 == true && check2 == true){
		if (map[loc1_ind][loc2_ind] > 0){
			map[loc1_ind][loc2_ind] = 0;
			std::cout << "Connection deleted between " << location1 << " and " << location2 << std::endl;
		}
		else
		{
			std::cout << "Connection does not exist." << std::endl;
		}
	}
	else
		std::cout << "Could not find inputted locations." << std::endl;
}

void show_map(int map[][8], char L[8]){
	std::cout << "  ";
	for (int i = 0; i < 8; i++){
		std::cout << std::setw(4) << std::left << L[i];
		std::cout << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < 8; i++){
		std::cout << L[i] << " ";
		for (int k = 0; k < 8; k++){
			std::cout << std::setw(4)<< std::left << map[i][k] << " ";
		}
		std::cout << std::endl;
	}

}