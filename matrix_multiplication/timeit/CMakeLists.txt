cmake_minimum_required(VERSION 3.20)
project(time_it)

add_library(time_it SHARED src/main.cpp)

target_compile_definitions(time_it PRIVATE
TIMER_FUNCTIONS_EXPORTS)

target_include_directories(time_it PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS time_it
LIBRARY DESTINATION "${CMAKE_BINARY_DIR}"
RUNTIME DESTINATION "${CMAKE_BINARY_DIR}"
ARCHIVE DESTINATION "${CMAKE_BINARY_DIR}"
)
install(FILES include/task_timer.hpp DESTINATION
"${CMAKE_CURRENT_SOURCE_DIR}/include")