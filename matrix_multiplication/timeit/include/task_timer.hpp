#ifndef TASK_TIMER_HPP
#define TASK_TIMER_HPP

#include <iostream>
#include <chrono>
#include <utility>
#include <functional>

// Handle export/import for cross-platform shared librariesis

#if defined(_WIN32) || defined(_WIN64)
    #ifdef TIMER_FUNCTIONS_EXPORTS
        #define TIMER_API __declspec(dllexport)
    #else
        #define TIMER_API __declspec(dllimport)
    #endif
#elif defined(__linux__) || defined(__APPLE__)
    #ifdef TIMER_FUNCTIONS_EXPORTS
        #define TIMER_API __attribute__((visibility("default")))
    #else
        #define TIMER_API
    #endif
#else
    #define TIMER_API
#endif

template <class F, class... Args>
TIMER_API auto getTime(F &&f, Args &&...args) -> std::pair<decltype(f(args...)), double>
{
    auto start = std::chrono::high_resolution_clock::now();

    auto result = std::invoke(std::forward<F>(f), std::forward<Args>(args)...);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    return std::make_pair(result, duration.count());
}

#endif // TASK_TIMER_HPP
