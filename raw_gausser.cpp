#include "raw_gausser.h"

#include <cassert>
#include <stdexcept>

#include "gausser.h"

ribi::raw_gausser::raw_gausser(const double sd) : m_sd{sd}
{
  if (m_sd <= 0.0)
  {
    throw std::invalid_argument("sd must be bigger than zero");
  }
}

double ribi::raw_gausser::operator()(const double x) const noexcept
{
  return gauss(x, m_sd);
}
