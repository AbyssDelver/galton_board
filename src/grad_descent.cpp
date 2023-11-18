#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "board.hpp"
#include "constants.hpp"
#include "iopegs.hpp"

double calculate_chi_squared(const std::vector<double>& evs) {
  assert(evs.size() == consts::wanted_ev.size());

  double chi_squared{};

  for (int i{}; i < evs.size(); ++i) {
    chi_squared += (evs[i] - consts::wanted_ev[i]) *
                   (evs[i] - consts::wanted_ev[i]) / consts::wanted_ev[i];
  }
  return chi_squared;
}

void calculate_evs(std::vector<double>& evs, const galton::Board& board) {
  assert(evs.size() == board.get_width());
  for (int i{}; i < evs.size(); ++i) {
    evs[i] = board.peg_ev(board.get_height(), i);
  }

  // TODO: why does it not work???
  //  the sum of the evs should be close to 1:'
  double total = std::accumulate(evs.begin(), evs.end(), 0.);
  assert(total > 0.99 && total < 1.09);
}

int main() {
  galton::matrix pegs;
  try {
    galton::read_pegs(pegs, consts::file_name);
  } catch (std::runtime_error& err) {
    galton::read_pegs(pegs, "../" + consts::file_name);
  }

  // Vector holds porbabilities that get updated. Put inside a good initial
  // guess.
  std::vector<double> prob_left = consts::init_prob_left;

  galton::Board board(pegs, prob_left);

  std::vector<double> evs(board.get_width());

  for (int j{}; j < consts::descent_iterations; ++j) {
    std::cout << "--- " << std::setw(8) << "iteration number: " << j
              << " ---\n";

    for (int i{}; i < static_cast<int>(board.get_height()) + 1; ++i) {
      calculate_evs(evs, board);
      double chi_squared1{calculate_chi_squared(evs)};

      board.change_left_prob(i,
                             board.get_left_prob(i) + consts::derivative_step);
      calculate_evs(evs, board);
      double chi_squared2{calculate_chi_squared(evs)};

      double derivative =
          (chi_squared2 - chi_squared1) / consts::derivative_step;
      board.change_left_prob(i, board.get_left_prob(i) -
                                    consts::derivative_step -
                                    consts::descent_step * derivative);
      std::cout << "--- " << std::setw(8) << board.get_left_prob(i) << " ---\n";
    }
  }

  while (true) {
    std::cout << "Enter the number of balls to drop on the galton board:\n";
    int n{};

    if (!(std::cin >> n)) {
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
