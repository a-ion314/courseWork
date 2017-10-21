#include<iostream>
#include<cmath>

double mean(double x1, double x2, double x3, double x4, double x5)
{
	double mean;
	mean = (x1 + x2 + x3 + x4 + x5) / 5;

	return mean;
}
double deviation(double x1,double x2,double x3,double x4,double x5,double m)
{
	double dev;
	double num;
	num = pow(x1 - m, 2) + pow(x2 - m, 2) + pow(x3 - m, 2) + pow(x4 - m, 2) + pow(x5 - m, 2);
	dev = sqrt(num / 5.0);
	return dev;
}
int main()
{
	double x1, x2, x3, x4, x5;
	std::cout << "Enter 5 numbers: ";
	std::cin >> x1 >> x2 >> x3 >> x4 >> x5;
	double m = mean(x1, x2, x3, x4, x5);
	std::cout << "The mean of those 5 numbers is: " << m << std::endl;
	std::cout << "The standard deviation of those 5 numbers is: " << deviation(x1, x2, x3, x4, x5, m) << std::endl;


	return 0;
}