#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "board.hpp"

#include <vector>

#include "doctest.h"

TEST_CASE("checking if asserts work as intended in board constructor") {
  SUBCASE("passing empty matrix") {
    std::vector<std::vector<int>> vec = {};
    CHECK_THROWS_WITH(galton::Board board{vec}, "height cannot have value 0");
  }

  SUBCASE("passing matrix with non even height") {
    std::vector<std::vector<int>> vec = {{0, 0, 0}, {0, 0}, {0, 0, 0}};
    CHECK_THROWS_WITH(galton::Board board{vec},
                      "height must be an even number");
  }

  SUBCASE("passing matrix that with first element not uneven") {
    std::vector<std::vector<int>> vec = {{0, 0}, {0, 0}};
    CHECK_THROWS_WITH(galton::Board board{vec},
                      "first row must have an uneven number of elements");
  }

  SUBCASE("passing matrix with non alternating elements") {
    std::vector<std::vector<int>> vec = {
        {0, 0, 0}, {0, 0}, {0, 0, 0}, {0, 0, 0}};
    CHECK_THROWS_WITH(
        galton::Board board{vec},
        "rows must alternate between sizes of width and sizes of width - 1");
  }

  SUBCASE("passing valid matrix") {
    std::vector<std::vector<int>> vec = {{0, 0, 0}, {0, 0}, {0, 0, 0}, {0, 0}};
    CHECK_NOTHROW(galton::Board board{vec});
  }
}