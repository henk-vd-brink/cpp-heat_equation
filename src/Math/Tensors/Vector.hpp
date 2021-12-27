#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <math.h>

template <typename T>
class Vector
{
public:
    int length;
    T *data;

    Vector() : length(0), data(nullptr)
    {
    }

    Vector(int length) : length(length), data(new T[length])
    {
    }

    Vector(const Vector &other) : Vector(other.length)
    {
        for (auto i = 0; i < other.length; i++)
        {
            data[i] = other.data[i];
        }
    }

    Vector(std::initializer_list<double> list) : Vector((int)list.size())
    {
        std::uninitialized_copy(list.begin(), list.end(), data);
    }

    // + operator
    Vector<T> operator+(const Vector<T> &other) const
    {
        if (length != other.length)
        {
            throw "Vectors have different nDim";
        };

        Vector<T> temp(other.length);

        for (int i = 0; i < this->length; i++)
        {
            temp.data[i] = this->data[i] + other.data[i];
        };
        return temp;
    }

    // - operator
    Vector<T> operator-(const Vector<T> &other) const
    {
        if (length != other.length)
        {
            throw "Vectors have different nDim";
        };

        Vector<T> temp(other.length);

        for (int i = 0; i < this->length; i++)
        {
            temp.data[i] = this->data[i] - other.data[i];
        };
        return temp;
    }

    // * operator: elementwise multiplication
    Vector<T> operator*(const Vector<T> &other) const
    {
        if (length != other.length)
        {
            throw "Vectors have different nDim";
        };

        Vector<T> temp(other.length);

        for (int i = 0; i < this->length; i++)
        {
            temp.data[i] = this->data[i] * other.data[i];
        };
        return temp;
    }

    // * operator: scalar multiplication
    template <typename S>
    Vector<T> operator*(S value) const
    {
        Vector<T> temp(this->length);
        for (int i = 0; i < this->length; i++)
        {
            temp.data[i] = value * this->data[i];
        };
        return temp;
    }

    // print the vector
    void print()
    {
        for (int i = 0; i < this->length; i++)
        {
            if (i == 0)
            {
                std::cout << "[" << this->data[i] << ", ";
            }
            else if (i == this->length - 1)
            {
                std::cout << this->data[i] << "]" << std::endl;
            }
            else
            {
                std::cout << this->data[i] << ", ";
            }
        }
    }
};

template <typename T>
T dot(const Vector<T> &lhs, const Vector<T> &rhs)
{
    if (lhs.length != rhs.length)
    {
        throw "Vectors have different nDim";
    }
    T temp = 0;
    for (int i = 0; i < lhs.length; i++)
    {
        temp += lhs.data[i] * rhs.data[i];
    }
    return temp;
}

template <typename T>
T norm(const Vector<T> &vector)
{
    if (vector.length == 0)
    {
        return 0;
    }

    return pow(dot(vector, vector), 0.5);
}

#endif // VECTOR_HPP