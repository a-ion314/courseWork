//Programmed by Adrian Ionascu CSC 1501 Lab 05 Bonus Problem
#include<iostream>

void intersect(int A[], int B[], int Result[]);
void Union(int A[], int B[], int Result[], int SizeA, int SizeB);

void main(){		//couldnt get program to work
	int A[4] = { 1, 2, 3, 4 };
	int B[5] = { 0, 2, 4, 6, 8 };
	int C[5] = { 3, 5, 7, 9, 11 };
	int U[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };

	int Result1[6];
	int Result2[7];
	int Result3[5];
	int Output[7];

	intersect(A, B, Result1);

	for (int i = 0; i < 7; i++){
		if (Output[i] != NULL){
			std::cout << Output[i] << " ";
		}
	}

}

void intersect(int A[], int B[], int Result[]){
	int count = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j++){
			if (A[i] == B[j]){
				Result[count] = A[i];
				count++;
			}
		}
	}

	for (int i = 0; i < 6; i++){
		for (int i = 0; i < 6; i++){
			if (Result[i] == NULL){
				for (int j = (i); j < 5; j++){
					Result[j] = Result[j + 1];
					Result[j + 1] = NULL;
				}
				break;
			}
		}
	}
}

void Union(int A[], int B[], int Result[], int SizeA, int SizeB){
	for (int i = 0; i < SizeA; i++){
		for (int j = 0; j < SizeB; j++){
			if (A[i] == B[j]){
				B[j] = NULL;
			}
		}
	}
}