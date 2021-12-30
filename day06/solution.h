#pragma once

#include "../solution.h"

#include <span>
#include <vector>

namespace Day06 {
  auto fish_count_after_n_days(std::vector<size_t> const&, size_t days) -> size_t;
  auto put_fishes_into_boxes(std::vector<size_t> const& fishes) -> std::vector<size_t>;
  auto calculate_fish_timer_for_the_next_day(std::vector<size_t> fish_boxes) -> std::vector<size_t>;
  auto extract_initial_fish_counts(std::vector<std::string> fish_string) -> std::vector<size_t>;
}

namespace AoC {

  template <>
  struct Solution<6> {
    explicit Solution(std::istream &);
    auto part1() const -> int;
    auto part2() const -> size_t;

  private:
    std::vector<std::string> report;
  };

}// namespace AoC
