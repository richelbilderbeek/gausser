#ifndef GAUSSER_IMPL_3_H
#define GAUSSER_IMPL_3_H

#include "gausser_impl_2.h"
#include <array>
namespace ribi
{

using gausser_impl_3 = gausser_impl_2;

#ifdef FIX_WHY_IS_THIS_IMPLEMENTATION_SO_INPRECISE

/// Quick calculation of Gauss
class gausser_impl_3
{
public:
  ///@param sd standard deviation of the gaussian
  explicit gausser_impl_3(const double sd);

  double operator()(const double x) const noexcept;

private:
  const double m_sd;

  /// Lookup table
  const std::array<double, 16384> m_lut;

  /// Create the LUT
  std::array<double, 16384> create_lut(const double sd);
};

#endif // FIX_WHY_IS_THIS_IMPLEMENTATION_SO_INPRECISE

} //~namespace ribi

#endif // GAUSSER_IMPL_3_H
