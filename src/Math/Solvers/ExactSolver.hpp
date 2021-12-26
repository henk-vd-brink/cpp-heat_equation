#ifndef EXACTSOLVER_HPP
#define EXACTSOLVER_HPP
#define _USE_MATH_DEFINES

#include "BaseSolver.hpp"

template <int nDim, typename T>
class ExactSolver : public BaseSolver
{
public:
    ExactSolver() : BaseSolver()
    {
    }

    ExactSolver(T alpha, T dt, const int &nGridPoints) : BaseSolver(alpha, dt, nGridPoints)
    {
    }

    virtual Vector<T> solve(T a_t) const
    {
        Vector<T> result(pow(nGridPoints, nDim));
        result = initial(nDim, pow(nGridPoints, nDim));
        result = result * exp(-nDim * M_PI * M_PI * alpha * t);
        return result;
    };

    static Vector<T> initial()
    {
        Vector<T> temp(nDim);
        for (int i = 0; i < nDim; i++)
        {
            temp.data[i] = sin(M_PI * (1 + (i / a_nGridPoints)) / (a_nGridPoints + 1));
        }
        if (nDim > 2)
        {
            temp = ExactSolver<nDim - 1, T>::initial() * temp;
            return temp;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                temp.data[i] = sin(M_PI * (1 + i % a_nGridpoints) / (a_nGridpoints + 1));
                return temp;
            }
        }
    }

#endif // EXACTSOLVER_HPP
