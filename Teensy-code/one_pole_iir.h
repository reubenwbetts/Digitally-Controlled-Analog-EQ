#include <cstdint>

class one_pole_iir
{
  public:

  uint8_t filter_method (uint8_t x, uint16_t damp_factor);

  private:

  uint16_t y_prev;
};

