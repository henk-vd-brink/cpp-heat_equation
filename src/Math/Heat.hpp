#ifndef HEAT_HPP
#define HEAT_HPP
#define _USE_MATH_DEFINES

#include <math.h>
#include "Tensors/Tensors.hpp"

template <int nDim, typename T>
class Heat
{
public:
    T alpha;         // Diffusion coefficient
    T dt;            // Time step
    int nGridPoints; // Number of gridpoints

    Vector<T> initialCondition;

    Heat() : alpha(0), dt(0), nGridPoints(0)
    {
    }

    Heat(T alpha, T dt, const int &nGridPoints) : alpha(alpha), dt(dt), nGridPoints(nGridPoints)
    {
    }

    void setInitialCondition()
    {
        initialCondition = initial(nGridPoints, pow(nGridPoints, nDim));
    }

    static Vector<T> initial(int a_nGridPoints, int size)
    {
        Vector<T> temp(size);
        for (auto i = 0; i < size; i++)
        {
            temp.data[i] = sin(M_PI * (1 + (i / a_nGridPoints)) / (a_nGridPoints + 1));
        }
        temp = Heat<nDim - 1, T>::initial(a_nGridPoints, size) * temp;
        return temp;
    }
};

template <>
Vector<double> Heat<1, double>::initial(int a_nGridPoints, int size)
{
    Vector<double> result(size);
    for (int i = 0; i < size; i++)
    {
        result.data[i] = sin(M_PI * (1 + i % a_nGridPoints) / (a_nGridPoints + 1));
    }
    return result;
}

#endif // HEAT_HPP