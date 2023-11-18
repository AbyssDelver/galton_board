#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../src/board.hpp"

#include <vector>

#include "../src/iopegs.hpp"
#include "doctest.h"

TEST_CASE("checking if asserts work as intended in board constructor") {
  // vector of probability distributions
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

TEST_CASE("testing peg_ev function") {
  SUBCASE("case from test1.txt") {
    galton::matrix pegs;
    try {
      galton::read_pegs(pegs, "tests/test1.txt");
    } catch (std::runtime_error& err) {
      galton::read_pegs(pegs, "../tests/test1.txt");
    }
    const std::vector<double> left_prob{0.5, 0.5, 0.5, 0.5, 1.};

    galton::Board board{pegs, left_prob};

    CHECK(board.peg_ev(4, 3) == doctest::Approx(0.125));
    CHECK(board.peg_ev(4, 4) == doctest::Approx(0.375));
    CHECK(board.peg_ev(4, 5) == doctest::Approx(0.375));
    CHECK(board.peg_ev(4, 6) == doctest::Approx(0.125));
  }

    SUBCASE("case from test2.txt") {
      galton::matrix pegs;
      try {
        galton::read_pegs(pegs, "tests/test2.txt");
      } catch (std::runtime_error& err) {
        galton::read_pegs(pegs, "../tests/test2.txt");
      }
      const std::vector<double> left_prob{0.2, 0.8, 0.1, 0.9, 1.,
                                          0.7, 0.3, 0.8, 0.3, 0.6, 0.};

      galton::Board board{pegs, left_prob};

      double ev_sum{};
      for (int i{}; i < 11; ++i) {
        ev_sum += board.peg_ev(10, i);
        std::cout << "--- " << std::setw(8) << board.peg_ev(10, i) << " ---\n";
      }
      std::cout << '\n';

      for (int i{}; i < 10000; ++i) {
        board.ball();
      }

      board.print_entries_numeric();
      std::cout << '\n';


      CHECK(ev_sum == doctest::Approx(1.));
    }

  SUBCASE("case from test3.txt") {
    galton::matrix pegs;
    try {
      galton::read_pegs(pegs, "tests/test3.txt");
    } catch (std::runtime_error& err) {
      galton::read_pegs(pegs, "../tests/test3.txt");
    }
    const std::vector<double> left_prob{0.2, 0.8, 0.1, 0.9, 1.};

    galton::Board board{pegs, left_prob};

    double ev_sum{};
    for (int i{}; i < 11; ++i) {
      ev_sum += board.peg_ev(4, i);
      std::cout << "--- " << std::setw(8) << board.peg_ev(4, i) << " ---\n";
    }
    std::cout << '\n';

    for (int i{}; i < 10000; ++i) {
      board.ball();
    }

    board.print_entries_numeric();

    CHECK(ev_sum == doctest::Approx(1.));
  }

  SUBCASE("case from test4.txt") {
    galton::matrix pegs;
    try {
      galton::read_pegs(pegs, "tests/test4.txt");
    } catch (std::runtime_error& err) {
      galton::read_pegs(pegs, "../tests/test4.txt");
    }
    const std::vector<double> left_prob{0.2, 0.8,  0.1,  0.9, 0.2,
                                        0.7, 0.42, 0.76, 0.2, 0.8,
                                        0.1, 0.9,  0.2};

    galton::Board board{pegs, left_prob};

    double ev_sum{};
    for (int i{}; i < 15; ++i) {
      ev_sum += board.peg_ev(12, i);
      std::cout << "--- " << std::setw(8) << board.peg_ev(12, i) << " ---\n";
    }
    std::cout << '\n';

    for (int i{}; i < 10000; ++i) {
      board.ball();
    }

    board.print_entries_numeric();
    std::cout << '\n';


    CHECK(ev_sum == doctest::Approx(1.));
  }
}