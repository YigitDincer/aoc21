#include <gtest/gtest.h>

#include "solution.h"

#include <sstream>
#include <string>
#include <vector>

static const std::string LINE = {"be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe"};

TEST(Day08, get_four_digits) {
  std::vector<std::string> solution{"fdgacbe", "cefdb", "cefbgd", "gcbe"};
  EXPECT_EQ(Day08::get_four_digits(LINE), solution);
}

TEST(Day08, is_unique) {
  EXPECT_EQ(Day08::is_unique("fdgacbe"), true);
  EXPECT_EQ(Day08::is_unique("cefdb"), false);
  EXPECT_EQ(Day08::is_unique("cefbgd"), false);
  EXPECT_EQ(Day08::is_unique("gcbe"), true);
}

TEST(Day08, count_unique_digits) {
  auto digits = Day08::get_four_digits(LINE);
  EXPECT_EQ(Day08::count_unique_digits(digits), 2);
}
