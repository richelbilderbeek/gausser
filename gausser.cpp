#include "gausser.h"

#include <cassert>
#include <cmath>


double ribi::gauss(const double x, const double sd) noexcept
{
  return std::exp(-(x*x) / (2.0 * sd * sd));
}
