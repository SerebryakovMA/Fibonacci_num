#pragma once

#include "struct_matrix.hpp"

template<typename T> T identity(const T& a) {
  return T(1);
}

template<> Matrix identity<> (const Matrix& a) {
  return Matrix::identity(a.rows());
}

template <typename T, unsigned int n> T binpow(const T& a) {
    if constexpr (n == 0)
      return identity(a);
    if constexpr (n % 2 == 1)
        return binpow<n-1>(a) * a;
    else {
        T b = binpow<n/2>(a);
        return b*b;
    }
}