#include <iostream>
#include "Matrix.hpp"

int main() {
    // Create a 3x3 matrix and set its values

    ArshiaMath::Matrix matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    // Print the matrix
    std::cout << "Original matrix:" << std::endl;
    std::cout << matrix;

    // Create another matrix for testing operations
    ArshiaMath::Matrix otherMatrix(3, 3);
    otherMatrix.setIdentity();

    // Add the two matrices
    ArshiaMath::Matrix sumMatrix = matrix + otherMatrix;
    std::cout << "Sum matrix:" << std::endl;
    std::cout << sumMatrix;

    // Subtract the two matrices
    ArshiaMath::Matrix diffMatrix = matrix - otherMatrix;
    std::cout << "Difference matrix:" << std::endl;
    std::cout << diffMatrix;

    // Multiply the two matrices
    ArshiaMath::Matrix multMatrix = matrix * otherMatrix;
    std::cout << "Multiplication matrix:" << std::endl;
    std::cout << multMatrix;

    // Multiply the matrix by a scalar
    double scalar = 2.0;
    ArshiaMath::Matrix scalarMultMatrix = matrix * scalar;
    std::cout << "Scalar multiplication matrix:" << std::endl;
    std::cout << scalarMultMatrix;

    // Check if two matrices are equal element-wise
    ArshiaMath::Matrix equalsMatrix = matrix.elementWiseEquals(otherMatrix);
    std::cout << "Element-wise equality matrix:" << std::endl;
    std::cout << equalsMatrix;

    // Check if two matrices are equal
    bool isEqual = matrix.equals(otherMatrix);
    std::cout << "Matrix equality: " << (isEqual ? "true" : "false") << std::endl;

    return 0;
}