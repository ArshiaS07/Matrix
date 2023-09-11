/*
 * Matrix.hpp
 *
 *  Created on: Mar 26, 2023
 *      Author: Arshia Saffari
 */

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace ArshiaMath {

class Matrix {
public:
	// Default constructor
	Matrix();

	// Parameterized constructor
	Matrix(size_t rows, size_t cols);

	// Copy constructor
	Matrix(const Matrix &other);

	// Constructor with initializer list
    Matrix(std::initializer_list<std::initializer_list<double> > init);

	// Destructor
	~Matrix();

	// Matrix operations

	// Assignment operator
	Matrix& operator=(const Matrix &other);

	// Addition of matrices
	Matrix operator+(const Matrix &other) const;

	// Subtraction of matrices
	Matrix operator-(const Matrix &other) const;

	// Matrix multiplication
	Matrix operator*(const Matrix &other) const;

	// Scalar multiplication
	Matrix operator*(double scalar) const;

	// Friend function for scalar multiplication
	friend Matrix operator*(double scalar, const Matrix &matrix);

	// Inequality operator
	bool operator!=(const Matrix &other) const;

	// Element-wise equality check
	Matrix elementWiseEquals(const Matrix& other) const;

	// Equality check
	bool equals(const Matrix& other) const;

	// Indexing operator for accessing matrix elements
	double*& operator[](size_t index);

	// Const version of indexing operator for accessing matrix elements
	const double* operator[](size_t index) const;

	// Accessors - m_rows and m_cols should never be changed directly as dereferencing is done
	// without range checking.
	size_t getRows() const;
	size_t getCols() const;

	// Resize the matrix
	void resize(size_t rows, size_t cols);

	// Free memory allocated for the matrix
	void freeMemory();

	// Allocate memory for the matrix
	void allocateMemory(size_t rows, size_t cols);

	// Reallocate memory for the matrix
	void reallocateMemory(size_t rows, size_t cols);

	// Set the matrix as an identity matrix
	void setIdentity();

	// Set the matrix elements to 1
	void setOne();

	// Set the matrix elements to 0
	void setZero();

	// Set the matrix elements from a file
	void setMatFromFile(const std::string &filename);

private:
	size_t m_rows = 0;
	size_t m_cols = 0;
	double **m_data = nullptr;
};

// Overloading the stream insertion operator for Matrix objects
std::ostream& operator<<(std::ostream &os, const Matrix &matrix);

}    // namespace ArshiaMath