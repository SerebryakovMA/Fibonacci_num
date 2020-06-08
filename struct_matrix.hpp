#pragma once
#include <vector>

class Matrix {
    public:
       
    explicit Matrix(const std::vector < std::vector<std::size_t> >& a);
    
    ~Matrix() = default;
    
  	Matrix(std::size_t num_rows, std::size_t num_cols);
  
    Matrix operator* (const Matrix &rhs) const;
  
  	std::size_t rows() const;

  	std::size_t cols() const;
  	
  	static Matrix identity (size_t rows);

    std::size_t at(std::size_t a, std::size_t b) const;

    private:
    std::vector < std::vector<std::size_t> > value;
};
          
