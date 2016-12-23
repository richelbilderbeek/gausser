#ifndef RIBI_GAUSSER_H
#define RIBI_GAUSSER_H

#include <vector>

namespace ribi {

///Quick calculation of Guass
class gausser
{
public:
  ///@param sd standard deviation of the gaussian
  gausser(const double sd);

  ///Fast function
  double operator()(const double x) const noexcept;

  ///Calls gauss function
  double get_precise(const double x) const noexcept;

  ///Uses gausser
  double get_fast(const double x) const noexcept;

private:
  const double m_sd;

  ///Lookup table
  const std::vector<double> m_lut;

  ///Create the LUT
  std::vector<double> create_lut(const double sd, const int sz);
};

///The Gaussian function, with a density of 1.0 at an x of 0.0
double gauss(const double x, const double sd) noexcept;


} //~namespace ribi


#endif // RIBI_GAUSSER_H
