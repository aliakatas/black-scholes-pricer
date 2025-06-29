#include "black_scholes/black_scholes.hpp"
#include <cassert>
#include <cmath>

int main() 
{

   black_scholes::Option opt{100.0, 1.0, black_scholes::OptionType::Call};
   double price = black_scholes::price_option(100.0, opt, 0.05, 0.2);

   assert(std::abs(price - 10.45) < 0.1);  // Approx known value

   return EXIT_SUCCESS;
}
