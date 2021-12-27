#ifndef EXACTSOLVER_HPP
#define EXACTSOLVER_HPP
#define _USE_MATH_DEFINES

template <int nDim, typename T>
class ExactSolver
{
public:
    Heat<nDim, T> *heatObject = nullptr;

    ExactSolver(Heat<nDim, T> *heat) : heatObject(heat)
    {
    }

    Vector<T> solve(T t)
    {
        T alpha = heatObject->alpha;

        Vector<T> result = heatObject->initialCondition;
        result = result * exp(-nDim * M_PI * M_PI * alpha * t);
        return result;
    };
};

#endif // EXACTSOLVER_HPP
