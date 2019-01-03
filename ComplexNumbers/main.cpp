#include <iostream>
#include "complex_number.h"

int main()
{

ComplexNumber* num = new ComplexNumber(0,2);

num->printCN();
std::cout << "Imaginary UNIT: " << num->getImagineUnit() << std::endl;
std::cout << "Real UNIT: " << num->getRealUnit() << std::endl;

std:: cout << "Abs: " << num->abs() << std::endl;

std:: cout << "tgArg: " << num->tgArg() << std::endl;
std:: cout << "Arg: " << num->Arg() << std::endl;

delete num;
return 0;
}