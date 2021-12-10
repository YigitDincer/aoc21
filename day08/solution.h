#pragma once

#include "../solution.h"

#include <span>
#include <vector>

namespace Day08 {
  auto get_four_digits(std::string const& input) -> std::vector<std::string>;
  auto is_unique(std::string const& str) -> bool;
  auto count_unique_digits(std::vector<std::string> const& str) -> int;
}

namespace AoC {

  template <>
  struct Solution<8> {
    explicit Solution(std::istream &);
    auto part1() const -> int;
    auto part2() const -> int;

  private:
    std::vector<std::string> report;
  };

}// namespace AoC
