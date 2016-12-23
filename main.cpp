#include <chrono>
#include <iostream>
#include <string>
#include <random>
#include "gausser.h"

using namespace ribi;

void benchmark_gausser()
{
  const double sd{1.0};
  const double min_x{-4.0};
  const double max_x{4.0};
  const double dx{8.0 / 100000000.0};
  double sum_gauss{0.0};
  double sum_gausser{0.0};
  int n_millis_gauss{0};
  int n_millis_gausser{0};

  using my_clock = std::chrono::high_resolution_clock;
  using msec = std::chrono::milliseconds;

  //gauss
  {
    const auto start_time = my_clock::now();
    {
      for (double x{min_x}; x<max_x; x+=dx)
      {
        sum_gauss += gauss(x, sd);
      }
    }
    const auto end_time = my_clock::now();
    const auto diff = end_time - start_time;
    n_millis_gauss = std::chrono::duration_cast<msec>(diff).count();
  }
  //gausser
  {
    const auto start_time = my_clock::now();
    {
      const gausser g(sd);
      for (double x{min_x}; x<max_x; x+=dx)
      {
        sum_gausser += g(x);
      }
    }
    const auto end_time = my_clock::now();
    const auto diff = end_time - start_time;
    n_millis_gausser = std::chrono::duration_cast<msec>(diff).count();
  }
  std::clog << "sum_gauss: " << sum_gauss << '\n';
  std::clog << "sum_gausser: " << sum_gausser << '\n';
  std::clog << "n_millis_gauss: " << n_millis_gauss << '\n';
  std::clog << "n_millis_gausser: " << n_millis_gausser << '\n';
}

int main()
{
  benchmark_gausser();
}
