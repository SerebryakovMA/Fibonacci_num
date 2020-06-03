#include <iostream>
#include <vector>
#include <cassert>

class Matrix {
    public:
    std::vector < std::vector<double> > value;
    Matrix(std::vector < std::vector<double> > a): value(a)
    {}
    Matrix matrix_composition (std::vector< std::vector<double> > a, const std::vector< std::vector<double> > b){//composition of matrices
        size_t num_rows = a.size();
        size_t num_cols = b[0].size();
        size_t num_rows_b = b.size();
        std::vector< std::vector<double> > ans;
        assert(num_rows == num_cols);
        for (size_t row = 0; row < num_rows; ++row)
        {
            for (size_t col = 0; col < num_cols; ++col)
            {
                for (size_t row_b; row_b < num_rows_b ; ++row_b)
                    ans[row][col] += a[row][row_b] * b[row_b][col];
            }
        }
        return ans; 
    }
    Matrix operator* (Matrix a){
        return matrix_composition();
    }   
    std::vector < std::vector<double> > binpow(std::vector < std::vector<double> > a, int n){  //binary powering for matrix
        assert(a.size() == a[0].size());
        if (n == 0){
            for (size_t row = 0; row < a.size(); ++row)
            {
                for (size_t col = 0; col < a.size(); ++col)
                    {
                        if (row == col)
                            a[row][col] = 1;
                        else
                            a[row][col] = 0;
                    }
            }
            return a;
        }   
        if (n % 2 == 1)
            return matrix_composition(binpow(a, n-1), a);
        else {
            std::vector < std::vector<double> > b = binpow(a, n/2);
            return matrix_composition(b,b);
        }

    }
    /*std::vector<int> get_matrix(std::vector<int> m){
        return m;
    }*/
    void set_values(std::vector<int> p){
        initial_matrix = p;
    }
    private:
    std::vector<int> initial_matrix;
};