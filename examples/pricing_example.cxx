#include "black_scholes/black_scholes.hpp"

#include <iostream>

int main() 
{
   // Define the market and option parameters
   double spot_price = 100.0;     // S₀
   double strike_price = 100.0;   // K
   double maturity = 1.0;         // T (in years)
   double interest_rate = 0.05;   // r (risk-free rate)
   double volatility = 0.2;       // σ

   // Given the parameters, the expected output is:
   // > Call Option Price: 10.4506
   // > Put Option Price: 5.5735


   // Price a European Call
   black_scholes::Option call_option{strike_price, maturity, black_scholes::OptionType::Call};
   double call_price = price_option(spot_price, call_option, interest_rate, volatility);
   std::cout << "Call Option Price: " << call_price << std::endl;

   // Price a European Put
   black_scholes::Option put_option{strike_price, maturity, black_scholes::OptionType::Put};
   double put_price = price_option(spot_price, put_option, interest_rate, volatility);
   std::cout << "Put Option Price: " << put_price << std::endl;

   return EXIT_SUCCESS;
}
