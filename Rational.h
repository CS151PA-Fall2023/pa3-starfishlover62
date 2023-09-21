#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
#include <iostream>

class Rational {
    public:
    Rational();
    Rational(int numer, int denom);
    friend std::ostream &operator<<(std::ostream &output, const Rational &R );
    Rational& operator=(const Rational &right);
    operator double() const;

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }


    private:
    int numerator;
    int denominator;


};




#endif