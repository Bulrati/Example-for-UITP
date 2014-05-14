// TPR_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
// 256*x^2 + 240,9*x + 64

double function (double);
int counter;
int main()
{
	counter = 0;
	double Xc = 0, X1 = 0, X2 = 0, funcXc = 0, funcX1 = 0,
		funcX2 = 0, a = -16, b = 16, L = 0, E = 0.001;
	int numOfIter = 0;

	std::cout << "a = " << a << ", b = " << b;
	Xc = (a + b) / 2;
	std::cout << "Xc = " << Xc << std::endl;
	L = b - a;
		std::cout << "L = " << L << std::endl;
	funcXc = function(Xc);

	while (1) {

	++numOfIter;
	std::cout << "Iterations = " << numOfIter << std::endl;
	X1 = a + L / 4;
	X2 = b - L / 4;
	std::cout << "X1 = " << X1 << ", X2 = " << X2 << std::endl;
	funcX1 = function(X1);
	funcX2 = function(X2);
	funcXc = function(Xc);
	std::cout << "funcX1 = " << funcX1 << " funcX2 = " << funcX2 << " funcXc = " << funcXc << std::endl;
	if(funcX1 < funcXc) {
		b = Xc;
		Xc = X1;
		std::cout << "funcX1 < funcXc" << std::endl;
	} else if (funcX2 < funcXc) {
		a = Xc;
		Xc = X2;
		std::cout << "funcX2 < funcXc" << std::endl;
	} else if (funcX2 >= funcXc) {
		a = X1;
		b = X2;
		std::cout << "funcX2 >= funcXc" << std::endl;
	} // end of if
	
	L = b - a;
	std::cout << "L = " << L << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	if ( L < E ) {
		std::cout << "Result : a = " << a << ", b = " << b << std::endl;
		std::cout << " Extr = " << Xc << " Func Extr = " << function(Xc) << " WIN! " << std::endl;
		std::cout << " Function calls = " << counter << std::endl;
		break;
	} // end of if

	}//end of while

	
	system("pause");
	return 0;
}


double function (double x)
{
	++counter;
	double rez = 0;
	rez = 256 * pow(x,2) + 240.9*x + 64; 
	return rez;
}