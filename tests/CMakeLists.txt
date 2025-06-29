add_executable(test_black_scholes test_black_scholes.cxx)
target_link_libraries(test_black_scholes black_scholes_pricer)
target_include_directories(test_black_scholes PRIVATE "../include")
add_test(NAME BlackScholesTest COMMAND test_black_scholes)

