#include <cstdint>

class one_pole_iir
{
  public:

  uint8_t filter_method (uint8_t x, float damp_factor);

  private:

  float y_prev;
};
