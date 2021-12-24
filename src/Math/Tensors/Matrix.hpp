#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector.hpp"
#include <map>
#include <array>

template <typename T>
class Matrix
{
public:
    const int nRows;
    const int nColumns;

    typedef std::map<std::array<int, 2>, T> sparse;
    sparse mat;

    Matrix() : nColumns(0), nRows(0)
    {
    }

    Matrix(int num1, int num2) : nColumns(num1), nRows(num2)
    {
    }
};

#endif // MATRIX_HPP