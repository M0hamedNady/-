#include <iostream>

#include <vector>

class Matrix {

private:

    std::vector<std::vector<double>> elements;

    int rows, columns;

public:

    Matrix(int rows, int columns) : rows(rows), columns(columns) {

        elements.resize(rows, std::vector<double>(columns, 0.0));

    }

    void fill() {

        std::cout << "Enter the matrix elements:" << std::endl;

        for (int i = 0; i < rows; ++i) {

            for (int j = 0; j < columns; ++j) {

                std::cin >> elements[i][j];

            }

        }

    }

    Matrix operator+(const Matrix& other) const {

        if (rows != other.rows || columns != other.columns) {

            throw std::invalid_argument("Matrices must have the same dimensions to add them.");

        }

        Matrix result(rows, columns);

        for (int i = 0; i < rows; ++i) {

            for (int j = 0; j < columns; ++j) {

                result.elements[i][j] = elements[i][j] + other.elements[i][j];

            }

        }

        return result;

    }

    Matrix operator-(const Matrix& other) const {

        if (rows != other.rows || columns != other.columns) {

            throw std::invalid_argument("Matrices must have the same dimensions to subtract them.");

        }

        Matrix result(rows, columns);

        for (int i = 0; i < rows; ++i) {

            for (int j = 0; j < columns; ++j) {

                result.elements[i][j] = elements[i][j] - other.elements[i][j];

            }

        }

        return result;

    }

    Matrix operator*(const Matrix& other) const {

        if (columns != other.rows) {

            throw std::invalid_argument("The number of columns in the first matrix must match the number of rows in the second matrix to multiply them.");

        }

        Matrix result(rows, other.columns);

        for (int i = 0; i < rows; ++i) {

            for (int j = 0; j < other.columns; ++j) {

                for (int k = 0; k < columns; ++k) {

                    result.elements[i][j] += elements[i][k] * other.elements[k][j];

                }

            }

        }

        return result;

    }

    Matrix operator/(const double scalar) const {

        if (scalar == 0) {

            throw std::invalid_argument("Cannot divide matrix by zero.");

        }

        Matrix result(rows, columns);

        for (int i = 0; i < rows; ++i) {

            for (int j = 0; j < columns; ++j) {

                result.elements[i][j] = elements[i][j] / scalar;

            }

        }

        return result;

    }

    void print() const {

        for (int i = 0; i < rows; ++i) {

            for (int j = 0; j < columns; ++j) {

                std::cout << elements[i][j] << " ";

            }

            std::cout << std::endl;

        }

    }

};

int main() {

    int rows, columns;

    std::cout << "Enter the number of rows and columns for the first matrix:" << std::endl;

    std::cin >> rows >> columns;

    Matrix matrix1(rows, columns);

    matrix1.fill();

    std::cout << "Enter the number of rows and columns for the second matrix:" << std::endl;

    std::cin >> rows >> columns;

    Matrix matrix2(rows, columns);

    matrix2.fill();

    Matrix matrixSum = matrix1 + matrix2;

    std::cout << "The sum of the two matrices is:" << std::endl;

    matrixSum.print();

    Matrix matrixDifference = matrix1 - matrix2;

    std::cout << "The difference between the two matrices is:" << std::endl;

    matrixDifference.print();

    Matrix matrixProduct = matrix1 * matrix2;

    std::cout << "The product of the two matrices is:" << std::endl;

    matrixProduct.print();

    double scalar;

    std::cout << "Enter a scalar value to divide the first matrix with:" << std::endl;

    std::cin >> scalar;

    Matrix matrixQuotient = matrix1 / scalar;

    std::cout << "The quotient of the first matrix and the scalar value is:" << std::endl;

    matrixQuotient.print();

    return 0;

}
