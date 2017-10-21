//Programmed by: Adrian Ionascu
//CSC 1501 Lab 07 Program 4
#include<iostream>
#include<fstream>

void sort(int list[], int temp[], int start, int end);
void merge(int list[],int temp[], int start, int middle, int end);

void main(){
	int list[15], temp[15];

	std::ifstream doc; std::ofstream output;
	doc.open("A4.txt"); output.open("B4.txt");

	for (int i = 0; i < 15; i++){
		for (int i = 0; i < 15; i++){
			doc >> list[i];
		}

		sort(list, temp, 0, 14);

		for (int i = 0; i < 15; i++){
			output << temp[i] << " ";
		}
		output << std::endl;
	}

	doc.close();
	output.close();

}

void sort(int list[],int temp[],int start,int end){
	if (start < end)
	{
		int middle = (start + end) / 2;
		sort(list,temp, start, middle);
		sort(list,temp, middle + 1, end);
		merge(list,temp, start, middle+1, end);
	}
}



void merge(int numbers[], int temp[], int p, int mid, int r)
{
	int left, index, tempIndex;
	left = (mid - 1);
	tempIndex = p;
	index = (r - p + 1);
	while ((p <= left) && (mid <= r))
	{
		if (numbers[p] <= numbers[mid])
			{	
				temp[tempIndex] = numbers[p];
				tempIndex++;
					p++;
			}
			else	
			{			
				temp[tempIndex] = numbers[mid];
				tempIndex++;
					mid++;
			}
	}
	while (p <= left)
	{
		temp[tempIndex] = numbers[p];
		p++;
		tempIndex++;
	}
	while (mid <= r)
	{
		temp[tempIndex] = numbers[mid];
			mid++;
			tempIndex++;
	}
	for (int i = 0; i <= index; i++)
	{
		numbers[r] = temp[r];
			r--;
	}
}


