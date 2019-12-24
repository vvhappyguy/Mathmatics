#include <iostream>
#include <cmath>
using namespace std;
double iteration_method(double initial_value, double accuracy, double (*function_phi)(double), double (*source_function)(double))
{
    int i = 1;
    double prevX, nextX = initial_value;
    cout << "X" << 0 << " = " << initial_value << endl;
    do
    {
        prevX = nextX;
        nextX = function_phi(prevX);
        cout << "X" << i << " = " << nextX << endl;
        i++;
    }
    while (abs(source_function(nextX)) > accuracy);
    return nextX;
}
double Function(double x) {return pow(x, 3) - 0.1 * pow(x, 2) + 0.4*x  - 1.5;}
double tangential_Function(double x) {return x - Function(x)/(3*pow(x,2) -0.2*x + 0.4);}
int main()
{
    cout << "task 3.1.2" << endl;
    double answer = iteration_method(0, 0.001, tangential_Function, Function);
    cout << "Approximate root x = " << answer << endl;
    cout << "f(x) = " << Function(answer) << endl;
    return 0;}
