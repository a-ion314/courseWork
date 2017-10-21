//Programmed by: Adrian Ionascy
//CSC 1501 Lab 12 Program 3

#include<iostream>
#include<iomanip>
#include<vector>

void dij_alg(int graph[10][10], int source);
int check_minimal(int L[], bool S[]);
void output(int L[], int source, int path[]);

void main(){
	int a =0, b=1, c=2, d=3, e=4, f=5, g=6, h=7, i=8, j=9;

	int graph[10][10];

	for (int n = 0; n < 10; n++){
		for (int j = 0; j < 10; j++){
				graph[n][j] = 0;
		}
	}

	graph[a][e] = 1; graph[d][a] = 4;
	graph[d][h] = 1; graph[a][h] = 10;
	graph[h][e] = 5; graph[e][f] = 3;
	graph[h][i] = 9; graph[f][i] = 1;
	graph[i][j] = 2; graph[j][g] = 1;
	graph[f][g] = 7; graph[f][b] = 1;
	graph[f][c] = 3; graph[b][c] = 2;



	dij_alg(graph, 3);
}

void dij_alg(int graph[10][10], int source){
	int path[6];

	for (int i = 0; i < 6; i++){
		path[i] = 0;
	}

	int counter = 0;

	int a = source;
	int L[10];	//distance between source and vertex
	bool S[10];	//list of all verticies checked

	for (int i = 0; i < 10; i++){
		S[i] = false;
		L[i] = INT_MAX;
	}

	L[a] = 0;

	for (int k = 0; k < 9; k++){
		int u = check_minimal(L, S);
		S[u] = true;

		if (S[6] == false && counter != 6){
			path[k] = u;
			counter++;
		}

		for (int i = 0; i < 10; i++){
			if (!(S[i]) && (graph[u][i]) && (L[u] != INT_MAX) && (L[u] + graph[u][i] < L[i])){
				L[i] = L[u] + graph[u][i];
			}
		}
	}

	output(L, source, path);
}

int check_minimal(int L[], bool S[]){
	int index, small = INT_MAX;

	for (int i = 0; i < 10; i++){
		if ((S[i] == false) && (L[i] <= small)){
			small = L[i];
			index = i;
		}
	}

	return index;
}

void output(int L[], int source, int path[]){
	std::cout << "Source is on the left, Destination is on the top." << std::endl;
	std::cout << std::endl;
	std::cout << "  ";
	for (int i = 0; i < 10; i++){
		std::cout << std::setw(2) << static_cast<char>(i + 65) << " ";
	}
	std::cout << std::endl;
	std::cout << static_cast<char>(source + 65) << " ";
	for (int i = 0; i < 10; i++){
		if (L[i] == INT_MAX){
			std::cout << "n/a";
		}
		else
			std::cout << std::setw(2) << L[i] << " ";
	}
	std::cout << std::endl;

	char Loc_array[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	std::cout << "D -> ";

	for (int i = 0; i < sizeof(path); i++){
		int temp = path[i];
		switch (temp)
		{
		case 3: std::cout << Loc_array[0] << " -> ";
			break;			 
		case 7: std::cout << Loc_array[4] << " -> ";
			break;			 
		case 0: std::cout << Loc_array[5] << " -> ";
			break;			 
		case 4: std::cout << Loc_array[6] << " -> ";
			break;			
		case 5: std::cout << Loc_array[9] << " -> ";
			break;			 
		case 8: std::cout << Loc_array[6] << std::endl;
			bool exit = true;
			break;
		}
	}
	std::cout << std::endl;
}