#pragma once
#include <vector>

class Matrix {
    public:
       
    explicit Matrix(const std::vector < std::vector<double> >& a);
    
    ~Matrix() = default;
    
  	Matrix(size_t num_rows, size_t num_cols);
  
    Matrix operator* (const Matrix &rhs) const;
  
  	size_t rows() const;

  	size_t cols() const;
  	
  	static Matrix identity (size_t rows);

    double at(size_t a, size_t b) const;

    private:
    std::vector < std::vector<double> > value;
};
          
