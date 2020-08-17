#include "polynomial.h"
#include <ctime>
#include <iomanip>

double randomValueOnInterval(double minimum, double maximum);

int main()
{
	// Initialization for the time-based random function.
	srand(time(NULL));

	// Create two polynomials to use.
	Polynomial first;
	Polynomial second;

	// Choose a random small degree and make an array.
	int firstDegree = (int)randomValueOnInterval(3, 7);
	ipointer coef;
	coef = new int[firstDegree + 1];

	// Choose small random coefficient values.
	for (int i = 0; i <= firstDegree; i++)
	{
		coef[i] = (int)randomValueOnInterval(-10, 10);
	}

	// Create the polynomial.
	first = Polynomial(coef, firstDegree);

	// Delete the array.
	delete[] coef;

	// Choose a random small degree and make an array.
	int degree = randomValueOnInterval(1, 5);
	coef = new int[degree + 1];

	// Choose small random coefficient values.
	for (int i = 0; i <= degree; i++)
	{
		coef[i] = randomValueOnInterval(-10, 10);
	}

	// Create the polynomial.
	second = Polynomial(coef, degree);

	// Create a random constant and make its value known.
	int randomInteger = randomValueOnInterval(1, 10) * ((rand() > RAND_MAX / 2) ? 1 : -1);
	cout << "Constant: " << to_string(randomInteger) + "\n";

	// Test toString.
	cout << "First as a string: " << first.toString() + "\n";
	cout << "Second as a string: " << second.toString() + "\n";

	// Test getDegree.
	cout << "Degree: " << to_string(first.getDegree()) + "\n";

	// Test getCoefficientAt.
	for (int change = 0; degree - change >= 0; change++)
	{
		cout << "Coefficient " + to_string(degree - change) + ": " << to_string(first.getCoefficientAt(degree - change)) + "\n";
	}

	// Test the evaluation operation.
	cout << "Evaluation at x = " + to_string(randomInteger) + ": " << to_string(first.evaluateAt(randomInteger)) << "\n";

	// Test addition operation on Polynomials.
	cout << "Two polynomials:" << (first + second).toString() << "\n";
	cout << "Left polynomial:" << (first + randomInteger).toString() << "\n";
	cout << "Right polynomial:" << (randomInteger + second).toString() << "\n";

	return 0;
}

// This function is used to generate a random polynomial. It returns a random value 
// from the input range.
double randomValueOnInterval(double minimum, double maximum)
{
	return minimum + ((double)rand() / RAND_MAX) * (maximum - minimum);
}