#ifndef MATRIXVECTORPRODUCT_HPP
#define MATRIXVECTORPRODUCT_HPP

#include "../Vector.hpp"
#include "../Matrix.hpp"

template <typename T>
Vector<T> operator*(const Matrix<T> &lhs, const Vector<T> &rhs)
{
    Vector<T> temp(rhs.length);

    for (auto it = lhs.mat.begin(); it != lhs.mat.end(); it++)
    {
        temp.data[it->first[0]] += it->second * rhs.data[it->first[1]];
    }
    return temp;
}

#endif // MATRIXVECTORPRODUCT_HPP