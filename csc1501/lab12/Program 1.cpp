//Programmed by: Adrian Ionascu
//CSC 1501 Lab 12 Program 1

#include<iostream>

void ins_con(bool map[][7], char L[7]);
void del_con(bool map[][7], char L[7]);
void show_map(bool map[][7], char L[7]);
void show_num_edges(bool map[][7]);

void main(){
	int b = 0, c = 1, d = 2, l = 3, n = 4, s = 5, w = 6;

	char location[7] = {'B','C','D','L','N','S','W'};
	bool map[7][7];

	for (int i = 0; i < 7; i++){
		for (int k = 0; k < 7; k++){
			map[k][i] = false;
		}
	}
	map[b][n] = true; map[n][b] = true;
	map[n][w] = true; map[w][n] = true;
	map[n][c] = true; map[c][n] = true;
	map[c][w] = true; map[w][c] = true;
	map[c][d] = true; map[d][c] = true;
	map[d][s] = true; map[s][d] = true;
	map[d][l] = true; map[l][d] = true;
	map[s][l] = true; map[l][s] = true;
	
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

void ins_con(bool map[][7], char L[7]){
	char location1, location2;
	bool check1 = false, check2 = false;
	int loc1_ind, loc2_ind;
	std::cout << "Enter first location(must be first letter of location and capitalized): ";
	std::cin >> location1;
	std::cout << "Enter first location(must be first letter of location and capitalized): ";
	std::cin >> location2;

	for (int i = 0; i < 7; i++){
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
		if (map[loc1_ind][loc2_ind] == true)
			std::cout << "Connection already exists." << std::endl;
		else
		{
			map[loc1_ind][loc2_ind] = true;
			map[loc2_ind][loc1_ind] = true;
			std::cout << "Connection made between " << location1 << " and " << location2 << std::endl;
		}
	}
	else
		std::cout << "Could not find inputted locations." << std::endl;
}

void show_num_edges(bool map[][7]){
	int count = 0;

	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 7; j++){
			if (map[i][j] == true)
				count++;
		}
	}

	std::cout << "The number of edges is " << (count / 2) << std::endl;
}

void del_con(bool map[][7], char L[7]){
	char location1, location2;
	bool check1 = false, check2 = false;
	int loc1_ind, loc2_ind;
	std::cout << "Enter first location(must be first letter of location and capitalized): ";
	std::cin >> location1;
	std::cout << "Enter first location(must be first letter of location and capitalized): ";
	std::cin >> location2;

	for (int i = 0; i < 7; i++){
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
		if (map[loc1_ind][loc2_ind] == true){
			map[loc1_ind][loc2_ind] = false;
			map[loc2_ind][loc1_ind] = false;
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

void show_map(bool map[][7], char L[7]){
	std::cout << "  ";

	for (int i = 0; i < 7;i++){
		std::cout << L[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < 7; i++){
		std::cout << L[i] << " ";
		for (int j = 0; j < 7; j++){
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}