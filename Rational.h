/**
 * @file Rational.h
 * @author Josh Gillum
 * @brief Rational class definition. Allows for the storage and manipulation of rational numbers
 * @version 1.0
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
#include <iostream>

class Rational {
    public:
    // Constructors
    Rational();
    Rational(int numer, int denom);
    Rational(std::string str);
    Rational(const char * str);
    Rational(const Rational &right);

    // Operator overloads
    friend std::ostream &operator<<(std::ostream &output, const Rational &R );
    Rational& operator=(const Rational &right);
    Rational operator+(const Rational &right);
    Rational operator-(const Rational &right);
    Rational operator*(const Rational &right);
    Rational operator/(const Rational &right);
    operator double() const;

    // Getter functions

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    // General Functions
    bool reduce();


    private:
    int numerator; // The numerator of the rational number
    int denominator; // The denominator of the rational number

};

#endif