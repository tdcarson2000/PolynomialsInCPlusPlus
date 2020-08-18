# PolynomialsInCPlusPlus

Polynomial is a library that defines a Polynomial dynamic type for use in C++. 
It should support evaluation of polynomials, addition, subtraction, and multiplication of polynomials and 
numeric types, as well as conversion to strings. For those unfamiliar with polynomials, more information 
may be found [here](https://en.wikipedia.org/wiki/Polynomial).

## Installation

Use 
```
git clone https://github.com/tdcarson2000/PolynomialsInCPlusPlus
```
to clone the repository to your own local repository and build PolynomialsInCPlusPlus.sln using 
Microsoft Visual Studio or any other compatible C++ IDE.

## Usage

#### UML Class Diagram
![UML Diagram for Polynomial Class](https://github.com/tdcarson2000/PolynomialsInCPlusPlus/blob/master/docs/UML.jpg)

#### Importing into your project
```c++
import "Polynomial.h";
```

#### Creating a Polynomial
```c++
// Using a dynamic integer array.
Polynomial polynomial1 = Polynomial(/*int* */ coefficients, /*int*/ degree);

// Using another Polynomial.
Polynomial polynomial2 = Polynomial(polynomial1);

// Using the default constructor. This initializes it to an empty polynomial of degree 0.
Polynomial polynomial3 = Polynomial();
```

#### Operations with Polynomials
##### Assignments
```c++
polynomial3 = polynomial1;
```

##### Addition
```c++
polynomial1 + polynomial2;
polynomial1 + intger;
integer + polynomial2;
```

##### Subtraction
```c++
polynomial1 - polynomial2;
polynomial1 - intger;
integer - polynomial2;
```

##### Multiplication
```c++
polynomial1 * polynomial2;
polynomial1 * intger;
integer * polynomial2;
```

##### Evaluation
```c++
polynomial1.evaluateAt(/*double*/ xValue);
```

#### Accessing Fields
##### Degree
```c++
polynomial1.getDegree();
```

##### Coefficients
```c++
polynomial1.getCoefficientAt(/*int*/ termPower);
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
