#include <gtest/gtest.h>

#include "solution.h"

#include <sstream>
#include <string>
#include <vector>

static const std::vector<std::string> input{"{([(<{}[<>[]}>{[]{[(<()>", "[[<[([]))<([[{}[[()]]]",
                                            "[{[{({}]{}}([{[{{{}}([]", "[<(<(<(<{}))><([]([]()",
                                            "<{([([[(<>()){}]>(<<{{"};

static const std::vector<std::string> input2{"[({(<(())[]>[[{[]{<()<>>", "[(()[<>])]({[<{<<[]>>(",
                                             "(((({<>}<{<{<>}{[]{[]{}", "{<[[]]>}<{[{[{[]{()[[[]",
                                             "<{([{{}}[<[[[<>{}]]]>[]]"};


TEST(day11, first_illegal_character) {
  EXPECT_EQ(Day11::first_illegal_character("{([(<{}[<>[]}>{[]{[(<()>"), '}');
}

TEST(day11, first_illegal_character_2) {
  EXPECT_EQ(Day11::first_illegal_character("[[<[([]))<([[{}[[()]]]"), ')');
}

TEST(day11, calculate_points_sum) { EXPECT_EQ(Day11::calculate_points_for_part1(input), 26397); }

TEST(day11, mathematical_sum_of_missing_characters) {
  EXPECT_EQ(Day11::mathematical_sum_of_missing_characters("<{([{{}}[<[[[<>{}]]]>[]]"), 294);
}

TEST(day11, mathematical_sum_of_missing_characters_2) {
  EXPECT_EQ(Day11::mathematical_sum_of_missing_characters("[({(<(())[]>[[{[]{<()<>>"), 288957);
}

TEST(day11, calculate_points_for_part2) {
  EXPECT_EQ(Day11::calculate_points_for_part2(input2), 288957);
}