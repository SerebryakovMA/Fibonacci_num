#include "struct_matrix.hpp"
#include <vector>

Matrix::Matrix(const std::vector < std::vector<double> >& a): value(a)
{};

Matrix::Matrix(size_t num_rows, size_t num_cols)
   : value(num_rows, std::vector<double>(num_cols, 0))
{};

Matrix Matrix::operator* (const Matrix &rhs) const {
    size_t num_rows = value.size();
    size_t num_cols = rhs.value[0].size();
    size_t num_rows_rhs = rhs.value.size();
    Matrix ans(num_rows, num_cols);
    for (size_t row = 0; row < num_rows; ++row)
    {
        for (size_t col = 0; col < num_cols; ++col)
        {
            for (size_t row_rhs; row_rhs < num_rows_rhs ; ++row_rhs)
                ans.value[row][col] += this->value[row][row_rhs] * rhs.value[row_rhs][col];
        }
    }
    return ans; 
};   
