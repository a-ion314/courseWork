#include<iostream>

struct node{
	int value;
	node * link;
};

void main(){

	node *list, *last;
	node node1, node2, node3;

	list = &node1;
	list->value = 1;
	list->link = &node1;
	list->link->value = 2;
	list->link->link = &node3;
	list->link->link->value = 3;
	list->link->link->link = nullptr;

	last = &node3;

	*list = *last;

	std::cout << list << std::endl;
	std::cout << list->value << std::endl;
	std::cout << last << std::endl;
}