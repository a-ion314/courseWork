#include<iostream>
#include<string>

int Vowels(std::string str)
{
	int length = str.length();
	int place = length - 1;
	int vowel = 0;
	for (int i = 0; i <= (place); i++)
	{
		char pl = str.at(i);
		if (pl == 'a' || pl == 'e' || pl == 'i' || pl == 'o' || pl == 'u')
			vowel++;
	}



	return vowel;
}
int main()
{
	std::string str;
	int vowel;
	std::cout << "Input a string in all lowercase: ";
	std::cin >> str;
	vowel = Vowels(str);
	std::cout << "The amount of vowels in the given string is: " << vowel << std::endl;
	return 0;
}