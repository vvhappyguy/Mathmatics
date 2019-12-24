#include <iostream>
#include <cmath>
using namespace std;
// A0 - начальное приближение метода хорд
// B0 - начальное приближение метода касательных
double  combined_method(double A0, double B0, double accuracy,
double (*chordsFunc)(double, double), double (*tangentsFunc)(double), double (*f)
(double))
{
    int i = 1;
    cout << "A" << 0 << " = " << A0 << " "
    << "B" << 0 << " = " << B0 << endl;
    do
    {
        if(A0 == B0) return A0;
        A0 = chordsFunc(A0, B0);
        B0 = tangentsFunc(B0);
        cout    << "A" << i << " = " << A0 << " "
                << "B" << i << " = " << B0 << endl;
        i++;
    }
    while (abs(f(abs(A0+B0)/2.)) > accuracy);
    return A0;
}

double Function(double x) {return pow(x, 3) - 12*x + 6;}
double chord_Function(double x, double fixedX){return x - Function(x)*(fixedX - x)/(Function(fixedX) - Function(x));}
double tangential_Function(double x) {return x - (Function(x)/((3*pow(x, 2) - 12)));}
int main()
{
    cout << "Task 3.3" << endl;
    double answer = combined_method(2, 1, 0.001, chord_Function, tangential_Function, Function);
    cout << "Approximate root x = " << answer << endl;
    cout << "f(x) = " << Function(answer) << endl;
    return 0;
}
