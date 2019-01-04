#include <iostream>
#include "complex_number.h"
#include <string>

int main()
{

ComplexNumber* num = new ComplexNumber(0,2);
ComplexNumber* num1 = new ComplexNumber(1,0);

num->printCN();
std::cout << "Imaginary UNIT: " << num->getImagineUnit() << std::endl;
std::cout << "Real UNIT: " << num->getRealUnit() << std::endl;

std:: cout << "Abs: " << num->abs() << std::endl;

std:: cout << "tgArg: " << num->tgArg() << std::endl;
std:: cout << "Arg: " << num->Arg() << std::endl;

std::string a = num->toString();
std::cout << a << std::endl;

delete num, num1;
return 0;
}