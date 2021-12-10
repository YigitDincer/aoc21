#pragma once

#include "../solution.h"

#include <span>
#include <vector>

namespace Day07 {
  auto part1_solution(std::vector<int> const& crabs) -> int;
  auto part2_solution(std::vector<int> const& crabs) -> int;
}

namespace AoC {

  template <>
  struct Solution<7> {
    explicit Solution(std::istream &);
    auto part1() const -> int;
    auto part2() const -> int;

  private:
    std::vector<int> report;
  };

}// namespace AoC
