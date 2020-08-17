#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

// Uses the basic C++ libraries.
#include <stdlib.h>
#include <iostream>
#include <string>

// Uses variables from the standard namespace.
using namespace std;

// Simplified the use of integer pointers using a typedef.
typedef int* ipointer;

/*
 * This class encapsulates the idea of a Polynomial. It contains functions for getting the exponent on the largest
 * term, getting each coefficient, setting each coefficient, and overloaded operators for addition, subtraction,
 * multiplication, and assignment of pPolynomials.
 *
 */
class Polynomial
{
	// The degree of the Polynomial.
	int degree;

	// The set of coefficients for each term.
	ipointer coefficients;

	// Private mutator for the degree to be invoked when a coefficient is added to a higher index.
	void setDegree(const int index);

	// Mutator
	void setCoefficient(const int index, const int coefficient);
public:
	// Constructors
	Polynomial();
	Polynomial(const ipointer coefficients, const int degree);

	// Copy Constructor
	Polynomial(const Polynomial& clone);

	// Accessors
	int getDegree() const;
	int getCoefficientAt(const int index) const;

	// Function for evaluating the Polynomial for a given value.
	double evaluateAt(const double xValue) const;

	// Function for turning a Polynomial to a string.
	const string toString() const;

	// Destructor
	~Polynomial();

	// Overloaded = Operator
	Polynomial& operator = (const Polynomial& equalPolynomial);

	// Overloaded Addition Operators
	Polynomial& operator + (const Polynomial& addPolynomial) const;
	Polynomial& operator + (const int& addConstant) const;
	friend Polynomial& operator + (const int& addConstant, const Polynomial& addPolynomial);

	// Overloaded Subtraction Operators
	Polynomial& operator - (const Polynomial& subPolynomial) const;
	Polynomial& operator - (const int& subConstant) const;
	friend Polynomial& operator - (const int& subConstant, const Polynomial& subPolynomial);

	// Overloaded Multiplication Operators
	Polynomial& operator * (const Polynomial& multPolynomial) const;
	Polynomial& operator * (const int& multConstant) const;
	friend Polynomial& operator * (const int& multConstant, const Polynomial& multPolynomial);
};
#endif // !POLYNOMIAL_H
