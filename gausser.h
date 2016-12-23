#ifndef RIBI_GAUSSER_H
#define RIBI_GAUSSER_H

#include <vector>
#include "gausser_impl_1.h"

namespace ribi {

using gausser = gausser_impl_1;

///The Gaussian function, with a density of 1.0 at an x of 0.0
double gauss(const double x, const double sd) noexcept;

} //~namespace ribi


#endif // RIBI_GAUSSER_H
