#include "black_scholes/black_scholes.hpp"
#include <cassert>
#include <cmath>

int main() 
{

   black_scholes::Option call{100.0, 1.0, black_scholes::OptionType::Call};
   black_scholes::Option put{100.0, 1.0, black_scholes::OptionType::Put};

   double call_price = black_scholes::price_option(100.0, call, 0.05, 0.2);
   double put_price = black_scholes::price_option(100.0, put, 0.05, 0.2);

   assert(std::abs(call_price - 10.45) < 0.1);
   assert(std::abs(put_price - 5.57) < 0.1);

   return EXIT_SUCCESS;
}
