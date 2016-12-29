#ifndef GAUSSER_IMPL_1_H
#define GAUSSER_IMPL_1_H

#include <vector>

namespace ribi {

///Quick calculation of Guass
class gausser_impl_1
{
public:
  ///@param sd standard deviation of the gaussian
  explicit gausser_impl_1(const double sd);

  ///Block expensive copies
  //gausser_impl_1(const gausser_impl_1&) = delete;
  //gausser_impl_1& operator=(const gausser_impl_1&) = delete;

  ///Get the standard deviation of the gaussian
  double sd() const noexcept { return m_sd; }

  ///Get the density at the gaussion at x. Will be 1.0 for x equals 0.0
  inline double operator()(const double x) const noexcept
  {
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

private:
  const double m_sd;

  ///Lookup table
  const std::vector<double> m_lut;

  ///Create the LUT
  std::vector<double> create_lut(const double sd, const int sz);
};

} //~namespace ribi


#endif // GAUSSER_IMPL_1_H
