#include "solution.h"

#include <string>

#include <algorithm>
#include <numeric>
#include <optional>
#include <ranges>
#include <stack>


namespace Day10 {

  auto parse(std::istream &stream) -> std::vector<std::string> {
    std::vector<std::string> v;
    std::ranges::copy(std::ranges::istream_view<std::string>(stream), std::back_inserter(v));
    return v;
  }

  auto is_opening(char character) -> bool {
    return character == '(' || character == '[' || character == '<' || character == '{';
  }

  auto closing_character(char character) -> char {
    switch (character) {
      case '(':
        return ')';
      case '[':
        return ']';
      case '<':
        return '>';
      case '{':
        return '}';
      default:
        throw;
    }
  }

  auto char_values_for_part2(char character) -> int {
    switch (character) {
      case '(':
        return 1;
      case '[':
        return 2;
      case '{':
        return 3;
      case '<':
        return 4;
      default:
        throw;
    }
  }

  auto char_values_for_part1(char character) -> int {
    switch (character) {
      case ')':
        return 3;
      case ']':
        return 57;
      case '}':
        return 1197;
      case '>':
        return 25137;
      case ' ':
        return 0;
      default:
        throw;
    }
  }

  auto calculate_points_for_part1(std::vector<std::string> const &input) -> int {
    return std::accumulate(input.begin(), input.end(), (int) 0, [](int acc, std::string line) {
      acc += char_values_for_part1(first_illegal_character(line).value_or(' '));
      return acc;
    });
  }

  auto calculate_points_for_part2(std::vector<std::string> const &input) -> long long int {

    std::vector<std::string> filtered_result;
    std::copy_if(input.begin(), input.end(), std::back_inserter(filtered_result),
                 [](std::string line) { return !first_illegal_character(line).has_value(); });

    std::vector<long long int> missing_char_scores;
    std::transform(filtered_result.begin(), filtered_result.end(),
                   std::back_inserter(missing_char_scores),
                   [](std::string line) { return mathematical_sum_of_missing_characters(line); });

    std::sort(missing_char_scores.begin(), missing_char_scores.end());

    return missing_char_scores[missing_char_scores.size() / 2];
  }


  auto first_illegal_character(std::string const &line) -> std::optional<char> {
    std::stack<char> stack;

    for (auto const &character : line) {
      if (is_opening(character)) {
        stack.push(character);
      } else {
        if (closing_character(stack.top()) == character) {
          stack.pop();
          continue;
        } else {
          return character;
        }
      }
    }

    return std::nullopt;
  }

  auto mathematical_sum_of_missing_characters(std::string const &line) -> long long int {
    std::stack<char> stack;

    for (auto const &character : line) {
      if (is_opening(character)) {
        stack.push(character);
      } else {
        if (closing_character(stack.top()) == character) {
          stack.pop();
          continue;
        }
      }
    }

    long long int sum = 0;
    while (!stack.empty()) {
      sum = sum * 5 + char_values_for_part2(stack.top());
      stack.pop();
    }

    return sum;
  }


}// namespace Day10

namespace AoC {

  Solution<10>::Solution(std::istream &stream)
      : report{Day10::parse(stream)} {}

  auto Solution<10>::part1() const -> int {
    using namespace Day10;
    return calculate_points_for_part1(report);
  }

  auto Solution<10>::part2() const -> long long int {
    using namespace Day10;
    return calculate_points_for_part2(report);
  }

}// namespace AoC
