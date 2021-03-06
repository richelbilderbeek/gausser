#include "raw_gausser.h"

#include "gausser.h"

// Boost.Test does not play well with -Weffc++


#include <boost/test/unit_test.hpp>

using namespace ribi;

BOOST_AUTO_TEST_CASE(ribi_raw_gausser)
{
  const double sd{1.0};
  const raw_gausser g(sd);
  // Must be in range of gausser, which is [-4.0,4.0]
  for (double x = -3.9; x < 3.9; x += 0.001)
  {
    const double expected{gauss(x, sd)};
    const double measured{g(x)};
    BOOST_CHECK_EQUAL(measured, expected); // Will be perfectly equal
  }
  // Extremes should also work
  BOOST_CHECK_NO_THROW(g(-5.0));
  BOOST_CHECK_NO_THROW(g(5.0));
}


