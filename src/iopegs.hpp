#ifndef IOPEGS_HPP
#define IOPEGS_HPP
#include "board.hpp"

namespace galton {
    matrix& read_pegs(matrix& pegs, const std::string& file_name);
    void print_pegs(const matrix& pegs);
}
#endif