#include "complex_number.h"
#include <iostream>
#include <string>
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
};

// ComplexNumber ComplexNumber::operator+(ComplexNumber* &a)
// {
//     return ComplexNumber(a->getRealUnit()+this->getRealUnit(),a->getImagineUnit()+this->getImagineUnit());
// };

// ComplexNumber ComplexNumber::operator-(ComplexNumber &a)
// {
//     return ComplexNumber(this->getRealUnit()-a.getRealUnit(),this->getImagineUnit()-a.getImagineUnit());
// };

// ComplexNumber ComplexNumber::operator=(ComplexNumber* &a)
// {
//     *this->real = a->getRealUnit();
//     *this->imagine = a->getImagineUnit();
//     return *this;
// };

// bool ComplexNumber::operator==(ComplexNumber* &a)
// {
//     return (*this->real == a->getRealUnit() && *this->imagine==a->getImagineUnit()) ? true:false;
// };  

std::string ComplexNumber::toString()
{
    char* tmp = new char[100];
    sprintf(tmp,"%f + %fi",*this->real, *this->imagine);
    std::string res(tmp);
    delete tmp;
    return res;
};
