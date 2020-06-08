#include "struct_matrix.hpp"
#include <vector>

Matrix::Matrix(const std::vector < std::vector<double> >& a): value(a)
{};

Matrix::Matrix(std::size_t num_rows, std::size_t num_cols)
   : value(num_rows, std::vector<double>(num_cols, 0))
{};

Matrix Matrix::operator* (const Matrix &rhs) const {
    std::size_t num_rows = value.size();
    std::size_t num_cols = rhs.value[0].size();
    std::size_t num_rows_rhs = rhs.value.size();
    Matrix ans(num_rows, num_cols);
    for (std::size_t row = 0; row < num_rows; ++row)
    {
        for (std::size_t col = 0; col < num_cols; ++col)
        {
            for (std::size_t row_rhs = 0; row_rhs < num_rows_rhs ; ++row_rhs)
                ans.value[row][col] += this->value[row][row_rhs] * rhs.value[row_rhs][col];
        }
    }
    return ans; 
};

std::size_t Matrix::rows() const
{
    return this->value.size();
};
std::size_t Matrix::cols() const
{
    if (this->rows() != 0)
        return this->value[0].size();
    else 
        return 0;
};

Matrix Matrix::identity (std::size_t rows)
{
    Matrix elementary(rows, rows);
    for (std::size_t row = 0; row < rows; ++row)
    {
        for (std::size_t col = 0; col < rows; ++col)
        {
        if (row == col)
            elementary.value[row][col] = 1;
        else
            elementary.value[row][col] = 0;
        }
    }
    return elementary;
};
 
double Matrix::at(std::size_t a, std::size_t b) const
{
    return value[a][b];
};