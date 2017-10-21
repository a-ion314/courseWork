#include<iostream>
#include<string>

int main()
{
	int age;
	char delim;
	std::string name;
	std::cin >> age;
	std::cin.get(delim);
	std::getline(std::cin,name);
	
	std::cout << "name = "<< name << std::endl;
	std::cout << "character = " << delim << std::endl;
	std::cout << "age = "<< age << std::endl;

	return 0;
} 