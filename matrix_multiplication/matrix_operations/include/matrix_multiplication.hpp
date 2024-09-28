#ifndef MATRIX_MULTIPLCATION_HPP
#define MATRIX_MULTIPLCATION_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <thread>

std::vector<std::vector<int>> singleThreadedMultiplication(const std::vector<std::vector<int>> &matrixA,
                                                           const std::vector<std::vector<int>> &matrixB);

void multiplyRows(const std::vector<std::vector<int>> &matrixA, const std::vector<std::vector<int>> &matrixB,
                  std::vector<std::vector<int>> &result, int startRow, int endRow);

std::vector<std::vector<int>> multiThreadedMultiplication(const std::vector<std::vector<int>> &matrixA,
                                                          const std::vector<std::vector<int>> &matrixB);

#endif // MATRIX_MULTIPLCATION_HPP
