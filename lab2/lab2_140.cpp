#include <iostream>
#include <cmath>
#include <format>
#include <exception>

using namespace std;

const double a=0.0, b=1.0;

void about(){
    cout << "The author of this program is Roman Hrynchak from K-15 group." << endl;
    cout << "This program calculates the value of the series with given accuracy. Variant 140." << endl;
}

void input_double(double& x, const string& prompt, const string& name){
    cout << prompt;
    cin >> x;
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error(format("At time of getting {}: non-numeric value", name));
    }
}

// calculates the value of the series for x with accuracy eps
// if eps is 0 or negative then while cycle won't even start and s will return 1
// if x is greater than 1 function will work until term becomes to big for double type and change it's sign because of it
// if x is negative than program will work as for |x| because we make x = x * x for quicker calculations
double s(double x, double eps){
    double term = 1, sum = 0;
    int k = 0;
    x = x * x;
    while (term >= eps){
        sum += term;
        k += 4;
        term *= x / (k) / (k - 1) / (k-2) / (k-3);
    }
    return sum += term;
}

int main(){
    about();
    try{
        double x, eps;
        input_double(x, format("Enter a real from [{};{}]: ", a, b), "x");
        if (x < a || x > b)
            throw runtime_error("At time of getting x: incorrect value");
        cout << endl;
        input_double(eps, "Enter positive eps: ", "eps");
        if (eps <= 0)
            throw runtime_error("At time of getting eps: incorrect value");
        cout << '\n' << "***** do calculations ...";
        double res = s(x, eps);
        cout << " done" << endl;
        cout << format("for x = {:.7e}", x) << endl;
        cout << format("for eps = {:.5e}", eps) << endl;
        cout << format("result = {:.10f}", res) << endl;
    }
    catch (const runtime_error& e){
        cout << '\n' << "***** error" << endl;
        cout << e.what();
    }
    return 0;
}