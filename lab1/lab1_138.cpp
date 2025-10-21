#include <iostream>
#include <cmath>
#include <format>

using namespace std;

// функція f, рахує значення даного виразу для введеного х, окрім х<-7 та окрім х=3, що не входять в область визначення
// при х=3, функція повертає -inf, при х<-7 функція повертає -nan(ind)
double f(double x) {
    double expression = cos(22.0 / 67.0) - (25 * M_PI) / (45 * M_E) * (5 / ((x + 10) * (x - 3)))
                      + 12 * cos(x - 6) - sqrt(x + 7);
    return expression;
}
bool domain(double x) {
    return x + 7 >= 0 && x != 3;
}
double inputX() {
    double x;
    cout << "Enter real x (except 3, x<-7) : ";
    cin >> x;
    if (cin.fail()) {
        throw runtime_error("wrong input");
    }
    return x;
}
int main() {
    try {
        cout << "The author of this code is Burkova Veronika" << endl;
        cout << "This program calculates the value of expressions by given x. Variant 138" << endl;

        double x = inputX();
        cout << endl;
        cout << "***** do calculations ... ";
        double result = 0;

        if (domain(x)) {
            result = f(x);
        } else {
            result = NAN;
        }
        cout << "done" << endl;
        cout << format("for x = {:.5f}", x) << endl;
        if (not isnan(result)) {
            cout <<format ("result = {:.9f}", result) << endl;
        }
        else {
            cout << "result = undefined" << endl;
        }
    }
    catch (const exception& error) {
        cout << endl;
        cout << error.what() << endl;
    }
    return 0;
}
