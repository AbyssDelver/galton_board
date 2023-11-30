#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include <string>
#include <vector>
// Constants file
namespace consts {
// Initial probability of going left vector
// Size: board hight + 1
const std::vector<double> init_prob_left = {0.8, 0.8, 1., 0.6, 0.8, 1., 0.8,
                                            0.5, 1.,  1., 0.7, 1.,  0.8};
// Wanted ev vector
// Size: board width
const std::vector<double> wanted_ev = {0.067, 0.067, 0.067, 0.067, 0.067,
                                       0.067, 0.067, 0.067, 0.067, 0.067,
                                       0.067, 0.067, 0.067, 0.067, 0.067};
// peg file name
const std::string file_name{"pegs.txt"};

constexpr double derivative_step{0.0001};
constexpr double descent_step{0.1};
constexpr int descent_iterations{50};
// number of times the init vector gets randomly generated
constexpr double init_generation_size{100};
}  // namespace consts

#endif