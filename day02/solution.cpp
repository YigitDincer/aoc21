#include "solution.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <ranges>
#include <sstream>


namespace Day02 {

  auto parse(std::istream &stream) -> std::string {
    return {std::istreambuf_iterator<char>{stream}, std::istreambuf_iterator<char>{}};
  }


  struct Point
  {
    int x;
    int y;
    int aim;
  };

  auto part01(std::string const& input) -> Point
  {
    std::stringstream file(input);

    std::string direction;
    int units;

    Point point{0,0};

    while (file >> direction >> units)
    {
      if (direction == "forward")
      {
        point.x += units;
      }
      else if (direction == "down")
      {
        point.y += units;
      }
      else if (direction == "up")
      {
        point.y -= units;
      }
    }

    return point;
  }

  auto part02(std::string const& input) -> Point
  {
    std::stringstream file(input);

    std::string direction;
    int units;

    Point point{0,0};

    while (file >> direction >> units)
    {
      if (direction == "forward")
      {
        point.x += units;
        point.y += point.aim * units;
      }
      else if (direction == "down")
      {
        point.aim += units;
      }
      else if (direction == "up")
      {
        point.aim -= units;
      }
    }

    return point;
  }




}// namespace Day02

namespace AoC {

  Solution<2>::Solution(std::istream &stream)
      : input{Day02::parse(stream)} {}

  auto Solution<2>::part1() const -> int {
    using namespace Day02;
    Point p1 = part01(input);
    return p1.x * p1.y;
  }

  auto Solution<2>::part2() const -> int {
    using namespace Day02;
    Point p2 = part02(input);
    return p2.x * p2.y;
  }

}// namespace AoC
