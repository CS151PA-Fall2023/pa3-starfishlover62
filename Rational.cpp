#include "Rational.h"


Rational::Rational() : Rational(1,1){}

Rational::Rational(int numer, int denom){
    numerator = numer;
    denominator = denom;
}


Rational::Rational(std::string str){
    std::string numer = "";
    std::string denom = "";
    bool denominator = false;
    bool negative = false;
    for(unsigned i = 0; i < str.size(); ++i){
        if(str[i] == '/'){
            denominator = true;
        } else if(denominator){
            if(str[i] == '-'){
                negative = !negative;
            } else {
                denom += str[i];
            }
        } else {
            if(str[i] == '-'){
                negative = !negative;
            } else {
                numer += str[i];
            }
        }
        if(numer != ""){
            this->numerator = std::stoi(numer);
        } else {
            this->numerator = 1;
        }
        
        if(denom != ""){
            this->denominator = std::stoi(denom);
        } else {
            this->denominator = -1;
        }


        if(negative){
            this->numerator *= -1;
        }
    }
}

Rational::Rational(const Rational &right){
    this->numerator = right.getNumerator();
    this-> denominator = right.getDenominator();
}

std::ostream &operator<<(std::ostream &output, const Rational &R ) {
    if(R.getDenominator() == 1){
        output << R.getNumerator();
    } else {
        output << R.getNumerator() << '/' << R.getDenominator();
    }
    return output;
   }

Rational& Rational::operator=(const Rational &right){
    this->numerator = right.getNumerator();
    this->denominator = right.getDenominator();
    return *this;
}

Rational::operator double() const {
    double value = 0;
    value = numerator;
    value /= denominator;
    return value;
}


bool Rational::reduce(){
    bool reduced = false;
    for(int i = 2; i <= denominator; ++i){
        if(denominator % i == 0 && numerator % i == 0){
            denominator /= i;
            numerator /= i;
            i = 1;
            reduced = true;
        }
    }
    return reduced;
}