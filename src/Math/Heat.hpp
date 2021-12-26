#ifndef HEAT_HPP
#define HEAT_HPP
#define _USE_MATH_DEFINES

#include <math.h>
#include "Tensors/Tensor.hpp"

template <int nDim, typename T>
class Heat
{
public:
    T alpha;         // Diffusion coefficient
    T dt;            // Time step
    int nGridPoints; // Number of gridpoints
    Matrix<T> M;     // Sparse matrix attribute

    Heat() : alpha(0), dt(0), nGridPoints(0)
    {
    }

    Heat(T alpha, T dt, const int &nGridPoints) : alpha(alpha), dt(dt), nGridPoints(nGridPoints)
    {
        generateMatrix(pow(nGridPoints, nDim), alpha, dt, nGridPoints, M);
    }

    Vector<T> solveExact(T t) const
    {
        std::cout << nGridPoints << "," << nDim << std::endl;
        Vector<T> result(pow(nGridPoints, nDim));
        result = initial(nDim, pow(nGridPoints, nDim));
        result = result * exp(-nDim * M_PI * M_PI * alpha * t);
        return result;
    }

    Vector<T> solve(T t) const
    {
        float tol = 1;
        int maxIter = 10;

        int size = pow(nGridPoints, nDim);
        Vector<T> b = initial(nGridPoints, size);

        struct state
        {
            float t;
            Vector<T> x;
            Matrix<T> m;
        };

        Matrix<T> l_m(10, 10);

        struct state heatState;
        heatState.x = b;
        heatState.m = l_m;

        // struct systemState l_systemState;
        // l_systemState.stateVector = b;
        // l_systemState.stateMatrix = M;

        // l_systemState.stateVector.print();

        // for (auto i = 0; i * dt < t; i++)
        // {
        //     int k = conjugateGradient<T>(systemState, 1e-3, 100);
        //     b = x;
        //     std::cout << k << std::endl;

        //     for (auto i = 0; i < b.length; i++)
        //     {
        //         x.data[i] = 0;
        //     }
        // }
        return b;
    }

    static Vector<T> initial(int a_nGridPoints, int a_size)
    {
        Vector<T> temp(a_size);
        for (auto i = 0; i < a_size; i++)
        {
            temp.data[i] = sin(M_PI * (1 + (i / a_nGridPoints)) / (a_nGridPoints + 1));
        }
        temp = Heat<nDim - 1, T>::initial(a_nGridPoints, a_size) * temp;
        return temp;
    }

    static void generateMatrix(int column, T alpha, T dt, int a_nGridPoints, Matrix<T> &M)
    {
        int translation = pow(a_nGridPoints, nDim - 1);

        for (auto j = 0; j < column; j++)
        {
            M.mat[{j, j}] += 2 * alpha * dt * pow(a_nGridPoints + 1, 2);
            if ((j + translation) < pow(a_nGridPoints, nDim))
            {
                M.mat[{j, j + translation}] += -alpha * dt * pow(a_nGridPoints + 1, 2);
                M.mat[{j + translation, j}] += -alpha * dt * pow(a_nGridPoints + 1, 2);
            }
        }
        Heat<nDim - 1, T>::generateMatrix(column, alpha, dt, a_nGridPoints, M);
    }

    //     void printMatrix()
    //     {
    //         for (auto it = M.mat.begin(); it != M.mat.end(), ++it)
    //         {
    //             std::cout << "i[" << it->first[0] << "," << it->first[1] << "] =" << it->second << std::endl;
    //         }
    //     }
};

template <>
void Heat<1, double>::generateMatrix(int column, double alpha, double dt, int nGridPoints, Matrix<double> &M)
{
    for (auto j = 0; j < column; j++)
    {
        M.mat[{j, j}] += 2 * alpha * dt * pow(nGridPoints + 1, 2) + 1;
        if (j % nGridPoints != nGridPoints - 1)
        {
            M.mat[{j, j + 1}] += -alpha * dt * pow(nGridPoints + 1, 2);
            M.mat[{j + 1, j}] += -alpha * dt * pow(nGridPoints + 1, 2);
        }
    }
}

template <>
Vector<double> Heat<1, double>::initial(int a_nGridpoints, int size)
{
    Vector<double> result(size);
    for (int i = 0; i < size; i++)
    {
        result.data[i] = sin(M_PI * (1 + i % a_nGridpoints) / (a_nGridpoints + 1));
    }
    return result;
}

#endif // HEAT_HPP