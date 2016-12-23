#ifndef GAUSSER_IMPL_2_H
#define GAUSSER_IMPL_2_H

#include <vector>

namespace ribi {

///Quick calculation of Guass
class gausser_impl_2
{
public:
  ///@param sd standard deviation of the gaussian
  gausser_impl_2(const double sd);

  ///Fast function
  double operator()(const double x) const noexcept;

private:
  const double m_sd;

  ///Lookup table
  const std::vector<double> m_lut;

  ///Create the LUT
  std::vector<double> create_lut(const double sd, const int sz);
};

} //~namespace ribi

#endif // GAUSSER_IMPL_2_H
