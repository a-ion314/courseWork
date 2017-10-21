#include<iostream>
#include"Header.h"

void figure::erase(){
	std::cout << "this is the function figure::erase()" << std::endl;
}

void figure::draw(){
	std::cout << "this is the function figure::draw()" << std::endl;
}

void figure::center(){
	std::cout << "the member function center is called to erase and draw" << std::endl;
	erase();
	draw();
}

void Rectangle::erase(){
	std::cout << "this is the function rectangle::erase()" << std::endl;
}

void Rectangle::draw(){
	std::cout << "this is the function rectangle::draw()" << std::endl;
}

void Triangle::erase(){
	std::cout << "this is the function triangle::erase()" << std::endl;
}

void Triangle::draw(){
	std::cout << "this is the function triangle::draw()" << std::endl;
}