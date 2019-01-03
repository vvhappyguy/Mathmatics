#ifndef _COMPLEX_NUM_H_
#define _COMPLEX_NUM_H_

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
};

#endif