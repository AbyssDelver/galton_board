#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "board.hpp"

#include <vector>

#include "doctest.h"

// vector of probability distributions

TEST_CASE("checking if asserts work as intended in board constructor") {
  const std::vector<double> h1{0.5};
  const std::vector<double> h2{0.5, 0.5};
  const std::vector<double> h3{0.5, 0.5, 0.5};
  const std::vector<double> h4{0.5, 0.5, 0.5, 0.5};
  const std::vector<double> h5{0.5, 0.5, 0.5, 0.5, 0.5};

  SUBCASE("passing empty matrix") {
    std::vector<std::vector<int>> vec = {};
    CHECK_THROWS_WITH(galton::Board(vec, h1), "height cannot have value 0");
  }

  SUBCASE("passing matrix with non even height") {
    std::vector<std::vector<int>> vec = {{0, 0, 0}, {0, 0}, {0, 0, 0}};
    CHECK_THROWS_WITH(galton::Board(vec, h4), "height must be an even number");
  }

  SUBCASE("passing matrix that with first element not uneven") {
    std::vector<std::vector<int>> vec = {{0, 0}, {0, 0}};
    CHECK_THROWS_WITH(galton::Board(vec, h3),
                      "first row must have an uneven number of elements");
  }

  SUBCASE("passing matrix with non alternating elements") {
    std::vector<std::vector<int>> vec = {
        {0, 0, 0}, {0, 0}, {0, 0, 0}, {0, 0, 0}};
    CHECK_THROWS_WITH(galton::Board(vec, h5),
                      "rows must alternate between sizes of the width and "
                      "sizes of the width - 1");
  }

  SUBCASE("passing valid matrix") {
    std::vector<std::vector<int>> vec = {{0, 0, 0}, {0, 0}, {0, 0, 0}, {0, 0}};
    CHECK_NOTHROW(galton::Board board{vec, h5});
  }
}