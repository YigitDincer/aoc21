#pragma once

#include "../solution.h"

#include <span>
#include <vector>

namespace Day02 {
}

namespace AoC {

  template <>
  struct Solution<2> {
    explicit Solution(std::istream &);
    auto part1() const -> int;
    auto part2() const -> int;

  private:
    std::string input;
  };

}// namespace AoC
