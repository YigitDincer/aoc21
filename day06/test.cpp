#include <gtest/gtest.h>

#include "solution.h"

static const std::vector<size_t> input = {3,4,3,1,2};

TEST(Day06, extract_initial_fish_counts) {
  std::vector<std::string> input_line {"3,1,2,3,4"};
  std::vector<size_t> const expectation{3,1,2,3,4};
  EXPECT_EQ(Day06::extract_initial_fish_counts(input_line), expectation);
}

TEST(Day06, fish_count_after_n_days) {
  EXPECT_EQ(Day06::fish_count_after_n_days(input, 18), 26);
  EXPECT_EQ(Day06::fish_count_after_n_days(input, 80), 5934);
  EXPECT_EQ(Day06::fish_count_after_n_days(input, 256), 26984457539);
}

TEST(Day06, put_fishes_into_boxes)
{
  std::vector<size_t> expectation {0, 1, 1, 2, 1, 0, 0, 0, 0};
  EXPECT_EQ(Day06::put_fishes_into_boxes(input), expectation);
}

TEST(Day06, calculate_the_next_day)
{
  auto boxes = Day06::put_fishes_into_boxes(input);
  std::vector<size_t> expectation {1, 1, 2, 1, 0, 0, 0, 0, 0};
  EXPECT_EQ(Day06::calculate_fish_timer_for_the_next_day(boxes), expectation);
}

TEST(Day06, calculate_the_next_day_after_creation)
{
  auto boxes = Day06::put_fishes_into_boxes({0, 0, 0, 1});
  std::vector<size_t> expectation {1, 0, 0, 0, 0, 0, 3, 0, 3};
  EXPECT_EQ(Day06::calculate_fish_timer_for_the_next_day(boxes), expectation);
}

