#include <iostream>

#include "HashTable.h"

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
	
{
	tableSize = initTableSize;
	dataTable = new BSTree<DataType, KeyType>[tableSize];
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& source) {
	if (this != source){
		*this = source;
	}
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>&
HashTable<DataType, KeyType>::operator=(const HashTable& source) {
	copyTable(source);
	return *this;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source) {
	tableSize = source.tableSize;

	for (int i = 0; i < tableSize;i++){
		dataTable[i] = source.dataTable[i];
	}
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable() {
	for (int i = 0; i < tableSize; i++){
		dataTable[i].clear();
	}
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem) {
	int hash = newDataItem.hash(newDataItem.getKey()) % tableSize;
	return dataTable[hash].insert(newDataItem);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey) {
	
	DataType temporary;
	int index = temporary.hash(deleteKey) % tableSize;

	return dataTable[index].remove(deleteKey);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey,
	DataType& returnItem) const
{
	int index = returnItem.hash(searchKey) % tableSize;

	return dataTable[index].retrieve(searchKey, returnItem);
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear() {
	for (int i = 0; i < tableSize; i++){
		dataTable[i].clear();
	}
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const {
	for (int i = 0; i < tableSize; i++){
		if (!(dataTable[i].isEmpty()))
			return false;
	}
	return true;
}

#include <cmath>

template <typename DataType, typename KeyType>
double HashTable<DataType, KeyType>::standardDeviation() const {
	int total = 0;

	for (int i = 0; i < tableSize; ++i) {
		total += dataTable[i].getCount();
	}

	double average = total / tableSize;
	double sum = 0.0;

	for (int i = 0; i < tableSize; ++i) {
		int size = dataTable[i].getCount();
		sum += (size - average) * (size - average);
	}

	return sqrt(sum / (tableSize - 1));
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const {
	for (int i = 0; i < tableSize; ++i) {
		cout << i << ": ";
		dataTable[i].writeKeys();
	}
}
