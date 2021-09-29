#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
#include <cmath>
#include <vector>

template <typename T>
class Matrix{
    int n{}, m{};
    std::vector<std::vector<T>> M;
public:
    Matrix(int n, int m);
    Matrix(std::vector<std::vector<T>>&);

    Matrix<T> operator+(Matrix<T>&);
    Matrix<T> operator*(int);
    Matrix<T> operator*(Matrix<T>&);

    Matrix<T> trans();

    Matrix<T> pow(int);
};

template<typename T>
Matrix<T>::Matrix(int _n, int _m) {
    n = _n;
    m = _m;
    M.resize(n)
    for(int i = 0;i < n;i++) {
        M[i].resize(m);
        for (int j = 0; j < m; j++)
            M[i][j] = 0;
    }
}

template<typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> &_M) {
    M = _M;
    n = _M.size();
    m = _M[0].size();
}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &a) {
    if(a.n != n || a.m != m) throw std::string "Matrix should be same size"
    else{
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                M[i][j] += a.M[i][j];
    }
    return &this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(int k) {
    return &this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& a) {
    return &this;
}

template<typename T>
Matrix<T> Matrix<T>::trans() {
    return &this;
}

template<typename T>
Matrix<T> Matrix<T>::pow(int) {
    return &this;
}

#endif //MATRIX_MATRIX_H
