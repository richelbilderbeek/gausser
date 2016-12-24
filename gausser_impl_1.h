#ifndef GAUSSER_IMPL_1_H
#define GAUSSER_IMPL_1_H

#include <vector>

namespace ribi {

///Quick calculation of Guass
class gausser_impl_1
{
public:
  ///@param sd standard deviation of the gaussian
  gausser_impl_1(const double sd);

  ///Block expensive copies
  //gausser_impl_1(const gausser_impl_1&) = delete;
  //gausser_impl_1& operator=(const gausser_impl_1&) = delete;

  ///Get the standard deviation of the gaussian
  double sd() const noexcept { return m_sd; }

  ///Get the density at the gaussion at x. Will be 1.0 for x equals 0.0
  double operator()(const double x) const noexcept;

private:
  const double m_sd;

  ///Lookup table
  const std::vector<double> m_lut;

  ///Create the LUT
  std::vector<double> create_lut(const double sd, const int sz);
};

} //~namespace ribi


#endif // GAUSSER_IMPL_1_H
