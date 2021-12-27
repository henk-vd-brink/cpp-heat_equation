#include <iostream>
#include <fstream>
#include <initializer_list>
#include <memory>
#include <exception>
#include <typeinfo>
#include "Math/Math.hpp"

int nGridPoints = 100;
const int nDim = 1;
float tMax = 1;

void writeVectorToFile(Vector<double> &vector, const std::string &fileName)
{
    std::ofstream file(fileName);
    if (file.is_open())
    {
        for (int i = 0; i < vector.length; i++)
        {
            file << vector.data[i] << "\n";
        }
        file.close();
    }
    else
    {
        std::cout << "Could not open file" << std::endl;
    }
}

int main()
{
    Heat<nDim, double> *heat = new Heat<nDim, double>(0.3125, 0.01, nGridPoints);

    heat->setInitialCondition();

    // Solve the equation exact
    ExactSolver<nDim, double> exactSolver(heat);
    Vector<double> exactResult = exactSolver.solve(tMax);
    // exactResult.print();

    // Solve the equation approximately using the CG solver
    CGSolver<nDim, double> cgSolver(heat);
    Vector<double> cgResult = cgSolver.solve(tMax);
    // cgResult.print();

    // Write solutions to files -> ./data/cgSolution.txt & ./data/exactSolution.txt
    writeVectorToFile(exactResult, "./data/exactSolution.txt");
    writeVectorToFile(cgResult, "./data/cgSolution.txt");

    // Calculate error
    Vector<double> temp = exactResult - cgResult;
    std::cout << "Calculated error: " << dot(temp, temp) / temp.length << std::endl;

    return 0;
}