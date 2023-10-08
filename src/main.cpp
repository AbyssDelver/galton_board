#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "board.hpp"
#include "iopegs.hpp"

int main() {
  galton::matrix pegs;
  try {
    galton::read_pegs(pegs, "pegs.txt");
  } catch (std::runtime_error& err) {
    galton::read_pegs(pegs, "../pegs.txt");
  }

  galton::print_pegs(pegs);
  galton::Board board(pegs);
  for (int i{}; i < 200; ++i) {
    board.ball();
  }
  board.print_occurences();
}
