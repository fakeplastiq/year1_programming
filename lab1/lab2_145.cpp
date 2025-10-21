#define _USE_MATH_DEFINES 

#include <iostream>
#include <cmath>
#include <format>

using namespace std;

double f(double x) {
/*
* Calculates the given in 145th variant expression
* 
* Args:
*	x - double
* 
*Obligatory to use check_if_in_domain function before calling f(x)
*/
	return cos(3.0 / 56.0) - (25.0 * 11.0 * M_PI)/(54.0 * M_E * (x - 14.0) * (x + 12.0)) - 10 * atan(1.0/(x + 4.0)) + (13 - sqrt(x - 8.0))/(x + 15.0);
}
 
void welcoming() {
	cout << "The author of this program is Kotun Oleg.\n";
	cout << "This program calculates the expression from variant by given x. Variant 145.\n";
}

double input() {
/*
*Throws 4 if delta is not double
*/
	double delta;
	cout << "Please, enter x from domain (x >= 8 and x !=14): ";
	cin >> delta;
	if (cin.fail()) {
		throw 4;
	}
	return delta;
}


bool check_if_in_domain(double x){
	return x >= 8 and x != 14;
}


int main() {
	try
	{
		welcoming();

		double x = input();
		cout << endl;

		cout << "***** do calculations ... ";
		double counted;
		if (check_if_in_domain(x)) {
			counted = f(x);
		}
		else {
			counted = NAN;
		}
		cout << "done";


		cout << format("\nfor x = {:.5f}", x);

		if (isnan(counted)) {
			cout << "\nresult = undefined";
		}
		else
		{
			cout << format("\nresult = {:.9f}", counted);
		}

		return 0;
	}
	catch (int e)
	{
		if (e == 4) {
			cout << "wrong input";
		}
	}
	}
	