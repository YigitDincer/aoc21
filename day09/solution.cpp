#include "solution.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>


namespace Day9 {

  auto parse(std::istream &stream) -> std::vector<std::string> {
    std::vector<std::string> v;
    std::ranges::copy(std::ranges::istream_view<std::string>(stream), std::back_inserter(v));
    return v;
  }

  auto get_mask_indices(std::vector<std::string> cave) -> std::vector<std::pair<int, int>> {
    std::vector<std::pair<int, int>> indices;

    int line_size = cave.front().size();

    indices.push_back({-line_size - 1, -1});
    indices.push_back({-line_size, 0});
    indices.push_back({-line_size + 1, 1});
    indices.push_back({-1, -1});
    indices.push_back({1, 1});
    indices.push_back({line_size - 1, -1});
    indices.push_back({line_size, 0} );
    indices.push_back({line_size + 1, 1});

    return indices;
  }

  auto create_map(std::vector<std::string> const &cave) -> std::string {
    return std::accumulate(cave.begin(), cave.end(), std::string{});
  }

  auto sum_of_risk_points(std::vector<std::string> const &cave) -> int {
    auto const indices = get_mask_indices(cave);
    auto map = create_map(cave);

    int counter = 0;
    int cave_dimension = cave.front().size();

    for (int i = 0; i < map.size(); i++) {
      std::vector<int> indices_reduced =
              std::accumulate(indices.begin(), indices.end(), std::vector<int>(),
                              [&i, &cave_dimension, &map](std::vector<int> acc, std::pair<int, int> offset) {
                                int new_idx = i + offset.first;

                                int new_idx_col = new_idx % cave_dimension;
                                int current_col = i%cave_dimension;

                                if (new_idx >= 0 && (new_idx_col - current_col == offset.second) && new_idx < map.size()) { acc.push_back(new_idx); };
                                return acc;
                              });

        if (std::ranges::all_of(indices_reduced,
                        [&i, &map](int offset) { return (map[i]-'0') < (map[offset]-'0'); })) {
          counter += map[i]-'0' + 1;
        }

    }

    return counter;
  }


}// namespace Day9

namespace AoC {

  Solution<9>::Solution(std::istream &stream)
      : report{Day9::parse(stream)} {}

  auto Solution<9>::part1() const -> int {
    using namespace Day9;
    return Day9::sum_of_risk_points(report);
  }

  auto Solution<9>::part2() const -> int {
    using namespace Day9;
    return 42;
  }

}// namespace AoC
