#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <format>

using namespace std;

void about(){
    cout << "The author of this program is Roman Hrynchak from K-15 group" << endl;
    cout << "This program calculates the value of expression, which also concludes trigonometric functions. Variant 140." << endl;
}

// function "input_double" returns input success
bool input_double(double& x, const string& prompt){
    cout << prompt;
    cin >> x;
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool in_domain(double x){
    return (x+10) && (x-11) && (x+13);
}

// function "f" calculates the value of expression for given x (x shouldn't equal -10, 11 or 13);
// for unacceptable x values function returns inf or -inf
double f(double x){
    double value = 0;
    value = cos(17.0 / 70.0);
    value += 8 * M_PI;
    value -= (62 * M_E * 9) / ((x+10) * (x-11));
    value += 7 * atan(x-5);
    value -= 4 / (x+13);
    return value;
}

int main(){
    about();
    double x;
    if (!input_double(x, "Enter real x (x should not equal -10, 11 or -13): ")){
        cout << '\n' << "wrong input" << endl;
    }
    else{
        cout << '\n' << "***** do calculations ...";
        double result;
        bool OK = in_domain(x);
        if (OK) result = f(x);
        cout << " done" << endl;
        cout << format("for x = {:.5f}", x) << endl;
        if (OK) 
            cout << format("result = {:.9f}", result) << endl;
        else
            cout << "result = undefined" << endl;
    }
    return 0;
}