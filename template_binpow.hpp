#pragma once

#include "struct_matrix.hpp"

template<typename T> T identity(const T& a) {
  return T(1);
}

template<> Matrix identity<> (const Matrix& a) {
  return Matrix::identity(a.rows());
}

template <typename T> T binpow(const T& a, unsigned int n) {
    if (n == 0)
      return identity(a);
    if (n % 2 == 1)
        return binpow(a, n-1)*a;
    else {
        T b = binpow(a, n/2);
        return b*b;
    }
}