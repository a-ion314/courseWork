#include<iostream>
#include<string>

void main(){
	int whole, sum = 0;
	double fraction, sumFrac = 0, output;
	std::string wholeString, fractionString;
	char *wholePoint, mult;
	char *fractionPoint;
	
	std::cout << "Please input a fraction in octal: ";
	std::cin >> fraction;

	whole = fraction;
	fraction = fraction - whole;
	
	wholeString = std::to_string(whole);
	fractionString = std::to_string(fraction);

	wholePoint = new char[wholeString.length()];
	fractionPoint = new char[fractionString.length()];

	for (int i = 0; i < wholeString.length(); i++){
		wholePoint[i] = wholeString[i];
	}

	for (int i = 0; i < fractionString.length(); i++){
		fractionPoint[i] = fractionString[i];
	}

	for (int i = 0; i < wholeString.length(); i++){
		mult = wholePoint[i];
		sum += (mult - 48) * pow(8, wholeString.length() - 1 - i);
	}

	for (int i = 2; i < fractionString.length(); i++){
		mult = fractionPoint[i];
		sumFrac += static_cast<double>((mult - 48) * (1.0 / pow(8, i-1)));
	}

	output = sumFrac + static_cast<double>(sum);

	std::cout << "Output in base 10 is: "<<output << std::endl;
}