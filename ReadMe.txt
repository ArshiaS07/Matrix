The Matrix.hpp file provides a C++ header-only implementation of a matrix class within the ArshiaMath namespace. This class supports various matrix operations and functionalities. Below is an overview of the class and its member functions:

Class: ArshiaMath::Matrix

This class represents a matrix object and provides operations for matrix arithmetic and manipulation.
Constructors:

Matrix(): Default constructor that creates an empty matrix.
Matrix(size_t rows, size_t cols): Parameterized constructor that creates a matrix with the given number of rows and columns.
Matrix(const Matrix &other): Copy constructor that creates a deep copy of an existing matrix.
Destructor:

~Matrix(): Destructor that frees the dynamically allocated memory for the matrix.
Matrix Operations:

operator=: Assignment operator for assigning one matrix to another.
operator+: Addition operator for adding two matrices.
operator-: Subtraction operator for subtracting one matrix from another.
operator*: Matrix multiplication operator for multiplying two matrices.
operator*: Scalar multiplication operator for multiplying a matrix by a scalar.
operator*: Friend function for scalar multiplication in the form scalar * matrix.
operator!=: Inequality operator for checking if two matrices are not equal.
elementWiseEquals: Element-wise equality check between two matrices.
equals: Equality check between two matrices.
Accessors and Indexing:

operator[]: Indexing operator for accessing matrix elements.
getRows(): Getter function for retrieving the number of rows in the matrix.
getCols(): Getter function for retrieving the number of columns in the matrix.
Matrix Manipulation:

resize: Resizes the matrix to the specified number of rows and columns.
freeMemory: Frees the memory allocated for the matrix.
allocateMemory: Allocates memory for the matrix with the specified number of rows and columns.
reallocateMemory: Reallocates memory for the matrix with the specified number of rows and columns.
setIdentity: Sets the matrix as an identity matrix.
setOne: Sets all matrix elements to 1.
setZero: Sets all matrix elements to 0.
setMatFromFile: Reads matrix elements from a file and sets them in the matrix.
Output Stream Operator:

operator<<: Overloading the stream insertion operator for Matrix objects, allowing the matrix to be printed to an output stream.