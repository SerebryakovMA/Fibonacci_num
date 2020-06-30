#include <iostream>
#include "struct_matrix.hpp"
#include "template_binpow.hpp"

int main() // complexity O(log n) arithmetic operations
{
    Matrix initial({{0, 1}, {1, 1}});
    unsigned int n_1 = 9; // F_9 = 34
    unsigned int n_2 = 34; // F_34 = 5702887
    unsigned int n_3 = 50; // F_50 = 12586269025
    std::cout << binpow<n_1>(initial).at(1, 1) - binpow<n_1>(initial).at(0, 0) <<std::endl;
    //std::cout << binpow(initial, n_2).at(1, 1) - binpow(initial, n_2).at(0, 0) <<std::endl;
    //std::cout << binpow(initial, n_3).at(1, 1) - binpow(initial, n_3).at(0, 0) <<std::endl;
    return 0;
}