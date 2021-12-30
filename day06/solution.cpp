#include "solution.h"

#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>


namespace Day06 {

  auto parse(std::istream &stream) -> std::vector<std::string> {
    std::vector<std::string> v;
    std::ranges::copy(std::ranges::istream_view<std::string>(stream), std::back_inserter(v));
    return v;
  }

  auto extract_initial_fish_counts(std::vector<std::string> fish_string) -> std::vector<size_t>
  {
    using namespace std::string_view_literals;
    auto line = fish_string[0];
    auto range_after_split = line | std::views::split(","sv)
                             | std::views::transform(
                                     [](auto &&range_chars)
                                     {
                                       auto common_char_range = range_chars | std::views::common;
                                       auto i = std::stoi(std::string{common_char_range.begin(), common_char_range.end()});
                                       return i;
                                     });

    std::vector<size_t> result;
    std::ranges::copy(range_after_split, std::back_inserter(result));

    return result;
  }

  auto put_fishes_into_boxes(std::vector<size_t> const& fishes) -> std::vector<size_t>
  {
    // we expect elements of 0..8 => len = 9
    std::vector<size_t> fish_boxes(9, 0);
    for (auto const& fish : fishes)
    {
      fish_boxes[fish] += 1;
    }

    return fish_boxes;
  }

  auto calculate_fish_timer_for_the_next_day(std::vector<size_t> fish_boxes) -> std::vector<size_t>
  {
    auto ready_for_creation = fish_boxes[0];

    std::transform(fish_boxes.begin()+1, fish_boxes.end(), fish_boxes.begin(),
                   [](size_t fish_box)
                   {
                     return fish_box;
                   });

    fish_boxes[6] += ready_for_creation;
    fish_boxes[8] = ready_for_creation;

    return fish_boxes;
  }

  auto fish_count_after_n_days(std::vector<size_t> const& fishes, size_t days) -> size_t
  {
    auto fish_boxes = put_fishes_into_boxes(fishes);
    for (auto _ : std::views::iota(0ul, days))
    {
      fish_boxes = calculate_fish_timer_for_the_next_day(std::move(fish_boxes));
    }

    return std::accumulate(fish_boxes.begin(), fish_boxes.end(), size_t{},
                    [](size_t acc, size_t fish_count){
                      return acc + fish_count;
                    });


  }



}// namespace Day06

namespace AoC {

  Solution<6>::Solution(std::istream &stream)
      : report{Day06::parse(stream)} {}

  auto Solution<6>::part1() const -> int {
    using namespace Day06;
    auto fish_counts = Day06::extract_initial_fish_counts(report);
    return fish_count_after_n_days(fish_counts, 80);
  }

  auto Solution<6>::part2() const -> size_t {
    using namespace Day06;
    auto fish_counts = Day06::extract_initial_fish_counts(report);
    return fish_count_after_n_days(fish_counts, 256);
  }

}// namespace AoC
