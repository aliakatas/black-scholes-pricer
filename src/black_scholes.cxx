#include "black_scholes/black_scholes.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>

double N(double x) 
{
   return 0.5 * std::erfc(-x / std::sqrt(2));
}

double black_scholes::price_option(
   double S, 
   const black_scholes::Option& opt, 
   double r, 
   double sigma
)  noexcept(false) 
{
   double K = opt.strike;
   double T = opt.maturity;

   double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
   double d2 = d1 - sigma * std::sqrt(T);

   if (opt.type == black_scholes::OptionType::Call)
      return S * N(d1) - K * std::exp(-r * T) * N(d2);
   else if (opt.type == black_scholes::OptionType::Put)
      return K * std::exp(-r * T) * N(-d2) - S * N(-d1);
   else
      throw std::invalid_argument("Invalid OptionType");
}
