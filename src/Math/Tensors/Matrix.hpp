#ifndef MATRIX_HPP
#define MATRIX_HPP

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

    Matrix() : nRows(0), nColumns(0)
    {
    }

    Matrix(int num1, int num2) : nRows(num1), nColumns(num2)
    {
    }
};

#endif // MATRIX_HPP