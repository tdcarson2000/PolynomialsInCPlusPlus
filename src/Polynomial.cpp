#include "Polynomial.h"

/*
* This function is the default constructor for the Polynomial class. It makes a Polynomial with no coefficients.
*
*/
Polynomial::Polynomial()
{
	// Create a Polynomial of degree 0.
	this->degree = 0;
	this->coefficients = new int[0];
}

/*
* This function is a constructor for the Polynomial class that takes an array to initialize a Polynomial.
*
*/
Polynomial::Polynomial(const ipointer coefficients, const int degree)
{
	// Set the degree to the passed array's degree.
	this->degree = degree;

	// Create a new array of length degree plus 1.
	this->coefficients = new int[degree + 1];

	// Set the coefficient array to have the same contents as the passed pointer.
	for (int i = 0; i <= degree; i++)
	{
		// Set the indexed variable at this index equal to the value in the passed pointer.
		this->coefficients[i] = coefficients[i];
	}
}

/*
* This function is the copy constructor for the Polynomial. It sets the Polynomial to be the same degree and
* copies the contents of one array of coefficients into the other.
*
*/
Polynomial::Polynomial(const Polynomial& clone)
{
	// Set the degree of this Polynomial to that of the other and create a new array of that degree plus 1.
	this->degree = clone.degree;
	this->coefficients = new int[this->degree + 1];

	// Fill the array with the vales referenced by the original Polynomial's array.
	for (int i = 0; i <= this->degree; i++)
	{
		// Set the value of this coefficient to the value of the other Polynomial's coefficient here.
		this->coefficients[i] = clone.coefficients[i];
	}
}