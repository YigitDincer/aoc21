#include "solution.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>


namespace Day04 {

  auto parse(std::istream &stream) -> std::vector<std::string> {
    std::vector<std::string> v;
    std::ranges::copy(std::ranges::istream_view<std::string>(stream), std::back_inserter(v));
    return v;
  }



}// namespace Day04

namespace AoC {

  Solution<4>::Solution(std::istream &stream)
      : report{Day04::parse(stream)} {}

  auto Solution<4>::part1() const -> int {
    using namespace Day04;
    return 42;
  }

  auto Solution<4>::part2() const -> int {
    using namespace Day04;
    return 42;
  }

}// namespace AoC
