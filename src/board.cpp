#include "board.hpp"

#include <cassert>
#include <iostream>
#include <random>

#include "iopegs.hpp"

#define DEBUG_BOARD false

constexpr int occurence_print_size{10};

std::random_device rd;   // a seed source for the random number engine
std::mt19937 gen(rd());  // mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> distrib(0, 1);

namespace galton {
// todo: add assert that all the vectors be comprised of ones and zeros
Board::Board(matrix pegs) : m_pegs{pegs}, height{pegs.size()} {
  if (height % 2 != 0) {
    throw std::invalid_argument("height must be an even number");
  };

  if (height == 0) {
    throw std::invalid_argument("height cannot have value 0");
  };

  if ((pegs[0].size()) % 2 == 0) {
    throw std::invalid_argument(
        "first row must have an uneven number of elements");
  };

  width = pegs[0].size();

  for (int i{0}; static_cast<size_t>(i) < pegs.size(); i++) {
    if (i % 2 == 0) {
      if ((pegs[i].size() != width)) {
        throw std::invalid_argument(
            "rows must alternate between sizes of width and sizes of width - "
            "1");
      };
    } else {
      if ((pegs[i].size() != width - 1)) {
        throw std::invalid_argument(
            "rows must alternate between sizes of width and sizes of width - "
            "1");
      };
    }
  }

  std::vector<int> occurences(width);
  // todo: check by deafult it's zero vector
  m_pegs.push_back(occurences);
}

void Board::drop(size_t row, size_t column) {
  // handle dropping to end of table
  if (row + 2 >= height) {
    if (row % 2 == 0) {
      ++m_pegs[height][column];
      return;
    }

    // sumulating hitting border of section divider:
    auto direction = distrib(gen);

    if (direction == 1) {
      ++m_pegs[height][column + 1];
      return;
    }

    if (direction == 0) {
      ++m_pegs[height][column];
      return;
    }
  }

  // in case the ball is not dropping to the bottom:
  pass(row + 2, column);
}

void Board::pass(size_t row, size_t column) {
  // debug mode for board, prints all boards
  if (DEBUG_BOARD) {
    auto temp{m_pegs[row][column]};
    m_pegs[row][column] = -1;
    print_pegs(m_pegs);
    m_pegs[row][column] = temp;
  }

  assert(row <= height);
  assert(column < width);

  // handle if we are at last column
  if (row == height) {
    // add one to occurences
    ++m_pegs[row][column];
    return;
  }

  // handle if there is no peg
  if (m_pegs[row][column] == 0) {
    Board::drop(row, column);
    return;
  }

  // 1 for right, 0 for left
  auto direction = distrib(gen);

  // handle if there is peg and row is even
  if (row % 2 == 0) {
    if (direction == 1) {
      // if we are at the border on the right
      if (column + 1 == width) {
        Board::drop(height, column);
        return;
      }

      pass(row + 1, column);
      return;
    }

    if (direction == 0) {
      // if we are at the border on the left
      if (column == 0) {
        Board::drop(height, column);
        return;
      }

      pass(row + 1, column - 1);
      return;
    }
  }

  // handle if there is peg and row is not even
  if (direction == 1) {
    pass(row + 1, column + 1);
    return;
  }
  if (direction == 0) {
    pass(row + 1, column);
    return;
  }
}

void Board::ball() { pass(0, (width + 1) / 2 - 1); }

// todo: remove last |
void Board::print_occurences() {
  auto max = *(std::max_element(m_pegs[height].begin(), m_pegs[height].end()));
  for (size_t i{}; i < occurence_print_size; ++i) {
    for (size_t j{}; j < m_pegs[height].size(); ++j) {
      auto entry = m_pegs[height][j];

      if (static_cast<double>(entry) / max * occurence_print_size >=
          static_cast<double>(occurence_print_size - i)) {
        std::cout << 'x';

      } else {
        std::cout << ' ';
      }

      if (j + 1 != m_pegs[height].size()) {
        std::cout << '|';
      }
    }
    std::cout << '\n';
  }
}
}  // namespace galton