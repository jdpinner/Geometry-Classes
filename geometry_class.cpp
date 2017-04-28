// geometry_class.cpp : Defines the entry point for the console application.
// By: James Pinner
// This program takes three points which describe a triange and calculates the 
// side measures.

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class point {
public:
	double x;
	double y;
	point();
	point(double _x, double _y);
	string toString();
	};

class line {
	point begin;
	point end;

public:
	line();
	line(point _begin, point _end);
	double calcLength();
	string toString();

};


int main()
{
	point alpha(0, 0);
	point beta(30, 0);
	point gamma(0, 40);

	line c(alpha, beta);
	line a(beta, gamma);
	line b(gamma, alpha);

	cout << setw(20) << left << "alpha " << alpha.toString() << endl
		<< setw(20) << left << "beta " << beta.toString() << endl
		<< setw(20) << left << "gamma " << gamma.toString() << endl;

	cout << setw(20) << left << "Line a length = " << setw(20) << a.toString() << setw(10) << "Point beta to Point gamma" << endl
		<< setw(20) << left << "Line b length = " << setw(20) << b.toString() << setw(10) << "Point gamma to Point alpha" << endl
		<< setw(20) << left << "Line c length = " << setw(20) << c.toString() << setw(10) << "Point alpha to Point beta" << endl;

	cout << endl << "Press enter to exit program.";
	cin.ignore(100, '\n');


    return 0;
}
//************************************************Point Class Functions**********************************************

string point::toString() {	
	return "(" + to_string(x) + "," + to_string(y) + ")"; 
}
//************************************************Point Class Constructors*******************************************
point::point() {
	x = 0;
	y = 0;
}

point::point(double _x, double _y) {
	x = _x;
	y = _y;
}
//************************************************Line Class Functions***********************************************
string line::toString() {	
	return to_string(calcLength());
}

double line::calcLength() {	
	return sqrt(pow(begin.x - end.x, 2) + (pow(begin.y - end.y, 2)));
}
//************************************************Line Class Constructors******************************************
line::line() {
	begin = point(0, 0);
	end = point(0, 0);
}

line::line(point _begin, point _end) {
	begin = _begin;
	end = _end;
}
//***********************************************console output******************************************************
//alpha			  (0.000000, 0.000000)
//beta			  (30.000000, 0.000000)
//gamma			  (0.000000, 40.000000)
//Line a length = 50.000000           Point beta to Point gamma
//Line b length = 40.000000           Point gamma to Point alpha
//Line c length = 30.000000           Point alpha to Point beta
//
//Press enter to exit program.