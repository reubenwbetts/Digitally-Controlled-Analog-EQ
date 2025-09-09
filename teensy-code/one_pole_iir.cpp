#include "one_pole_iir.h"
#include <cstdint>
#include <cmath>

 uint8_t one_pole_iir::filter_method(uint8_t x, float damp_factor)
{
  float y = (1.0f - damp_factor) * x + damp_factor * y_prev;
  y_prev = y;
  uint8_t output = static_cast<uint8_t>(y);
  return output;
}
