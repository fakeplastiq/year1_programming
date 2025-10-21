#include <iostream>
#include <format>

using namespace std;

const double A = 0, B = 1;

void welcoming() {
	/*
	introduce the author, number of variant
	*/
	cout << "The author of this program is Kotun Oleg\n";
	cout << "This program calculates the value of series given in variant 145\n";
}

double inputX() {
	/*
	inputX() is used to get x, that is double, from user`s keyboard.

	Can throw diagnosis if user entered not number
	*/
	double delta;
	cin >> delta;
	if (cin.fail()) throw runtime_error("\nResult cannot be calculated because you entered X that is not a real number.");
	return delta;
}

double inputEps() {
	/*
	inputEps() is used to get eps, that is double, from user`s keyboard.

	Can throw diagnosis if user entered not number
	*/
	double delta;
	cin >> delta;
	if (cin.fail()) throw runtime_error("\nResult cannot be calculated because you entered epsilone that is not a real number.");
	return delta;
}

void epsIsPositive(double eps) {
	/*
	Checks if entered eps is positive
	
	Can throw diagnosis if epsilone is not positive 
	*/
	bool checkedEps = eps > 0;
	if (!checkedEps) throw domain_error("\nYou entered epsilone that is not positive.");
	
}

void x_check(double x) {
	/*
	Checks if entered x is in it`s domain [0;1]

	Can throw diagnosis if x is not in it`s domain
	*/
	bool checkedX = x >= A and x <= B;
	if (!checkedX) throw domain_error("\nYou entered x that is not in domain.");
}

double s(double x, double eps) {
	/*
	Calculates the value of series given in 145th variant using entered x and epsilone (mark of precision)

	Args:
		x - double from [0;1]
		eps - double, positive 
	*/
	double An = x; 
	double Sn = An;
	double x2 = x * x;
	int n_2 = 0;
		while (An > eps) {
			An *= x2 / (n_2 + 2.0) / (n_2 + 2.0) / (n_2 + 3.0) / (n_2 + 3.0);
			Sn += An;
			n_2+= 2;
		}
		
		return Sn;
}


int main() {
	/*
	Asking for enetering x, eps (precision)

	Printing result if it can be calculated. Othercase - giving issue diagnostics details
	*/
	try {
		double x, eps, result;

		welcoming();

		cout << "Enter a real from [0;1]: ";
		x = inputX();
		x_check(x);

		cout << "Enter positive epsilone: ";
		eps = inputEps();
		epsIsPositive(eps);

		cout << "***** do calculations ... ";
		result = s(x, eps);
		cout << "done";
		
		cout << format("\nfor x: {:.7E}", x);
		cout << format("\nfor eps: {:.5E}", eps);
		cout << format("\nresult = {:.10f}", result); 
		
		
		
	}
	catch (exception e) {
			cout << "\n***** error";
			cout << e.what();
	}
	return 0;
}