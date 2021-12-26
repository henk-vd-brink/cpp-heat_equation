#ifndef BASESOLVER_HPP
#define BASESOLVER_HPP
#define _USE_MATH_DEFINES

#include "../Tensors/Tensor.hpp"

template <int nDim, typename T>
class BaseSolver:
{
public:
    T alpha;
    T dt;
    int nGridPoints;

    BaseSolver() : alpha(0), dt(0), nGridPoints(0)
    {
    }

    BaseSolver(T alpha, T dt, const int &nGridPoints) : alpha(alpha), dt(dt), nGridPoints(nGridPoints)
    {
    }

    virtual Vector<T> solve(T t) const = 0;
    virtual static Vector<T> initial() = 0;
};

#endif // BASESOLVER_HPP
