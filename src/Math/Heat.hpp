#ifndef HEAT_HPP
#define HEAT_HPP
#define _USE_MATH_DEFINES

#include "CG.hpp"
#include <math.h>

template <int nDim, typename T>
class Heat
{
    public:
        T alpha;             // Diffusion coefficient
        T dt;                // Time step
        int nGridPoints;     // Number of gridpoints
        Matrix<T> M;         // Sparse matrix attribute

    Heat(): alpha(0), dt(0), nGridPoints(0)
    {
    }

    Heat(T alpha, T dt, const int &nGridPoints)
    {
        generateMatrix(pow(nGridPoints, nDim), alpha, dt, nGridPoints, M)
    }

    static void generateMatrix(int column, T alpha, T dt, int nGridPoints, Matrix<T> &M)
    {
        int translation = pow(nGridPoints, nDim);
        for (auto j = 0; j < column; j++)
        {
            M.mat[{j,j}] += 2 * alpha * dt * pow(nGridPoints + 1, 2);
            if ((j + translation) < pow(nGridPoints, nDim))
            {
                M.mat[{j, j + translation}] += -alpha * dt * pow(nGridPoints + 1, 2);
                M.mat[{j + translation, j}] += -alpha * dt * pow(nGridPoints + 1, 2);
            }
        }
        Heat<nDim -1, T>::generateMatrix(column, alpha, dt, nGridPoints, M);
    }

    Vector<T> exact(T t) const
    {
        Vector<T> result(pow(nGridPoints, nDim));
        result = initial(nDim, pow(nGridPoints, nDim));
        result = result * exp(-n * M_PI*M_PI*alpha*t);
        return result
    }

}