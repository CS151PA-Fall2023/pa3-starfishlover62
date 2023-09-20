#include "Rational.h"


Rational::Rational() : Rational(1,1){}

Rational::Rational(int numer, int denom){
    numerator = numer;
    denominator = denom;
}