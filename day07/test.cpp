#include <gtest/gtest.h>

#include "solution.h"

#include <sstream>
#include <string>
#include <vector>

static const std::vector<int> CRABS = {16,1,2,0,4,2,7,1,2,14};




TEST(Day07, cost_part1) {
  EXPECT_EQ(Day07::part1_solution(CRABS), 37);
}

TEST(Day07, cost_part2) {
  EXPECT_EQ(Day07::part2_solution(CRABS), 168);
}
