#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

namespace galton {
using matrix = std::vector<std::vector<int>>;

class Board {
  matrix m_pegs;
  //probability that the ball falls left, index is row
  std::vector<double> m_left_prob;
  size_t width;
  size_t height;

  void pass(size_t row, size_t column);
  void drop(size_t row, size_t column);

 public:
  Board(matrix, const std::vector<double>&);
  void ball();
  void print_entries_graphic();
  void print_entries_numeric();
  void clear_entries();
};

}  // namespace galton
#endif