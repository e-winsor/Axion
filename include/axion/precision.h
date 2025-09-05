#pragma once

#include <cmath>

namespace axion
{
  using real = float;

  inline real real_sqrt(real value)
  {
    return std::sqrtf(value);
  }

}
