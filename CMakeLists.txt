cmake_minimum_required(VERSION 3.10)
project(black_scholes_pricer)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME}
    src/black_scholes.cxx
    src/option.cxx
)

target_include_directories(${PROJECT_NAME} PRIVATE "include")

add_executable(example examples/pricing_example.cxx)
target_link_libraries(example ${PROJECT_NAME})
target_include_directories(example PRIVATE "include")

enable_testing()
add_subdirectory(tests)
