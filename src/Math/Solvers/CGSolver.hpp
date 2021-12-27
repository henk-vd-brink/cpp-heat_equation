#ifndef CGSOLVER_HPP
#define CGSOLVER_HPP
#define _USE_MATH_DEFINES

#include "../Tensors/Tensors.hpp"

template <int nDim, typename T>
class CGSolver
{
public:
    Heat<nDim, T> *heatObject = nullptr;
    Matrix<T> M;

    CGSolver(Heat<nDim, T> *heat) : heatObject(heat)
    {
        generateMatrix(pow(heat->nGridPoints, nDim), heat->alpha, heat->dt, heat->nGridPoints, M);
    }

    static void generateMatrix(int col, T alpha, T dt, int m, Matrix<T> &M)
    {
        int translation = pow(m, nDim - 1);
        for (auto j = 0; j < col; j++)
        {
            M.mat[{j, j}] += 2 * alpha * dt * pow(m + 1, 2);
            if ((j + translation) < pow(m, nDim))
            {
                M.mat[{j, j + translation}] += -alpha * dt * pow(m + 1, 2);
                M.mat[{j + translation, j}] += -alpha * dt * pow(m + 1, 2);
            }
        }
        CGSolver<nDim - 1, T>::generateMatrix(col, alpha, dt, m, M);
    }

    Vector<T> solve(T t)
    {
        int size = pow(heatObject->nGridPoints, nDim);
        Vector<T> b = heatObject->initialCondition;
        Vector<T> x(b.length);

        for (auto i = 0; i * heatObject->dt < t; i++)
        {
            int k = cg(M, b, x, 1e-25, 100);
            b = x;
            Vector<T> x(b.length);
        }

        return b;
    };

    int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, int maxiter)
    {
        // Temp vectors for cg function
        Vector<T> p(b.length);
        Vector<T> r(b.length);
        Vector<T> rNew(b.length);

        r = b - A * x;
        p = r;
        int k = 0;

        for (int i = 0; i < maxiter; i++)
        {
            double alph = dot(r, r) / dot(A * p, p);
            x = x + p * alph;
            rNew = r - A * p * alph;
            if (dot(rNew, rNew) < tol * tol)
            {
                break;
            }

            double beta = dot(rNew, rNew) / dot(r, r);
            p = rNew + p * beta;
            r = std::move(rNew);
            k++;
        }
        if (k < maxiter)
        {
            return k;
        }
        else
        {
            return -1;
        }
    }
};

template <>
void CGSolver<1, double>::generateMatrix(int col, double alpha, double dt, int m, Matrix<double> &M)
{
    for (auto j = 0; j < col; j++)
    {
        M.mat[{j, j}] += 2 * alpha * dt * pow(m + 1, 2) + 1;
        if (j % m != m - 1)
        {
            M.mat[{j, j + 1}] += -alpha * dt * pow(m + 1, 2);
            M.mat[{j + 1, j}] += -alpha * dt * pow(m + 1, 2);
        }
    }
}

#endif // CGSOLVER_HPP