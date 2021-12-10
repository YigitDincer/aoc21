#pragma once

#include "../solution.h"

#include <span>
#include <vector>

namespace Day04 {

}

namespace AoC {

  template <>
  struct Solution<4> {
    explicit Solution(std::istream &);
    auto part1() const -> int;
    auto part2() const -> int;

  private:
    std::vector<std::string> report;
  };

}// namespace AoC
