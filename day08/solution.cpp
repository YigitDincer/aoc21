#include "solution.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include <sstream>


namespace Day08 {

  auto parse(std::istream &stream) -> std::vector<std::string> {
    std::vector<std::string> v;
    std::string item;
    while (getline (stream, item, '\n')) {
      v.push_back (item);
    }
    return v;
  }

  auto get_four_digits(std::string const& input) -> std::vector<std::string>
  {
    std::vector<std::string> result;
    std::stringstream ss (input);
    std::string item;

    while (getline (ss, item, ' ')) {
      result.push_back (item);
    }

   std::vector<std::string> digits;
   std::copy(result.end()-4, result.end(), std::back_inserter(digits));
    return digits;
  }

  auto is_unique(std::string const& input) -> bool
  {
    return input.size() == 2 || input.size() == 4 || input.size() == 3 || input.size() == 7;
  }

  auto count_unique_digits(std::vector<std::string> const& str) -> int
  {
    return std::count_if(str.begin(), str.end(), is_unique);
  }

}// namespace Day08

namespace AoC {

  Solution<8>::Solution(std::istream &stream)
      : report{Day08::parse(stream)} {}

  auto Solution<8>::part1() const -> int {
    using namespace Day08;

    int unique_digits = 0;

    for ( auto const& line : report)
    {
      unique_digits += count_unique_digits(get_four_digits(line));
    }

    return unique_digits;

  }

  auto Solution<8>::part2() const -> int {
    using namespace Day08;
    return 42;
  }

}// namespace AoC
