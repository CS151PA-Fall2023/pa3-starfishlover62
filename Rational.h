#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
#include <iostream>

class Rational {
    public:
    Rational();
    Rational(int numer, int denom);
    friend std::ostream &operator<<(std::ostream &output, const Rational &R );



    private:
    int numerator;
    int denominator;


};




#endif