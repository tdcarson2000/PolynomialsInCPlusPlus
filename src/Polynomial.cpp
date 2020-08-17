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

/*
* This function is the destructor for the Polynomial class. It deallocates space for the dynamic array.
*
*/
Polynomial::~Polynomial()
{
	// Get rid of the dynamically allocated array.
	delete[] this->coefficients;
}

/*
* This function returns a Polynomial as a string.
*
*/
const string Polynomial::toString() const
{
	// Declare a string to hold the Polynomial in string form.
	string polynomialString = "";

	// Find the first non-zero term. Set the index to negative one of there is none to end the toString 
	// process.
	int positionOfFirstValue = -1;

	for (int i = this->degree; i >= 0; i--)
	{
		if (this->coefficients[i] != 0)
		{
			positionOfFirstValue = i;
			break;
		}
	}

	// Loop through the Polynomial and add each term and coefficient to it with the correct power.
	for (int i = positionOfFirstValue; i >= 0; i--)
	{
		// Declare a string for this term.
		string term = "";

		// Check if the current term is 0.
		if (this->coefficients[i] != 0)
		{
			// Check if the current term is positive, negative, or zero. Add a sign based
			// on this.
			if (this->coefficients[i] > 0 && i < positionOfFirstValue)
			{
				term += " + ";
			}
			else if (this->coefficients[i] < 0)
			{
				term += " - ";
			}

			// Add the coefficient's value if it is not one.
			if (abs(this->coefficients[i]) != 1 || i == 0)
			{
				term += to_string(abs(this->coefficients[i]));
			}

			// Check if it is the constant term.
			if (i > 0)
			{
				// Check if it is the power of 1.
				if (i == 1)
				{
					// Concatenate the variable.
					term += "x";
				}
				else
				{
					// Concatenate the variable and power.
					term += "x^" + to_string(i);
				}
			} // Do nothing if it is the constant term.
		} // Do nothing if the coefficient is 0.

		  // Add the term to the polynomial string.
		polynomialString += term;
	}

	// Return the string.
	return polynomialString;
}