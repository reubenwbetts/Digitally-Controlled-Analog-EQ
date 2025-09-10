#include "one_pole_iir.h"
#include <cstdint>
#include <cmath>

 uint8_t one_pole_iir::filter_method(uint8_t x, uint16_t damp_factor)
{
    // add 128 to fix DC sag (roudning errors from bit-shifting)
    uint16_t y = ((256-damp_factor) * x + damp_factor * y_prev + 128) >> 8;
    y_prev = static_cast<uint8_t>(y);
    return y_prev;
}
