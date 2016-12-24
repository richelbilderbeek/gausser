#include "gausser_impl_1.h"

#include <cassert>
#include <stdexcept>

#include "gausser.h"

ribi::gausser_impl_1::gausser_impl_1(const double sd)
  : m_sd{sd}, m_lut{create_lut(sd, 8000)}
{
  if (m_sd <= 0.0)
  {
    throw std::invalid_argument("sd must be bigger than zero");
  }
}

std::vector<double> ribi::gausser_impl_1::create_lut(const double sd, const int sz)
{
  std::vector<double> v;
  v.reserve(sz + 1);
  const double dx{8.0 / static_cast<double>(sz)};
  for (double x = -4.0; x < 4.0; x += dx)
  {
    v.push_back(gauss(x, sd));
  }
  return v;
}

double ribi::gausser_impl_1::operator()(const double x) const noexcept
{
  //Fraction of range
  const double f{(x + 4.0) / 8.0};
  const int i{
    static_cast<int>(
      f * static_cast<double>(m_lut.size())
    )
  };
  if (i < 0) return m_lut[0];
  if (i > static_cast<int>(m_lut.size())) return m_lut.back();
  return m_lut[i];
}
