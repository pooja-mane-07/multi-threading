#include <iostream>
#include "task_timer.hpp"

int sampleFunction(int a, int b)
{
    int sum = 0;
    for (int i = 0; i < 1000000; ++i)
    {
        sum += a + b;
    }
    return sum;
}

int main()
{
    auto [result, timeTaken] = getTime(sampleFunction, 10, 20);

    std::cout << "Result: " << result << std::endl;
    std::cout << "Time taken: " << timeTaken << " ms" << std::endl;

    return 0;
}
