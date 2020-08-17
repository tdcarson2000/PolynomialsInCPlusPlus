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
* This function is an accessor for the degree of the Polynomial. It returns the degree field.
*
*/
int Polynomial::getDegree() const
{
	// Return the degree of this Polynomial.
	return this->degree;
}

/*
* This function sets the degree of the Polynomial when the power of the coefficient is too high.
*
*/
void Polynomial::setDegree(const int index)
{
	// Make a new array with the length that of the new degree plus 1.
	ipointer coefficients = new int[index + 1];

	// Copy the original array to the new one.
	for (int i = 0; i <= this->degree; i++)
	{
		// Set the element here to the one in the current array.
		coefficients[i] = this->coefficients[i];
	}

	// Set any new terms to zero.
	for (int i = this->degree + 1; i <= index; i++)
	{
		coefficients[i] = 0;
	}

	// Delete the old array.
	delete[] this->coefficients;

	// Set the degree to the index that is too high for the current Polynomial.
	this->degree = index;

	// Set the coefficients to the newly-sized array.
	this->coefficients = coefficients;
}

/*
* This function acts as an accessor for a coefficient in the Polynomial.
*
*/
int Polynomial::getCoefficientAt(const int index) const
{
	// Check that the passed index is in the array.
	if (index <= this->degree && index >= 0)
	{
		// Return the value of the coefficient of this degree.
		return this->coefficients[index];
	}
	else
	{
		// Return 0 since the coefficient of such a term past the defined array is 0.
		return 0;
	}
}

/*
* This function takes an index and a coefficient to set the coefficient at that degree to
* a new one.
*
*/
void Polynomial::setCoefficient(const int index, const int coefficient)
{
	// Check if the degree is within the current bounds.
	if (index <= this->degree && index >= 0)
	{
		// Set the coefficient to the new value.
		this->coefficients[index] = coefficient;
	}
	else
	{
		// The coefficient is out of bounds, so check in which way it is out of bounds.
		if (index > degree)
		{
			// Set the degree to the higher value that was chosen.
			this->setDegree(index);

			// Fill the array with this coefficient.
			this->coefficients[index] = coefficient;
		}
		else
		{
			// The Polynomial class does not apply for Polynomials with terms of negative powers.
			return;
		}
	}
}

/*
* This function evaluates the Polynomial given a value for the variable.
*
*/
double Polynomial::evaluateAt(const double xValue) const
{
	// Define a double for the value.
	double value = 0;

	// Iterate through the array until all terms have been multiplied and added.
	for (int i = 0; i <= degree; i++)
	{
		// Multiply by the xValue for this iteration and add the next coefficient so that each term will be multiplied by the
		// xValue the appropriate number of times due to distributed multiplication. Start from the end.
		value = (value * xValue) + this->coefficients[degree - i];
	}

	// Return the value of the Polynomial.
	return value;
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

/*
* Overloaded assignment operator for the Polynomial that creates a copy of a Polynomial.
*
*/
Polynomial& Polynomial::operator = (const Polynomial& assignmentPolynomial)
{
	// Check whether the Polynomials have the same degree.
	if (assignmentPolynomial.degree != this->degree)
	{
		// Delete the coefficient array and make a new one of the righthand degree.
		delete[] this->coefficients;
		this->coefficients = new int[assignmentPolynomial.degree + 1];
	}

	// Set each field to be the same.
	this->degree = assignmentPolynomial.degree;
	for (int i = 0; i <= this->degree; i++)
	{
		// Set the coefficient at this index to be the same.
		this->coefficients[i] = assignmentPolynomial.coefficients[i];
	}

	// Return the value on the lefthand side.
	return *this;
}

/*
* Overloaded addition operator that adds two Polynomials by adding the coefficients of each term.
*
*/
Polynomial& Polynomial::operator + (const Polynomial& addPolynomial) const
{
	// Declare a new Polynomial to be returned.
	Polynomial* sum = new Polynomial();

	// Figure out which Polynomial is larger.
	if (this->degree >= addPolynomial.degree)
	{
		// Set the degree to that of the left Polynomial.
		sum->setDegree(this->degree);
	}
	else
	{
		// Set the degree to that of the right Polynomial.
		sum->setDegree(addPolynomial.degree);
	}

	// Set the value at each index to that of the sum of each Polynomial's coefficients at that index until the end.
	for (int i = 0; i <= sum->degree; i++)
	{
		// Add the values and set the coefficient to that.
		sum->setCoefficient(i, this->getCoefficientAt(i) + addPolynomial.getCoefficientAt(i));
	}

	// Return the new Polynomial.
	return *sum;
}

/*
* Overloaded addition operator that adds an integer as a constant to a Polynomial.
*
*/
Polynomial& Polynomial::operator + (const int& addConstant) const
{
	// Create an array containing the integer to construct a Polynomial.
	ipointer constantCoefficient = new int[1];

	// Set the array's one indexed variable to the constant.
	constantCoefficient[0] = addConstant;

	// Create a Polynomial of degree 0 that is just the integer using the array.
	Polynomial* constant = new Polynomial(constantCoefficient, 0);

	// Add the numbers as Polynomials.
	return *this + *constant;
}

/*
* Overloaded addition operator that adds Polynomials to a constant when order is swapped.
*
*/
Polynomial& operator + (const int& addConstant, const Polynomial & addPolynomial)
{
	// Create an array containing the integer to construct a Polynomial.
	ipointer constantCoefficient = new int[1];

	// Set the array's one indexed variable to the constant.
	constantCoefficient[0] = addConstant;

	// Create a Polynomial of degree 0 that is just the integer using the array.
	Polynomial* constant = new Polynomial(constantCoefficient, 0);

	// Add the numbers as Polynomials.
	return addPolynomial + *constant;
}

/*
* Overloaded subtraction operator that subtracts two polynomials by subtracting the coefficients at each term.
*
*/
Polynomial& Polynomial::operator - (const Polynomial& subPolynomial) const
{
	// Declare a new Polynomial to be returned.
	Polynomial* difference = new Polynomial();

	// Figure out which Polynomial is larger.
	if (this->degree >= subPolynomial.degree)
	{
		// Set the degree to that of the left Polynomial.
		difference->setDegree(this->degree);
	}
	else
	{
		// Set the degree to that of the right Polynomial.
		difference->setDegree(subPolynomial.degree);
	}

	// Set the value at each index to that of the sum of each Polynomial's coefficients at that index until the end.
	for (int i = 0; i <= difference->degree; i++)
	{
		// Add the values and set the coefficient to that.
		difference->setCoefficient(i, this->getCoefficientAt(i) - subPolynomial.getCoefficientAt(i));
	}

	// Return the new Polynomial.
	return *difference;
}

/*
* Overloaded subtraction operator that subtracts an integer as a constant from a Polynomial.
*
*/
Polynomial& Polynomial::operator - (const int& subConstant) const
{
	// Create an array containing the integer to construct a Polynomial.
	ipointer constantCoefficient = new int[1];

	// Set the array's one indexed variable to the constant.
	constantCoefficient[0] = subConstant;

	// Create a Polynomial of degree 0 that is just the integer using the array.
	Polynomial* constant = new Polynomial(constantCoefficient, 0);

	// Subtract the numbers as Polynomials.
	return *this - *constant;
}

/*
* Overloaded subtraction operator that subtracts Polynomials from a constant when order is swapped.
*
*/
Polynomial& operator - (const int& subConstant, const Polynomial & subPolynomial)
{
	// Create an array containing the integer to construct a Polynomial.
	ipointer constantCoefficient = new int[1];

	// Set the array's one indexed variable to the constant.
	constantCoefficient[0] = subConstant;

	// Create a Polynomial of degree 0 that is just the integer using the array.
	Polynomial* constant = new Polynomial(constantCoefficient, 0);

	// Subtract the numbers as Polynomials.
	return *constant - subPolynomial;
}