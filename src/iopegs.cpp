#include "iopegs.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

#include "board.hpp"

namespace galton {

matrix& read_pegs(matrix& pegs, std::string file_name) {
  std::ifstream file{file_name};

  if (!file) {
    throw std::runtime_error("unable to open file");
  }

  char ch;
  pegs.push_back({});
  size_t row{0};

  while (file.get(ch)) {
    switch (ch) {
      case '.':
        pegs[row].push_back(0);
        break;
      case '*':
        pegs[row].push_back(1);
        break;
      case '\n':
        pegs.push_back({});
        ++row;
        break;
      default:
        break;
    }
  }
  return pegs;
}

void print_pegs(const matrix& pegs) {
  for (auto& row : pegs) {
    if (row.size() % 2 == 0) {
      std::cout << ' ';
    }

    for (auto column : row) {
      if (column == 1) {
        std::cout << '*' << ' ';
      }

      if (column == 0) {
        std::cout << '.' << ' ';
      }

      if (column == -1) {
        std::cout << '0' << ' ';
      }
    }
    std::cout << '\n';
  }
}
}  // namespace galton