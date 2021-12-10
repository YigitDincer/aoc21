#pragma once

#include "../solution.h"

#include <optional>
#include <string>
#include <vector>

namespace Day10 {
  auto first_illegal_character(std::string const&) -> std::optional<char>;
  auto calculate_points_for_part1(std::vector<std::string> const &input) -> int;
  auto mathematical_sum_of_missing_characters(std::string const& line) -> long long int;
  auto calculate_points_for_part2(std::vector<std::string> const &input) -> long long int;
}

namespace AoC {

  template <>
  struct Solution<10> {
    explicit Solution(std::istream &);
    auto part1() const -> int;
    auto part2() const -> long long int;

  private:
    std::vector<std::string> report;
  };

}// namespace AoC
