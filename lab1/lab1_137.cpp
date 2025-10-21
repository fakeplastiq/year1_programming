#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <format>
using namespace std;

double get_double ();
bool is_in_domain(double x);
double f (double x);

int main () {
    cout << "The author of this program is Ihor Bondar, K-15" << endl;
    cout << "The program calculates the value of the function by given x. Variant 137" << endl;
    try {
        double x = get_double();
        cout << "***** do calculations ... ";
        double result = 0;
        if (is_in_domain(x)) {
            result = f(x);
        } else {
            result = NAN;
        }
        cout << "done" << endl;
        cout << format("for x = {:.5f}", x) << endl;
        cout << "result = ";
        if (not isnan(result)) {
            cout << format("{:.5f}", result);
        } else {
            cout << "undefined";
        }
        cout << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}

double f(double x)
/*
 * function evaluates and returns value of the expression by given x
 */
{
    return sin(24.0/64.0) - 18*M_PI-60*M_E*7/((x+14)*(x-10))+6*acos(x-9)+(12+sqrt(x-8))/(x-13);
}

double get_double ()
/*
 * function to input double variables
 * prompts user for value of x, gets the value and returns it
 * if cin fails, it clears cin and throws an exception
 */
{
    cout << "Enter x (8 <= x, x < 10): ";
    double x;
    cin >> x;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("wrong input");
    }
    cout << endl;
    return x;
}

bool is_in_domain (double x)
/*
 * function checks x for being in domain of the expression
 */
{
    return x >= 8 && x < 10;
}