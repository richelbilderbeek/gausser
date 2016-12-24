#include "gausser_impl_3.h"

#ifdef FIX_WHY_IS_THIS_IMPLEMENTATION_SO_INPRECISE

#include <cassert>
#include <cmath>
#include "gausser.h"

ribi::gausser_impl_3::gausser_impl_3(const double sd)
  : m_sd{sd}, m_lut{create_lut(sd)}
{
  assert(sd >= 0.0);
}

std::array<double, 16384> ribi::gausser_impl_3::create_lut(const double sd)
{
  std::array<double, 16384> v;
  const double dx{4.0 / 16384.0};
  for (int i=0; i!=16384; ++i)
  {
    const double x{static_cast<double>(i) * dx};
    assert(i >= 0);
    assert(i < static_cast<int>(v.size()));
    v[i] = gauss(x, sd);
  }
  return v;
}

double ribi::gausser_impl_3::operator()(const double x) const noexcept
{
  //Fraction of range
  const double f{std::abs(x) / 4.0};
  const int i{
    static_cast<int>(
      f * 16384.0
    )
  };
  if (i < 0) return 1.0;
  if (i >= 16384) return 0.0;
  assert(i >= 0);
  assert(i < static_cast<int>(m_lut.size()));
  return m_lut[i];
}

#endif //FIX_WHY_IS_THIS_IMPLEMENTATION_SO_INPRECISE
