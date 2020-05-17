#include <iostream>
#include <vector>
#include "matrix.hpp"

int main(){
    Matrix matrix;

    std::vector<int> initial_matrix;
    std::vector<int> matrix_comp;

    std::vector<int> p = {0, 1 , 1, 1};
    matrix.set_values(p);
    int n;
    std::cin >> n;
    int F_n;
    F_n = matrix.get_matrix(matrix.binpow(p, n))[1] + matrix.get_matrix(matrix.binpow(p, n))[2];
    std::cout << F_n <<std::endl;
    return 0;
}