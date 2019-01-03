#include "complex_number.h"
#include <iostream>
#include <math.h>

ComplexNumber::ComplexNumber()
{
    std::cout << "[CN] - C-tor Default " << std::endl;

    this->real = new float;
    this->imagine = new float;

    *this->real = 0;
    *this->imagine = 0;
};

ComplexNumber::ComplexNumber(float _real, float _imagine)
{
    std::cout << "[CN] - C-tor with ARGVs: " << _real << " " << _imagine << std::endl;

    this->real = new float;
    this->imagine = new float;

    *this->real = _real;
    *this->imagine = _imagine;
};

ComplexNumber::~ComplexNumber()
{
    std::cout << "[CN] - D-tor " << std::endl;

    delete this->real;
    delete this->imagine;
};

void ComplexNumber::printCN()
{
    std::cout << *this->real << " + " << *this->imagine << "i" << std::endl;
};

float ComplexNumber::getImagineUnit() { return *this->imagine; }
float ComplexNumber::getRealUnit() { return *this->real; }

float ComplexNumber::abs()
{
    return sqrt((*this->imagine) * (*this->imagine) + (*this->real) * (*this->real));
};

float ComplexNumber::tgArg()
{
    return (*this->imagine/(*this->real));
};

float ComplexNumber::Arg()
{
    return tan(this->tgArg());
}
