#include "board.hpp"

#include <cassert>
#include <iomanip>
#include <iostream>
#include <random>

#include "iopegs.hpp"

#define DEBUG_BOARD false

constexpr int entries_print_size{8};

static std::random_device rd;   // a seed source for the random number engine
static std::mt19937 gen(rd());  // mersenne_twister_engine seeded with rd()
// todo: check is actually double
static std::uniform_real_distribution<> distrib(0., 1.);

namespace galton {
// todo: add assert that all the vectors be comprised of ones and zeros
// todo: check that is deep copy
Board::Board(matrix pegs, const std::vector<double>& left_prob)
    : m_pegs{pegs}, m_left_prob{left_prob}, height{pegs.size()} {
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
  if (left_prob.size() != height + 1) {
    throw std::invalid_argument(
        "vector of row probability should contain as many elements as rows in "
        "the board, plus another one for the probability of section dividers "
        "in case of ball "
        "drop on last row");
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
            "rows must alternate between sizes of the width and sizes of the "
            "width - "
            "1");
      };
    }
  }

  std::vector<int> entries_(width);
  // todo: check by deafult it's zero vector
  m_pegs.push_back(entries_);
}

size_t Board::get_width() const { return width; }

size_t Board::get_height() const { return height; }

void Board::change_left_prob(size_t entry, double new_element) {
  assert(entry < height + 1);
  if(new_element > 1){
    m_left_prob[entry] = 1;
  }
  else if(new_element < 0){
    m_left_prob[entry] = 0;
  }
  else{
  m_left_prob[entry] = new_element;
  }
}

double Board::get_left_prob(size_t entry) const {
  assert(entry < height + 1);
  return m_left_prob[entry];
}

void Board::drop(size_t row, size_t column) {
  // handle droppegg to end of table
  if (row + 2 >= height) {
    if (row % 2 == 0) {
      ++m_pegs[height][column];
      return;
    }

    // sumulating hitting border of section divider:
    auto direction = distrib(gen);

    if (direction >= m_left_prob[height]) {
      ++m_pegs[height][column + 1];
      return;
    }

    if (direction < m_left_prob[height]) {
      ++m_pegs[height][column];
      return;
    }
  }

  // in case the ball is not droppegg to the bottom:
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
    // add one to entries_
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
    if (direction >= m_left_prob[row]) {
      // if we are at the border on the right
      if (column + 1 == width) {
        Board::drop(height, column);
        return;
      }

      pass(row + 1, column);
      return;
    }

    if (direction < m_left_prob[row]) {
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
  if (direction >= m_left_prob[row]) {
    pass(row + 1, column + 1);
    return;
  }
  if (direction < m_left_prob[row]) {
    pass(row + 1, column);
    return;
  }
}

// ball initialization passes ball from the peg in the middle, at the top row
void Board::ball() { pass(0, (width + 1) / 2 - 1); }

// todo: remove last |
void Board::print_entries_graphic() const {
  auto max = *(std::max_element(m_pegs[height].begin(), m_pegs[height].end()));
  for (size_t i{}; i < entries_print_size; ++i) {
    for (size_t j{}; j < m_pegs[height].size(); ++j) {
      auto entry = m_pegs[height][j];

      if (static_cast<double>(entry) / max * entries_print_size >=
          static_cast<double>(entries_print_size - i)) {
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

void Board::print_entries_numeric() const {
  for (auto entry : m_pegs[height]) {
    std::cout << "--- " << std::setw(8) << entry << " ---\n";
  }
}

void Board::clear_entries() {
  std::replace_if(
      m_pegs[height].begin(), m_pegs[height].end(), [](int) { return true; },
      0);
}

// Calculates the form expected value of the ball falling on the peg. Recursive.
// Bottom up approach. Starts from peg and asks: where did it come from? left?
// right? did it drop from above? with which probability?
double Board::peg_ev(size_t const row, size_t const column) const {
  assert(row >= 0);
  assert(column >= 0);
  // It allows even the calculation of expected values on bins, if row = height
  // TODO: delete
  assert(row <= height);
  assert(column < width);

  double ev{};

  // The recursion stops here.
  // If we are at the top of the row, we are sure the ball hit the middle peg.
  if (row == 0) {
    assert(column == (width + 1) / 2 - 1);
    return 1.;
  }

  // Checking if column to the right on the row above exists.
  if (row % 2 == 0 && column != width - 1) {
    // If the peg to the right is not empty calculate it's ev.
    if (m_pegs[row - 1][column] == 1) {
      // probability of coming from right = (probability of pegs above going
      // left) * (probability of getting to peg above to the right)
      ev += m_left_prob[row - 1] * peg_ev(row - 1, column);
    }
  } else if (row % 2 != 0) {
    // If the peg is not empty calculate it's ev.
    if (m_pegs[row - 1][column + 1] == 1) {
      ev += m_left_prob[row - 1] * peg_ev(row - 1, column + 1);
    }
  }

  // Checking if column to the left on the row above exists.
  if (row % 2 == 0 && column != 0) {
    // If the peg to the left is not empty calculate it's ev.
    if (m_pegs[row - 1][column - 1] == 1) {
      // probability of coming from left = (probability of pegs above going
      // right) * (probability of getting to peg above to the left)
      ev += (1 - m_left_prob[row - 1]) * peg_ev(row - 1, column - 1);
    }
  } else if (row % 2 != 0) {
    // If the peg is not empty calculate it's ev.
    if (m_pegs[row - 1][column] == 1) {
      ev += (1 - m_left_prob[row - 1]) * peg_ev(row - 1, column);
    }
  }

  if (row > 2) {
    // If peg above is not present, then we calculate the ev of that point.
    if (m_pegs[row - 2][column] == 0) {
      ev += peg_ev(row - 2, column);
    }
  }

  // If we are calculating ev from the bins, then we also have to consider the
  // proability of hitting a diveder of the bins.
  if (row == height) {
    // From the right.
    if (column != width - 1) {
      if (m_pegs[row - 1][column] == 0) {
        ev += m_left_prob[height] * peg_ev(row - 1, column);
      }
    }
    // Handle case of ball falling in last bin by hitting a wall.
    else {
      for (int row_i{static_cast<int>(height) - 2}; row_i > 0; row_i -= 2) {
        if (m_pegs[row_i][width - 1] == 1) {
          ev += (1 - m_left_prob[row_i]) * peg_ev(row_i, width - 1);
        }
      }
    }
    // From the left.
    if (column != 0) {
      if (m_pegs[row - 1][column - 1] == 0) {
        ev += (1 - m_left_prob[height]) * peg_ev(row - 1, column - 1);
      }
    }
    // Handle case of ball falling in first bin by hitting a wall.
    else {
      for (int row_i{static_cast<int>(height) - 2}; row_i > 0; row_i -= 2) {
        if (m_pegs[row_i][0] == 1) {
          ev += m_left_prob[row_i] * peg_ev(row_i, 0);
        }
      }
    }
  }
  assert(ev <= 1.009);
  return ev;
}
}  // namespace galton