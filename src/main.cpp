#include <iostream>
#include <initializer_list>
#include <memory>
#include <exception>
#include <typeinfo>
#include "Math/Math.hpp"

int main()
{

    int nGridPoints = 5;
    Heat<1, double> heat(0.3125, 0.1, nGridPoints);

    Vector<double> solution = heat.solve(0.5);
    // std::cout << solution.length << std::endl;
    solution.print();

    // Vector<double>
    //     v1({1, 2});
    // Vector<double> v2(v1.length);

    // Matrix<double> m;
    // for (int i = 0; i < 2; i++)
    // {
    //     m.mat[{i, i}] = 1;
    // }

    // std::cout << conjugateGradient<double>(m, v1, v1, 0.1, 100) << std::endl;

    return 0;
}