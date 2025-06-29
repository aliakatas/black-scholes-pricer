#pragma once

namespace black_scholes 
{

   enum class OptionType 
   { 
      Call, 
      Put 
   };

   struct Option 
   {
      double strike;
      double maturity;
      OptionType type;
   };

}  // namespace black_scholes
