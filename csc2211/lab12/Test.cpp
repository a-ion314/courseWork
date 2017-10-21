#include<iostream>
#include"Header.h"
using namespace std;

int	main()
{
	Triangle tri;
	tri.draw();
	cout << "In main,Derived class Triangle object calling"
		<< " center().\n";
	tri.center();
	Rectangle rect;
	rect.draw();
	cout << "In main, Derived class Rectangle object calling"
		<< " center().\n";
	rect.center();
	return	0;
}

//The difference between a base class with and without virtual functions is that
// when the base class figure doesnt have virtual functions, center is called then
// it will also call draw and erase in relation to that base class.
// When a derived class calls figure with virtual function center, center will call
// erase and draw in relation to the class it was called from.