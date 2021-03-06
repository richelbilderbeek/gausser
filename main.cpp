#include "gausser.h"
#include "gausser_impl_1.h"
#include "gausser_impl_2.h"
#include "gausser_impl_3.h"
#include <chrono>
#include <iostream>
#include <random>
#include <string>

using namespace ribi;
using my_clock = std::chrono::high_resolution_clock;
using msec = std::chrono::milliseconds;

struct benchmark_parameters
{
  const double sd{1.0};
  const double min_x{-4.0};
  const double max_x{4.0};
  const double dx{8.0 / 1000000000.0};
};

double measure_gauss(const benchmark_parameters &p)
{
  const double sd{p.sd};
  const double min_x{p.min_x};
  const double max_x{p.max_x};
  const double dx{p.dx};

  double sum{0.0};
  const auto start_time = my_clock::now();
  {
    for (double x{min_x}; x < max_x; x += dx)
    {
      sum += gauss(x, sd);
    }
  }
  const auto end_time = my_clock::now();
  const auto diff = end_time - start_time;
  const double n_millis = std::chrono::duration_cast<msec>(diff).count();
  std::clog << "sum gauss: " << sum << '\n';
  return n_millis;
}

double measure_gausser(const benchmark_parameters &p)
{
  const double sd{p.sd};
  const double min_x{p.min_x};
  const double max_x{p.max_x};
  const double dx{p.dx};

  double sum{0.0};
  const auto start_time = my_clock::now();
  {
    const gausser g(sd);
    for (double x{min_x}; x < max_x; x += dx)
    {
      sum += g(x);
    }
  }
  const auto end_time = my_clock::now();
  const auto diff = end_time - start_time;
  const double n_millis = std::chrono::duration_cast<msec>(diff).count();
  std::clog << "sum gausser: " << sum << '\n';
  return n_millis;
}

double measure_gausser_impl_1(const benchmark_parameters &p)
{
  const double sd{p.sd};
  const double min_x{p.min_x};
  const double max_x{p.max_x};
  const double dx{p.dx};

  double sum{0.0};
  const auto start_time = my_clock::now();
  {
    const gausser_impl_1 g(sd);
    for (double x{min_x}; x < max_x; x += dx)
    {
      sum += g(x);
    }
  }
  const auto end_time = my_clock::now();
  const auto diff = end_time - start_time;
  const double n_millis = std::chrono::duration_cast<msec>(diff).count();
  std::clog << "sum gausser_impl_1: " << sum << '\n';
  return n_millis;
}

double measure_gausser_impl_2(const benchmark_parameters &p)
{
  const double sd{p.sd};
  const double min_x{p.min_x};
  const double max_x{p.max_x};
  const double dx{p.dx};

  double sum{0.0};
  const auto start_time = my_clock::now();
  {
    const gausser_impl_2 g(sd);
    for (double x{min_x}; x < max_x; x += dx)
    {
      sum += g(x);
    }
  }
  const auto end_time = my_clock::now();
  const auto diff = end_time - start_time;
  const double n_millis = std::chrono::duration_cast<msec>(diff).count();
  std::clog << "sum gausser_impl_2: " << sum << '\n';
  return n_millis;
}

double measure_gausser_impl_3(const benchmark_parameters &p)
{
  const double sd{p.sd};
  const double min_x{p.min_x};
  const double max_x{p.max_x};
  const double dx{p.dx};

  double sum{0.0};
  const auto start_time = my_clock::now();
  {
    const gausser_impl_3 g(sd);
    for (double x{min_x}; x < max_x; x += dx)
    {
      sum += g(x);
    }
  }
  const auto end_time = my_clock::now();
  const auto diff = end_time - start_time;
  const double n_millis = std::chrono::duration_cast<msec>(diff).count();
  std::clog << "sum gausser_impl_3: " << sum << '\n';
  return n_millis;
}

void benchmark_gausser()
{
  const benchmark_parameters p;
  std::clog << "n_millis_gauss: " << measure_gauss(p) << '\n';
  std::clog << "n_millis_gausser: " << measure_gausser(p) << '\n';
  std::clog << "n_millis_gausser_impl_1: " << measure_gausser_impl_1(p) << '\n';
  std::clog << "n_millis_gausser_impl_2: " << measure_gausser_impl_2(p) << '\n';
  std::clog << "n_millis_gausser_impl_3: " << measure_gausser_impl_3(p) << '\n';
}

void show_gaussers()
{
  const double sd{1.0};
  gausser_impl_1 g1(sd);
  gausser_impl_2 g2(sd);
  gausser_impl_3 g3(sd);
  for (double x{0.0}; x < 4.0; x += 0.01)
  {
    const double y0{gauss(x, sd)};
    const double y1{g1(x)};
    const double y2{g2(x)};
    const double y3{g3(x)};
    std::cout << x << '\t' << y0 << '\t' << y1 << '\t' << y2 << '\t' << y3
              << '\n';
  }
  std::cout << std::endl;
}

int main()
{
  show_gaussers();
  benchmark_gausser();
}
