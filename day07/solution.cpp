#include "solution.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include <sstream>


namespace Day07 {

  auto parse(std::istream &stream) -> std::vector<int> {
    std::vector<std::string> v;
    std::ranges::copy(std::ranges::istream_view<std::string>(stream), std::back_inserter(v));

    std::stringstream ss(v[0]);
    std::vector<int> ints;
    for (int i; ss >> i;) {
      ints.push_back(i);
      if (ss.peek() == ',')
        ss.ignore();
    }

    return ints;
  }

  auto cost_part1(int distance) -> int
  {
    return distance;
  }

  auto cost_part2(int distance) -> int
  {
    int sum = 0;

    for (int i=1; i<=distance; i++)
    {
      sum += i;
    }

    return sum;
  }

  template<typename CostStrategy>
  auto calculate_min_fuel(std::vector<int> const& locations, CostStrategy cost_strategy) -> int
  {
    int min_fuel = INT_MAX;
    int location = 0;

    for(int i=0; i <= *std::max_element(locations.begin(), locations.end()); i++)
    {
      int fuel = 0;

      for (int j=0; j<locations.size(); j++)
      {
        int distance = std::abs(locations[j] - i);
        fuel += cost_strategy(distance);
      }

      if (fuel < min_fuel)
      {
        min_fuel = fuel;
        location = i;
      }
    }

    return min_fuel;
  }

  auto part1_solution(std::vector<int> const& crabs) -> int
  {
    return calculate_min_fuel(crabs, cost_part1);
  }

  auto part2_solution(std::vector<int> const& crabs) -> int
  {
    return calculate_min_fuel(crabs, cost_part2);
  }


}// namespace Day07

namespace AoC {

  Solution<7>::Solution(std::istream &stream)
      : report{Day07::parse(stream)} {}

  auto Solution<7>::part1() const -> int {
    using namespace Day07;
    return part1_solution(report);
  }

  auto Solution<7>::part2() const -> int {
    using namespace Day07;
    return part2_solution(report);
  }

}// namespace AoC
