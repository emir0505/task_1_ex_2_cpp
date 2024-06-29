#include <iostream>
#include "spiral_matrix.h"

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;

    std::cout << "Enter the size of the matrix (n): ";
    std::cin >> n;

    // Создание динамической квадратной матрицы размером n x n
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    // Заполнение матрицы по спирали против часовой стрелки
    if (fillSpiralMatrix(matrix, n)) {
        std::cout << "Spiral matrix:" << std::endl;
        printMatrix(matrix, n);
    } else {
        std::cerr << "Error: Invalid input" << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
