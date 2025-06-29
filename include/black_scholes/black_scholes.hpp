#pragma once
#include "option.hpp"

namespace black_scholes 
{

   double price_option(
      double spot,
      const Option& opt,
      double rate,
      double volatility
   ) noexcept(false);

}  // namespace black_scholes
