#include "solution.h"

#include <string>

#include <algorithm>
#include <numeric>
#include <optional>
#include <ranges>


namespace Day12 {

  auto parse(std::istream &stream) -> std::vector<std::string> {
    std::vector<std::string> v;
    std::ranges::copy(std::ranges::istream_view<std::string>(stream), std::back_inserter(v));
    return v;
  }

  auto parse_connection(std::string_view line) -> std::pair<std::string, std::string> {
    auto dash_pos = line.find('-');
    return std::pair{std::string{line.substr(0, dash_pos)}, std::string{line.substr(dash_pos + 1)}};
  }

  auto parse_input(std::span<std::string_view const> input)
          -> std::vector<std::pair<std::string, std::string>> {
    std::vector<std::pair<std::string, std::string>> parsed_connections;
    std::ranges::transform(
            input, std::back_inserter(parsed_connections),
            [](std::string_view connection) { return parse_connection(connection); });

    return parsed_connections;
  }

  auto get_unique_elements(std::vector<std::pair<std::string, std::string>> const &connection_pairs)
          -> std::set<std::string> {

    std::set<std::string> unique_elements;

    for (auto const &connection : connection_pairs) {
      unique_elements.insert(connection.first);
      unique_elements.insert(connection.second);
    }

    return unique_elements;
  }

  auto create_map(std::vector<std::pair<std::string, std::string>> const &connection_pairs)
          -> std::map<std::string, std::set<std::string>> {
    std::map<std::string, std::set<std::string>> connection_map;

    auto unique_elements = get_unique_elements(connection_pairs);
    unique_elements.erase("end");

    for (auto const &unique_element : unique_elements) {
      std::set<std::string> values;

      for (auto const &connection : connection_pairs) {
        if (connection.first == unique_element) {
          values.insert(connection.second);
        } else if (connection.second == unique_element) {
          values.insert(connection.first);
        }
      }
      values.erase("start");
      connection_map[unique_element] = values;
    }

    connection_map["end"] = {};
    return connection_map;
  }

  auto is_legal(std::vector<Node> const &nodes, std::string_view string_to_check, int parent_idx)
          -> bool {
    if (std::ranges::any_of(string_to_check, [](unsigned char c) { return std::islower(c); })) {
      while (parent_idx != -1) {
        if (nodes.at(parent_idx).name == string_to_check) {
          return false;
        } else {
          parent_idx = nodes.at(parent_idx).parent_idx;
        }
      }
    }
    return true;
  }

  auto is_legal_part2(std::vector<Node> const &nodes, std::string_view string_to_check,
                      int parent_idx) -> bool {
    std::set<std::string_view> visited_lower_nodes;

    if (std::ranges::any_of(string_to_check, [](unsigned char c) { return std::islower(c); })) {
      while (parent_idx != -1) {

        auto parent_node_name = nodes.at(parent_idx).name;

        if(std::ranges::any_of(parent_node_name, [](unsigned char c){ return std::islower(c);}))
        {
          visited_lower_nodes.insert(nodes.at(parent_idx).name);
        }


          if (visited_lower_nodes.find(string_to_check) != visited_lower_nodes.end()) {
            return false;
          }

        parent_idx = nodes.at(parent_idx).parent_idx;
      }
    }
    return true;
  }

  auto count_possible_paths(std::vector<Node> const &nodes) -> size_t {
    return std::accumulate(nodes.begin(), nodes.end(), size_t{},
                           [](size_t acc, Node const &node) { return acc + (node.name == "end"); });
  }

}// namespace Day12

namespace AoC {

  Solution<12>::Solution(std::istream &stream)
      : report{Day12::parse(stream)} {}

  auto Solution<12>::part1() const -> size_t {
    using namespace Day12;

    std::vector<std::pair<std::string, std::string>> connections_vec;
    auto connections_pairs_range = report | std::views::transform(parse_connection);
    std::ranges::copy(connections_pairs_range, std::back_inserter(connections_vec));
    auto connection_map = create_map(connections_vec);
    auto nodes = create_nodes(connection_map, is_legal);
    return count_possible_paths(nodes);
  }

  auto Solution<12>::part2() const -> size_t {
    using namespace Day12;


    return 42;
  }

}// namespace AoC
