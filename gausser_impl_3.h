#ifndef GAUSSER_IMPL_3_H
#define GAUSSER_IMPL_3_H

#include <array>

namespace ribi {

///Quick calculation of Guass
class gausser_impl_3
{
public:
  ///@param sd standard deviation of the gaussian
  gausser_impl_3(const double sd);

  ///Fast function
  double operator()(const double x) const noexcept;

private:
  const double m_sd;

  ///Lookup table
  const std::array<double, 6000> m_lut;

  ///Create the LUT
  std::array<double, 6000> create_lut(const double sd);


};

} //~namespace ribi

#endif // GAUSSER_IMPL_3_H
