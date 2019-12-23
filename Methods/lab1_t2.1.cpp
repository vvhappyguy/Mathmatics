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
double Function(double x) {return pow(x,3)  + 3*x - 1 ;}
double Function_phi(double x) {return x - Function(x)/6;}
int main()
{
    cout << "task 2.1" << endl;
    double answer = iteration_method(0, 0.001, Function_phi, Function);
    cout << "Approximate root x = " << answer << endl;
    cout << "f(x) = " << Function(answer) << endl;
    return 0;
}
