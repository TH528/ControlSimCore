//  main.cpp
//  Created by TH on 2020/11/29.
//  Copyright © 2020 TH. All rights reserved.

#include <cmath>
#include <iostream>

#include "solver/control_system_solver.hpp"
#include "csv/csv_writer.hpp"

int main() {
  constexpr solver::TimeConfig<double> TimeConfig {
    0.0, // start_time
    10.0, // end_time
    1E-3 // delta_t
  };

  static constexpr std::size_t N = 1; // state dimmension
  static constexpr std::size_t M = 1; // input dimmension + saving data dimmesion

  // Controller
  auto k = [&](const double t, const std::array<double, N>& x) {
    std::array<double, M> u {
      -x[0]
    };

    return u;
  };

  // Control system
  auto f = [&](const double t, const std::array<double, N>& x, const std::array<double, M>& u) {
    // Right hand side of control system
    std::array<double, N> dx {
      u[0]
    };

    return dx;
  };

  constexpr std::array<double, N> X0 { 1 }; // Initial state

  solver::ControlSystemSolver<double, solver::Solver::EULER, 1000, N> control_system_solver(TimeConfig, X0);
  auto [t_data, x_data, u_data] = control_system_solver.Solve<M>(f, k);

  csv::CSVWriter<double> t_csv_data("t_data.csv");
  csv::CSVWriter<double> x_csv_data("x_data.csv");
  csv::CSVWriter<double> u_csv_data("u_data.csv");

  t_csv_data.Open();
  x_csv_data.Open();
  u_csv_data.Open();

  t_csv_data.Write(t_data);
  x_csv_data.Write(x_data);
  u_csv_data.Write(u_data);

  return 0;
}