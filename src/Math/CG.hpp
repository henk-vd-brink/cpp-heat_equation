#ifndef CG_HPP
#define CG_HPP

#include "Tensors/Tensor.hpp"

template <typename T>
int conjugateGradient(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, int maxIter)
{
    int nDim = b.length;
    Vector<T> p(nDim);
    Vector<T> r(nDim);
    Vector<T> rNew(nDim);

    r = b - A * x;
    x.print();
    b.print();
    int k = 0;
    return 1;

    // for (int i = 0; i < maxIter; i++)
    // {
    //     double l_alpha = dot(r, r) / dot(A * p, p);
    //     x = x + p * l_alpha;
    //     rNew = r - A * p * l_alpha;

    //     if (norm(rNew) < tol)
    //     {
    //         break;
    //     }

    //     double beta = norm(rNew) / norm(r);
    //     p = rNew + p * beta;
    //     r = std::move(rNew);
    //     k++;
    // }

    // if (k < maxIter)
    // {
    //     return k;
    // }
    // else
    // {
    //     return -1;
    // }
};

#endif // CG_HPP