#include <iostream>
#include <initializer_list>
#include <memory>
#include <exception>
#include <typeinfo>
#include "Math/Tensors/Tensor.hpp"

int main()
{
    Vector<double> v1({1, 2});
    Vector<double> v2(v1.length);

    Matrix<double> m;

    for (int i = 0; i < 2; i++)
    {
        m.mat[{i, i}] = 10;
    }

    v2 = m * v1;

    v2.print();

    return 0;
}