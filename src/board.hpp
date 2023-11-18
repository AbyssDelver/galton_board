#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

namespace galton {
using matrix = std::vector<std::vector<int>>;

class Board {
  matrix m_pegs;
  // probability that the ball falls left, index is row
  std::vector<double> m_left_prob;
  size_t width;
  size_t height;

  void pass(size_t row, size_t column);
  void drop(size_t row, size_t column);
  double drop_ev(size_t const row, size_t const column);

 public:
  Board(matrix, const std::vector<double>&);
  void ball();
  void print_entries_graphic();
  void print_entries_numeric();
  void clear_entries();
  // returns expected value of bin, 0 being the first, width-1 being the last
  double expected_value(size_t bin);
  // calculates the form expected value of the ball falling on the pin.
  // recursive.
  double peg_ev(size_t const row, size_t const column);
};

}  // namespace galton
#endif