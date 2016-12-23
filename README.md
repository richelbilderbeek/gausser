# gausser

Branch|[![Travis CI logo](TravisCI.png)](https://travis-ci.org)|[![Codecov logo](Codecov.png)](https://www.codecov.io)
---|---|---
master|[![Build Status](https://travis-ci.org/richelbilderbeek/gausser.svg?branch=master)](https://travis-ci.org/richelbilderbeek/gausser)|[![codecov.io](https://codecov.io/github/richelbilderbeek/gausser/coverage.svg?branch=master)](https://codecov.io/github/richelbilderbeek/gausser/branch/master)
develop|[![Build Status](https://travis-ci.org/richelbilderbeek/gausser.svg?branch=develop)](https://travis-ci.org/richelbilderbeek/gausser)|[![codecov.io](https://codecov.io/github/richelbilderbeek/gausser/coverage.svg?branch=develop)](https://codecov.io/github/richelbilderbeek/gausser/branch/develop)

`gausser` is a C++ class for calculating the Gaussian faster.

## Problem

You want to calculate the Gaussian often. You could do so with this function:

```
double gauss(const double x, const double sd) noexcept
{
  return std::exp(-(x*x) / (2.0 * sd * sd));
}
```

In your code, the value of `sd` is constant, so you could precalculate these values. `gausser` is exactly such a class.

## Example

```
int main()
{
  //The standard deviation of the Gauss curve
  const double sd{1.0};

  //Create the lookup table
  const gausser g(sd); 

  //The value we want to get the Gaussian of
  const double x{2.0};

  //We get the Gaussian of x
  const double y{gauss(x, sd)};

  //The Gaussian of x is close to the expected value
  assert(std::abs(y - 0.135335283237) < 0.0001);
}
```

## Contributing, code guidelines

See [CONTRIBUTING](CONTRIBUTING.md).
