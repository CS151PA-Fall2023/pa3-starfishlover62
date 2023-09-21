/**
 * @file Rational.cpp
 * @author Josh Gillum
 * @brief Function definitions for the Rational class
 * @version 1.0
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Rational.h"

/**
 * @brief Default constructor. Sets numerator and denominator both to 1
 * 
 */
Rational::Rational() : Rational(1,1){}


/**
 * @brief Constructor given the numerator and denominator in integer forms
 * 
 * @param numer, the numerator, as an integer
 * @param denom, the denominator as an integer
 */
Rational::Rational(int numer, int denom){
    numerator = numer;
    denominator = denom;
}


/**
 * @brief Convert constructor given a string. Calls the convert constructor for a c-string
 * 
 * @param str, a string object representing the rational (ex: "3/5")
 */
Rational::Rational(std::string str) : Rational(&(str[0])){}


/**
 * @brief Convert constructor given a c-string.
 * 
 * @param str, the starting address of a c-string. The c-string should contain an integer followed
 * by a slash followed by another integer (ex: "1/3"). If a slash is not found, the entire
 * integer of the string will be considered the numerator, and the denominator will be set to 1
 */
Rational::Rational(const char * str) {
    std::string numer = ""; // The string representing the numerator
    std::string denom = ""; // The string representing the denominator
    bool denominator = false; // If the current portion is in the denominator
    bool negative = false; // If the rational is negative
    int index = 0; // The index of the c-string
    do {
        if(str[index] == '/'){ // Changes to start reading all following values to the denominator
            denominator = true;
        } else if(denominator){ // Reads values to the denominator
            if(str[index] == '-'){ // Checks if it is negative
                negative = !negative;
            } else {
                if(std::isdigit(str[index])){ // Adds the character to the denominator string if it is a number
                    denom += str[index];
                }
            }
        } else { // Reads value to numerator
            if(str[index] == '-'){ // Checks if the value is negative
                negative = !negative;
            } else {
                if(std::isdigit(str[index])){ // Adds the character to the numerator string if it is a number
                    numer += str[index];
                }
            }
        }
        if(numer != ""){ // Checks if a numerator was read at all
            this->numerator = std::stoi(numer); // Converts the numerator string to an integer
        } else {
            this->numerator = 1; // Sets numerator to 1 if it was not read
        }
        
        if(denom != ""){ // Checks if a denominator was read at all
            this->denominator = std::stoi(denom); // Converts the denominator string to an integer
        } else {
            this->denominator = -1; // Sets denominator to 1 if it was not read
        }

        if(negative){ // Makes the rational negative if it should be
            this->numerator *= -1;
        }
        ++index; // Increments index to next character
    } while(*(str+index) != '\0'); // Loop ends if null terminator is reached
}


/**
 * @brief Copy constructor
 * 
 * @param right, the Rational object being copied
 */
Rational::Rational(const Rational &right){
    this->numerator = right.getNumerator();
    this-> denominator = right.getDenominator();
}


/**
 * @brief Overloads stream insertion operator. Will output only the numerator if the
 * denominator is 1, otherwise outputs <numerator>/<denominator>
 * 
 * @param output, the ostream object that the output is being added to
 * @param R, the object whose values are being output
 * @return std::ostream&, returns the ostream output
 */
std::ostream &operator<<(std::ostream &output, const Rational &R ) {
    if(R.getDenominator() == 1){
        output << R.getNumerator();
    } else {
        output << R.getNumerator() << '/' << R.getDenominator();
    }
    return output;
   }


/**
 * @brief Overloads the assignment operator. Sets the numerator and denominator of this object
 * to the values of the object on the right
 * 
 * @param right, the object whose values are being copied
 * @return Rational&, this object
 */
Rational& Rational::operator=(const Rational &right){
    this->numerator = right.getNumerator();
    this->denominator = right.getDenominator();
    return *this;
}


/**
 * @brief Overloads the addition operator
 * 
 * @param right, the object being added to this object
 * @return Rational, a Rational object whose value is the sum of this object and the right object
 */
Rational Rational::operator+(const Rational &right){
    int numer = 1;
    int denom = 1;

    denom = this->getDenominator() * right.getDenominator(); // Gets a common denominator

    // Adds the numerators multiplied by the other terms denominator
    numer = this->getNumerator() * right.getDenominator() + right.getNumerator() * this->getDenominator(); 
    Rational sum(numer,denom);
    sum.reduce();
    return sum;
}


/**
 * @brief Overloads the subtraction operator
 * 
 * @param right, the object being subtracted from this object
 * @return Rational, a Rational object whose value is the difference of the two objects
 */
Rational Rational::operator-(const Rational &right){
    int numer = 1;
    int denom = 1;

    denom = this->getDenominator() * right.getDenominator();
    numer = this->getNumerator() * right.getDenominator() - right.getNumerator() * this->getDenominator();
    Rational sum(numer,denom);
    sum.reduce();
    return sum;
}


/**
 * @brief Overloads the multiplication operator
 * 
 * @param right, the object being multiplied with this object
 * @return Rational, a Rational object whose value is the product of the two objects
 */
Rational Rational::operator*(const Rational &right){
    int numer = 1;
    int denom = 1;

    denom = this->getDenominator() * right.getDenominator();
    numer = this->getNumerator() * right.getNumerator();
    Rational sum(numer,denom);
    sum.reduce();
    return sum;
}


/**
 * @brief Overloads the division operator
 * 
 * @param right, the object being divided into this object
 * @return Rational, a Rational object whose value is the quotient of the two objects
 */
Rational Rational::operator/(const Rational &right){
    int numer = 1;
    int denom = 1;

    denom = this->getDenominator() * right.getNumerator();
    numer = this->getNumerator() * right.getDenominator();
    Rational sum(numer,denom);
    sum.reduce();
    return sum;

}


/**
 * @brief Overloads conversion to a double
 * 
 * @return double, the decimal representation of the rational. Simply divides the numerator by the denominator
 */
Rational::operator double() const {
    double value = 0;
    value = numerator;
    value /= denominator;
    return value;
}


/**
 * @brief Reduces the rational number (takes a like factor out of both the numerator and denominator)
 * 
 * @return true, the Rational was reduced
 * @return false, the Rational was not reduced
 */
bool Rational::reduce(){
    bool reduced = false;
    for(int i = 2; i <= denominator; ++i){ // i represents a potential factor
        if(denominator % i == 0 && numerator % i == 0){ // If it is a factor of both the numerator and denominator
            // Takes the factor out of the terms
            denominator /= i;
            numerator /= i;
            // Resets the potential factor to 1 (it will increase to 2 at the end of this iteration for the next one)
            i = 1;
            reduced = true; // Sets the value to true, since it was reduced
        }
    }
    return reduced;
}