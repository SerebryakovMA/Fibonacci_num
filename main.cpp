#include <iostream>
#include "struct_matrix.hpp"
#include "template_binpow.hpp"

int main()
{
    Matrix initial({{0, 1}, {1, 1}});
    unsigned int n = 12;
    double F_n = binpow(initial, n).at(1, 1);
    std::cout << F_n <<std::endl;
    return 0;
}