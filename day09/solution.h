#pragma once

#include "../solution.h"

#include <span>
#include <vector>

namespace Day9 {
  auto sum_of_risk_points(std::vector<std::string> const& cave) -> int;
  auto create_map (std::vector<std::string> const& cave) -> std::string;
}

namespace AoC {

  template <>
  struct Solution<9> {
    explicit Solution(std::istream &);
    auto part1() const -> int;
    auto part2() const -> int;

  private:
    std::vector<std::string> report;
  };

}// namespace AoC
