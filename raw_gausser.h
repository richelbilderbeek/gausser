#ifndef RAW_GAUSSER_H
#define RAW_GAUSSER_H

#include <vector>

namespace ribi
{

/// Just calculate the gauss every operator()
class raw_gausser
{
public:
  ///@param sd standard deviation of the gaussian
  explicit raw_gausser(const double sd);

  /// Get the standard deviation of the gaussian
  double sd() const noexcept { return m_sd; }

  /// Get the density at the gaussion at x. Will be 1.0 for x equals 0.0
  double operator()(const double x) const noexcept;

private:
  const double m_sd;
};

} //~namespace ribi

#endif // RAW_GAUSSER_H
