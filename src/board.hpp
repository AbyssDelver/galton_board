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

  //Getter functions
  size_t get_width() const;
  size_t get_height() const;

  void change_left_prob(size_t entry, double new_element);
  double get_left_prob(size_t entry) const;

  void ball();
  void print_entries_graphic() const;
  void print_entries_numeric() const;
  void clear_entries();

  // calculates the form expected value of the ball falling on the pin.
  // recursive.
  double peg_ev(size_t const row, size_t const column) const;
};

}  // namespace galton
#endif