#include <iostream>
#include <cmath>
#include <format>
using namespace std;

const double m = -0.4;
const double n = 0.4;

double s(double x, double eps) // This function calculates sum.
{
	int k = 1;
	double a = (x * x * x) / 3;
	double s = a;
	double x2 = x * x;
	

	while( abs(a) >= eps )
	{
		a *= ((2 * k + 3) * x2 * 2) / ((k + 2) * (2 * k + 5));
		s += a;
		k += 1;
	}

	return s;
}

bool domain_x(double x) // This function cheking if x in range.
{
	return(x >= m && x <= n);
}

bool domain_eps(double eps) // This function cheking if eps in range.
{
	return (eps > 0);
}




double input_x() // This function is responsible for input x value and control mistakes.
{
	double x;
	cout << "write in x in [ -0.4; 0.4 ]: ";
	cin >> x;									
	
	if (cin.fail())
	{
		throw runtime_error("wrong input! (at time of getting x)");
	}
	if (!domain_x(x))
	{
		throw domain_error("x out of range!");
	}

	return x;
}

	double input_eps() // This function is responsible for input epsilon value and control mistakes.
{
	double eps;
	cout << "enter a positive epsilon: ";
	cin >> eps;

	if (cin.fail())
	{
		throw runtime_error("wrong input! (at time of getting eps)");
	}
	if (!domain_eps(eps))
	{
		throw domain_error("epsilon must be positive!");
	}

	cout << endl;
	
	return eps;
}




void about() // Contains information about author, project.
{
	cout << "Студентка групи К-15 Тупчій Олександра" << endl;
	cout << "Програмний проєкт №2, варіант 163 " << endl;
	cout << "Наближене обчислення суми з заданою точністю " << endl;
}


int main()
{
	system("chcp 65001");
	about();
	try
	{

		double x, eps, result;
		x = input_x();
		eps = input_eps();
		cout << endl;

		cout << "***** do calculations ...";

		result = s(x, eps);

		cout << " done";
		cout << endl;

		cout << format("for x = {:.7e}", x) << endl;
		cout << format("for eps = {:.5e}", eps) << endl;
		cout << format("result = {:.10f}", result) << endl;
	}
	catch (const runtime_error& e)
	{
		cout << endl << "***** error\n"<< e.what() << endl;
	}
	catch (const domain_error& e)
	{
		cout << endl << "***** error\n" << e.what() << endl;
	}

	return 0;
}
