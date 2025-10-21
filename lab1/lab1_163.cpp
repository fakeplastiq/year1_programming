#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <format>
using namespace std;

bool domain(double x)
/*
this function cheking domain of math expression
and return true if x is from the domain,
false if it isn't
*/
{
	return((x >= 11) && (x <= 13));
}


double f(double x) 
/*
 this function calculates math expresion
 domain of this function is [ 11; 13 ]
 if x is not from domain result in the end will be "undefined"
 (but we will have the result)
*/
{
	double result;
	result = sin(8 / 55) + ((19 * M_E) / (48 * M_PI)) * (8 / ((x + 9) * (x - 5))) + 11 * asin(x - 12) - sqrt(x + 6);
	return result;
}


double input() 
/* 
this function is responsible for input data and control input mistakes
*/
{
	double x;
	cout << "( Підказка: х це дійсне число зі своєї ОДЗ [ 11; 13 ] )" << endl;
	cout << "Введіть значення x:" << endl;
	cin >> x;
	cout << endl;
	if (cin.fail())
	{
		throw runtime_error("wrong input");
	}
	return x;
}

void about() 
//this function displays information about progect
{
	cout << "Студентка групи К-15 Тупчій Олександра" << endl;
	cout << "Програмний проєкт 1. Варіант 163. Розв'язування математичного виразу." << endl;
}


int main()
{
	system("chcp 65001");
	about();
	
	try
	{
		double x;
		x = input(); 
		double result;
		bool OK = true;
		cout << "***** do calculations ... ";

		OK = domain(x); 
		result = f(x); 

		cout << "done" << endl;
		cout << format("for x = {:.5f}", x) << endl; 

		if (OK) cout << format("result = {:.9f}", result) << endl; 
		else cout << "undefined" << endl; 

	}
	catch(const runtime_error& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
