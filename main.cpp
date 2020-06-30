#include <iostream>
#include "struct_matrix.hpp"
#include "template_binpow.hpp"

int main() {
    Matrix initial({{0, 1}, {1, 1}});
    unsigned const int n_1 = 9; // F_9 = 34
    unsigned const int n_2 = 34; // F_34 = 5702887
    unsigned const int n_3 = 50; // F_50 = 12586269025
    std::cout << binpow<n_1>(initial).at(1, 1) - binpow<n_1>(initial).at(0, 0) <<std::endl;
    std::cout << binpow<n_2>(initial).at(1, 1) - binpow<n_2>(initial).at(0, 0) <<std::endl;
    std::cout << binpow<n_3>(initial).at(1, 1) - binpow<n_3>(initial).at(0, 0) <<std::endl;
   return 0;
}