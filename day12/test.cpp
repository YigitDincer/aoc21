#include "solution.h"

#include <gtest/gtest.h>

#include <array>
#include <string>
#include <vector>

using namespace std::string_view_literals;
constexpr std::array INPUT{"start-A"sv, "start-b"sv, "A-c"sv,  "A-b"sv,
                           "b-d"sv,     "A-end"sv,   "b-end"sv};
constexpr std::array MIDDLE_INPUT{"start-A"sv, "A-c"sv, "A-end"sv, "start-b"sv, "b-end"sv, "b-A"sv};
constexpr std::array SMALL_INPUT{"start-A"sv, "A-b"sv, "b-end"sv, "A-end"sv};

constexpr std::array SLIGHTY_LARGER_EXAMPLE{
        "dc-end"sv, "HN-start"sv, "start-kj"sv, "dc-start"sv, "dc-HN"sv,
        "LN-dc"sv,  "HN-end"sv,   "kj-sa"sv,    "kj-HN"sv,    "kj-dc"sv,
};

constexpr std::array EVEN_LARGER_EXAMPLE{
        "fs-end"sv, "he-DX"sv,    "fs-he"sv, "start-DX"sv, "pj-DX"sv, "end-zg"sv,
        "zg-sl"sv,  "zg-pj"sv,    "pj-he"sv, "RW-he"sv,    "fs-DX"sv, "pj-RW"sv,
        "zg-RW"sv,  "start-pj"sv, "he-WI"sv, "zg-he"sv,    "pj-fs"sv, "start-RW"sv,
};

TEST(Day12, parse_connection) {
  auto connection{"start-A"};
  std::pair<std::string, std::string> expectation{"start", "A"};
  EXPECT_EQ(Day12::parse_connection(connection), expectation);
}

TEST(Day12, parse_input) {
  std::vector<std::pair<std::string, std::string>> expectation{
          {"start", "A"}, {"start", "b"}, {"A", "c"},  {"A", "b"},
          {"b", "d"},     {"A", "end"},   {"b", "end"}};

  EXPECT_EQ(Day12::parse_input(INPUT), expectation);
}

TEST(Day12, unique_elements) {
  auto connections = Day12::parse_input(INPUT);
  std::set<std::string> unique_elements{"start", "A", "b", "c", "d", "end"};
  EXPECT_EQ(Day12::get_unique_elements(connections), unique_elements);
}

TEST(Day12, create_map) {
  std::map<std::string, std::set<std::string>> expectation{{"start", {"A", "b"}},
                                                           {"A", {"c", "b", "end"}},
                                                           {"b", {"A", "d", "end"}},
                                                           {"c", {"A"}},
                                                           {"d", {"b"}},
                                                           {"end", {}}};

  auto connection_pairs = Day12::parse_input(INPUT);
  EXPECT_EQ(Day12::create_map(connection_pairs), expectation);
}

TEST(Day12, create_map_small_input) {
  std::map<std::string, std::set<std::string>> expectation{{"start", {"A"}},
                                                           {"A", {"b", "end"}},
                                                           {"b", {"A", "end"}},
                                                           {"end", {}}};

  auto connection_pairs = Day12::parse_input(SMALL_INPUT);
  EXPECT_EQ(Day12::create_map(connection_pairs), expectation);
}

TEST(Day12, create_connections) {
  auto connections_pairs = Day12::parse_input(SMALL_INPUT);
  auto connection_map = Day12::create_map(connections_pairs);
  auto nodes = Day12::create_nodes(connection_map, Day12::is_legal);
  EXPECT_EQ(Day12::count_possible_paths(nodes), 3);
}

TEST(Day12, count_possible_paths_small_input) {
  auto connections_pairs = Day12::parse_input(SMALL_INPUT);
  auto connection_map = Day12::create_map(connections_pairs);
  auto nodes = Day12::create_nodes(connection_map, Day12::is_legal);

  EXPECT_EQ(Day12::count_possible_paths(nodes), 3);
}

TEST(Day12, count_possible_paths) {
  auto connections_pairs = Day12::parse_input(INPUT);
  auto connection_map = Day12::create_map(connections_pairs);
  auto nodes = Day12::create_nodes(connection_map, Day12::is_legal);

  EXPECT_EQ(Day12::count_possible_paths(nodes), 10);
}

TEST(Day12, count_possible_paths_slighly_larger) {
  auto connections_pairs = Day12::parse_input(SLIGHTY_LARGER_EXAMPLE);
  auto connection_map = Day12::create_map(connections_pairs);
  auto nodes = Day12::create_nodes(connection_map, Day12::is_legal);

  EXPECT_EQ(Day12::count_possible_paths(nodes), 19);
}

TEST(Day12, count_possible_paths_even_larger) {
  auto connections_pairs = Day12::parse_input(EVEN_LARGER_EXAMPLE);
  auto connection_map = Day12::create_map(connections_pairs);
  auto nodes = Day12::create_nodes(connection_map, Day12::is_legal);

  EXPECT_EQ(Day12::count_possible_paths(nodes), 226);
}

TEST(Day12, count_possible_paths_small_input_part2) {
  auto connections_pairs = Day12::parse_input(SMALL_INPUT);
  auto connection_map = Day12::create_map(connections_pairs);
  auto nodes = Day12::create_nodes(connection_map, Day12::is_legal_part2);

  EXPECT_EQ(Day12::count_possible_paths(nodes), 5);
}

TEST(Day12, count_possible_paths_part2) {
  auto connections_pairs = Day12::parse_input(INPUT);
  auto connection_map = Day12::create_map(connections_pairs);
  auto nodes = Day12::create_nodes(connection_map, Day12::is_legal_part2);

  EXPECT_EQ(Day12::count_possible_paths(nodes), 36);
}

TEST(Day12, count_possible_paths_middle_input_part2) {
  auto connections_pairs = Day12::parse_input(MIDDLE_INPUT);
  auto connection_map = Day12::create_map(connections_pairs);
  auto nodes = Day12::create_nodes(connection_map, Day12::is_legal_part2);

//  for (auto const& node : nodes)
//  {
//    if(node.name=="end")
//    {
//      std::cout << "end-";
//      auto parent_idx = node.parent_idx;
//      while(parent_idx != -1)
//      {
//        std::cout << nodes[parent_idx].name << "-";
//        parent_idx = nodes[parent_idx].parent_idx;
//      }
//      std::cout << std::endl;
//    }
//  }

  EXPECT_EQ(Day12::count_possible_paths(nodes), 10);
}

TEST(Day12, count_possible_paths_slighly_larger_part2) {
  auto connections_pairs = Day12::parse_input(SLIGHTY_LARGER_EXAMPLE);
  auto connection_map = Day12::create_map(connections_pairs);
  auto nodes = Day12::create_nodes(connection_map, Day12::is_legal_part2);

  EXPECT_EQ(Day12::count_possible_paths(nodes), 103);
}

TEST(Day12, count_possible_paths_even_larger_part2) {
  auto connections_pairs = Day12::parse_input(EVEN_LARGER_EXAMPLE);
  auto connection_map = Day12::create_map(connections_pairs);
  auto nodes = Day12::create_nodes(connection_map, Day12::is_legal_part2);

  EXPECT_EQ(Day12::count_possible_paths(nodes), 3509);
}