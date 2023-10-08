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

  galton::Board board(pegs);

  while (true) {
    std::cout << "Enter the number of balls to drop on the galton board:\n";
    int n{};

    if (!(std::cin >> n)){
      // Input was not a valid integer
      std::cin.clear();  // Clear error flags
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // Discard the invalid input
      std::cout << "Invalid input. Please enter an integer.\n" << std::endl;
    }

    for (int i{}; i < n; ++i) {
      board.ball();
    }

    galton::print_pegs(pegs);
    board.print_entries_graphic();
    board.print_entries_numeric();
    board.clear_entries();
  }
}
