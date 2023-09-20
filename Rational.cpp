#include "Rational.h"


Rational::Rational() : Rational(1,1){}

Rational::Rational(int numer, int denom){
    numerator = numer;
    denominator = denom;
}

std::ostream &operator<<(std::ostream &output, const Rational &R ) {
      output << R.numerator << '/' << R.denominator;
      return output;
   }