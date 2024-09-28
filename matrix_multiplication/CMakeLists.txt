cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(MatrixMultiplication)

include_directories(matrix_operations/include)

add_subdirectory(timeit)

# Add the source files and create the executable
add_executable(matrixMultiplication
    matrix_operations/src/matrix_multiplication.cpp
    main.cpp
)

target_link_libraries(matrixMultiplication time_it)