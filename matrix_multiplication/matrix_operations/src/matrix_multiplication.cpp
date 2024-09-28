#include "matrix_multiplication.hpp"

std::vector<std::vector<int>> singleThreadedMultiplication(const std::vector<std::vector<int>> &matrixA,
                                                           const std::vector<std::vector<int>> &matrixB)
{
    if (matrixA.empty() || matrixB.empty())
    {
        throw std::invalid_argument("Input matrices must not be empty.");
    }

    if (matrixA[0].size() != matrixB.size())
    {
        throw std::invalid_argument("Number of columns in matrixA must equal number of rows in matrixB.");
    }

    int n = matrixA.size();
    int m = matrixA[0].size();
    int p = matrixB[0].size();

    std::vector<std::vector<int>> result(n, std::vector<int>(p));

    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < p; j++)
        {
            for (int k{0}; k < m; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}

void multiplyRows(const std::vector<std::vector<int>> &matrixA, const std::vector<std::vector<int>> &matrixB,
                  std::vector<std::vector<int>> &result, int startRow, int endRow)
{
    int m = matrixA[0].size();
    int p = matrixB[0].size();

    for (int i = startRow; i < endRow; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < m; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

std::vector<std::vector<int>> multiThreadedMultiplication(const std::vector<std::vector<int>> &matrixA,
                                                          const std::vector<std::vector<int>> &matrixB)
{
    if (matrixA.empty() || matrixB.empty())
    {
        throw std::invalid_argument("Input matrices must not be empty.");
    }

    if (matrixA[0].size() != matrixB.size())
    {
        throw std::invalid_argument("Number of columns in matrixA must equal number of rows in matrixB.");
    }

    int n = matrixA.size();
    int m = matrixA[0].size();
    int p = matrixB[0].size();

    std::vector<std::vector<int>> result(n, std::vector<int>(p));

    int numThreads = std::thread::hardware_concurrency();

    std::vector<std::thread> threads;

    int rowsPerThread = n / numThreads;

    for (int i = 0; i < numThreads; i++)
    {
        int startRow = i * rowsPerThread;
        int endRow = (i == numThreads - 1) ? n : startRow + rowsPerThread;
        threads.emplace_back(multiplyRows, std::ref(matrixA), std::ref(matrixB), std::ref(result), startRow, endRow);
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    return result;
}
