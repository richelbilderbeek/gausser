#include "gausser_impl_2.h"

#include "gausser.h"

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include <boost/test/unit_test.hpp>

using namespace ribi;

BOOST_AUTO_TEST_CASE(ribi_gausser_impl_2)
{
  const double sd{1.0};
  const gausser_impl_2 g(sd);
  //Must be in range of gausser, which is [-4.0,4.0]
  for (double x = -3.9; x < 3.9; x+=0.001)
  {
    const double expected{gauss(x, sd)};
    const double measured{g(x)};
    BOOST_CHECK_CLOSE(measured, expected, 0.000001);
  }
}

#pragma GCC diagnostic pop