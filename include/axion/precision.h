#pragma once

#include <cmath>

namespace Axion
{
  using real = float;

  inline real real_sqrt(real value)
  {
    return std::sqrtf(value);
  }

}
