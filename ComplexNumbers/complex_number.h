#ifndef _COMPLEX_NUM_H_
#define _COMPLEX_NUM_H_
#include <string>

class ComplexNumber
{
private:
  float *real;    // Real Unit of complex number
  float *imagine; // Imaginary Unit of complex number
public:
  ComplexNumber();
  ComplexNumber(float _real, float _imagine);
  ~ComplexNumber();
  void printCN();
  float getRealUnit();
  float getImagineUnit();
  float abs();
  float tgArg();
  float Arg();
  // ComplexNumber operator+(ComplexNumber* &a);
  // ComplexNumber operator+(ComplexNumber* &a,ComplexNumber* &b);
  // ComplexNumber operator-(ComplexNumber &a);
  // ComplexNumber operator=(ComplexNumber* &a);
  // bool operator==(ComplexNumber* &a);
  std::string toString();
};

#endif