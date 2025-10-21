#include <iostream>
#include <cmath>
#include <iomanip>
#include <exception>
using namespace std;
const double a = -0.9;
const double b = 0.9;

double s(double x, double eps) {
    double a_n = 0.5 * x * x;
    double sum = a_n;
    int n = 1;
    while (a_n>=eps) {
        cout << a_n << endl;
        a_n = (n * x / (n + 2)) * a_n;
        sum += a_n;
        n++;
    }
    return sum;
}

bool domain_eps(double eps) {
    return eps>0;
}

bool domain_x(double x) {
    return x >= a && x <= b;
}

int main() {
    cout << "The author of this program is Burkova Veronika." << endl;
    cout << "This program calculates tha value of the series. ";
    cout << "Variant 138" << endl;
    try {
        cout << "Enter a real from [-0.9; 0.9]: ";
        double x;
        cin >> x;
        if (cin.fail()) {
            throw runtime_error("\n wrong x input");
        }
        if (!domain_x(x)) {
            throw domain_error("\n x goes beyond the scope of definition");
        }


        cout << "Enter a positive eps: "<<endl;
        double eps;
        cin >> eps;
        if (cin.fail()) {
            throw runtime_error("\n wrong eps input");
        }
        if (!domain_eps(eps)) {
            throw domain_error("\n incorrect value");
        }

        cout << "***** do calculations ... ";
        double result = s(x, eps);
        cout << "done" << endl;
        cout << "for x = " << scientific << setprecision(7) << x << endl;
        cout << "for eps = " << scientific << setprecision(5) << eps << endl;
        cout << "result = " << fixed << setprecision(10) << result << endl;
    }
    catch (const exception& error) {
        cout << "***** error " << error.what() << endl;
    }
    return 0;
}

