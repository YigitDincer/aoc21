#pragma once

#include "../solution.h"

#include <map>
#include <set>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace Day12 {

  struct Node
  {
    std::string name;
    int parent_idx;
  };

  auto parse_connection(std::string_view line) -> std::pair<std::string, std::string>;
  auto parse_input(std::span<std::string_view const> input) -> std::vector<std::pair<std::string, std::string>>;
  auto get_unique_elements(std::vector<std::pair<std::string, std::string>> const& elems) -> std::set<std::string>;
  auto create_map(std::vector<std::pair<std::string, std::string>> const& connection_pairs) -> std::map<std::string, std::set<std::string>>;
  auto is_legal(std::vector<Node> nodes, std::string string_to_check, int parent_idx) -> bool;

  auto count_possible_paths(std::vector<Node> const&) -> size_t;

  template <typename T>
  auto create_nodes(std::map<std::string, std::set<std::string>> const &connection_map,
                    T&& is_legal_fct)
          -> std::vector<Node>
  requires std::invocable<T, std::vector<Node>, std::string, int>
  {
    std::vector<Node> nodes;
    nodes.push_back({"start", -1});

    int parent_ctr = 0;

    while (parent_ctr < nodes.size()) {
      for (auto const &connection : connection_map.at(nodes[parent_ctr].name)) {

        if (std::invoke(is_legal_fct, nodes, connection, parent_ctr)) { nodes.push_back({connection, parent_ctr}); }
      }
      parent_ctr++;
    }

    return nodes;
  }
}

namespace AoC {

  template <>
  struct Solution<12> {
    explicit Solution(std::istream &);
    auto part1() const -> size_t;
    auto part2() const -> size_t;

  private:
    std::vector<std::string> report;
  };

}// namespace AoC
