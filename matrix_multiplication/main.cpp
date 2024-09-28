#include <iostream>
#include <numeric>
#include <vector>
#include "task_timer.hpp"
#include "matrix_multiplication.hpp"

std::vector<std::vector<int>> generateMatrix(int rows, int cols, int startValue = 1)
{
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i)
    {
        std::iota(matrix[i].begin(), matrix[i].end(), startValue);
        startValue += cols;
    }
    return matrix;
}

int main()
{
    try
    {
        std::vector<std::tuple<int, int, int>> matrixSizes = {
            {3, 4, 10},
            {10, 10, 10},
            {100, 100, 100},
            {200, 300, 500},
            {400, 400, 400},
            {1000, 1000, 100}};

        for (const auto &[rowsMatA, colsMatA, colsMatB] : matrixSizes)
        {
            std::cout << "\nComparing for Matrix A: " << rowsMatA << "x" << colsMatA
                      << " and Matrix B: " << colsMatA << "x" << colsMatB << std::endl;

            std::vector<std::vector<int>> matrixA = generateMatrix(rowsMatA, colsMatA, 1);
            std::vector<std::vector<int>> matrixB = generateMatrix(colsMatA, colsMatB, 1);

            auto [resultM, timeTakenforMultiThreaded] = getTime(multiThreadedMultiplication, matrixA, matrixB);

            auto [resultS, timeTakenforSingleThreaded] = getTime(singleThreadedMultiplication, matrixA, matrixB);

            std::cout << "Time taken - Single threaded: " << timeTakenforSingleThreaded
                      << " ms vs Multi threaded: " << timeTakenforMultiThreaded
                      << " ms" << std::endl;
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
