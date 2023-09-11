/*
 * Matrix.cpp
 *
 *  Created on: Mar 26, 2023
 *      Author: ArshiaSaffari
 */

#include "Matrix.hpp" // Include the corresponding header file.

namespace ArshiaMath {

void Matrix::allocateMemory(size_t rows, size_t cols) {
	if (m_data != nullptr)
		throw std::runtime_error("Already allocated. Use reallocate instead");
	m_data = new double*[rows];
	m_data[0] = new double[rows * cols];
	for (size_t i = 1; i < rows; i++) {
		m_data[i] = m_data[i - 1] + cols;
	}
	m_rows = rows;
	m_cols = cols;
}

void Matrix::reallocateMemory(size_t rows, size_t cols) {
	if (m_data != nullptr)
		freeMemory();
	m_data = new double*[rows];
	m_data[0] = new double[rows * cols];
	for (size_t i = 1; i < rows; i++) {
		m_data[i] = m_data[i - 1] + cols;
	}
	m_rows = rows;
	m_cols = cols;
}

void Matrix::freeMemory() {
	delete[] m_data[0];
	delete[] m_data;
	m_data = nullptr;
	m_rows = 0;
	m_cols = 0;
}

Matrix::Matrix() :
		m_rows(0), m_cols(0), m_data(nullptr) {
}

Matrix::~Matrix() {
	freeMemory();
}

Matrix::Matrix(const Matrix &other) :
		m_rows(other.m_rows), m_cols(other.m_cols), m_data(nullptr) {
	allocateMemory(m_rows, m_cols);
	// Copy the data from 'other' to the current instance.
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			m_data[i][j] = other.m_data[i][j];
		}
	}
}

Matrix::Matrix(size_t rows, size_t cols) :
		m_rows(rows), m_cols(cols), m_data(nullptr) {
	allocateMemory(m_rows, m_cols);
}

// Constructor with initializer list
Matrix::Matrix(std::initializer_list<std::initializer_list<double> > init){
	size_t rows = init.size();
	size_t cols = (rows > 0) ? init.begin()->size() : 0;

	reallocateMemory(rows, cols);

	for (size_t i = 0; i < rows; i++){
		const std::initializer_list<double> row = *std::next(init.begin(), i);
		if(row.size() != cols)
			throw std::runtime_error("Invalid matrix dimensions");
		for (size_t j = 0; j < cols; j++){
			m_data[i][j] = *std::next(row.begin(), j);
		}
	}
}

size_t Matrix::getRows() const {
	return m_rows;
}

size_t Matrix::getCols() const {
	return m_cols;
}

double*& Matrix::operator[](size_t index) {
	return m_data[index];
}

const double* Matrix::operator[](size_t index) const {
	return m_data[index];
}

Matrix& Matrix::operator=(const Matrix &other) {
	if (this == &other)
		return *this;
	// Ensure that the current matrix has the same size as 'other'.
	if (m_rows != other.m_rows || m_cols != other.m_cols) {
		reallocateMemory(other.m_rows, other.m_cols);
	}
	// Copy the data from 'other' to the current instance.
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			m_data[i][j] = other.m_data[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix &other) const {
	if (other.m_cols != m_cols || other.m_rows != m_rows)
		throw std::invalid_argument("Matrices must have same dimensions.");
	Matrix result(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			result.m_data[i][j] = m_data[i][j] + other.m_data[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
	if (other.m_cols != m_cols || other.m_rows != m_rows)
		throw std::invalid_argument("Matrices must have same dimensions.");
	Matrix result(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			result.m_data[i][j] = m_data[i][j] - other.m_data[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator*(const Matrix &other) const {
	if (m_cols != other.m_rows)
		throw std::invalid_argument(
				"Number of columns of the first matrix must equal the number of rows of the second matrix.");
	Matrix result(m_rows, other.m_cols);
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < other.m_cols; j++) {
			result[i][j] = 0;
				for (size_t k = 0; k < m_cols; k++) {
					result[i][j] += m_data[i][k] * other.m_data[k][j];
				}
			}
		}
	return result;
}

Matrix Matrix::operator*(double scalar) const {
	Matrix result(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			result.m_data[i][j] = m_data[i][j] * scalar;
		}
	}
	return result;
}

Matrix operator*(double scalar, const Matrix &matrix) {
	return matrix * scalar;
}

Matrix Matrix::elementWiseEquals(const Matrix &other) const {
	if (other.m_cols != m_cols || other.m_rows != m_rows)
		throw std::invalid_argument("Matrices must have same dimensions.");
	Matrix result(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			result.m_data[i][j] = (m_data[i][j] == other.m_data[i][j]) ? 1.0 : 0.0;
		}
	}
	return result;
}

bool Matrix::equals(const Matrix &other) const {
	if (other.m_cols != m_cols || other.m_rows != m_rows)
		return false;
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			if (m_data[i][j] != other.m_data[i][j])
				return false;
		}
	}
	return true;
}

void Matrix::resize(size_t rows, size_t cols) {
	reallocateMemory(rows, cols);
}

void Matrix::setIdentity() {
	if (m_rows != m_cols)
		throw std::invalid_argument("Matrix must be square.");
	setZero();
	for (size_t i = 0; i < m_rows; i++) {
		m_data[i][i] = 1.0;
	}
}

void Matrix::setOne() {
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			m_data[i][j] = 1.0;
		}
	}
}

void Matrix::setZero() {
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			m_data[i][j] = 0.0;
		}
	}
}

void Matrix::setMatFromFile(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("Failed to open file: " + filename);
	size_t rows, cols;
	file >> rows;
	file >> cols;
	if (rows != m_rows || cols != m_cols)
		throw std::invalid_argument("Matrix dimensions do not match file contents.");
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			file >> m_data[i][j];
		}
	}
	file.close();
}

std::ostream& operator<<(std::ostream &os, const Matrix &matrix) {
	auto rows = matrix.getRows();
	auto cols = matrix.getCols();
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			os << matrix[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
} 

}/* namespace ArshiaMath */