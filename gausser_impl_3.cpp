#include "gausser_impl_3.h"

#include <cassert>
#include <cmath>

#include "gausser.h"

ribi::gausser_impl_3::gausser_impl_3(const double sd)
  : m_sd{sd}, m_lut{create_lut(sd)}
{
  assert(sd >= 0.0);
}

std::array<double, 10000> ribi::gausser_impl_3::create_lut(const double sd)
{
  std::array<double, 10000> v;
  const double dx{4.0 / 10000.0};
  for (int i=0; i!=10000; ++i)
  {
    const double x{static_cast<double>(i) * dx};
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
      f * 10000.0
    )
  };
  if (i < 0) return 1.0;
  if (i >= 10000) return 0.0;
  return m_lut[i];
}
