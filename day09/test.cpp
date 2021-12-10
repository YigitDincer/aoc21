#include <gtest/gtest.h>

#include "solution.h"

#include <sstream>
#include <string>
#include <vector>

static const std::vector<std::string> CAVE {"2199943210", "3987894921", "9856789892",
                                                "8767896789", "9899965678"};

TEST(Day9, sum_of_risk_points)
{
  EXPECT_EQ(Day9::sum_of_risk_points(CAVE), 15);
}

TEST(Day9, create_map)
{
  EXPECT_EQ(Day9::create_map(CAVE), "21999432103987894921985678989287678967899899965678");
}
