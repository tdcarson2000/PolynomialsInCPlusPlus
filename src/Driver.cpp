#include "polynomial.h"
#include <ctime>
#include <iomanip>

double randomValueOnInterval(double minimum, double maximum);

int main()
{
	// Initialization for the time-based random function.
	srand(time(NULL));

	// Create a polynomial to use.
	Polynomial polynomial;

	// Choose a random small degree and make an array.
	int degree = (int)randomValueOnInterval(1, 5);
	ipointer coef;
	coef = new int[degree + 1];

	// Choose small random coefficient values.
	for (int i = 0; i <= degree; i++)
	{
		coef[i] = (int)randomValueOnInterval(-10, 10);
	}

	// Create the polynomial.
	polynomial = Polynomial(coef, degree);

	// Delete the array.
	delete[] coef;

	// Test toString and the constructor.
	cout << "As a string: " << polynomial.toString() + "\n";

	// Test getDegree.
	cout << "Degree: " << to_string(polynomial.getDegree()) + "\n";

	// Test getCoefficientAt.
	for (int change = 0; degree - change >= 0; change++)
	{
		cout << "Coefficient " + to_string(degree - change) + ": " << to_string(polynomial.getCoefficientAt(degree - change)) + "\n";
	}

	return 0;
}

// This function is used to generate a random polynomial. It returns a random value 
// from the input range.
double randomValueOnInterval(double minimum, double maximum)
{
	return minimum + ((double)rand() / RAND_MAX) * (maximum - minimum);
}