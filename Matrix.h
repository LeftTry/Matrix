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

    template<class Type> friend std::ostream & operator<<(std::ostream&, const Matrix<Type>);
};

template<typename T>
Matrix<T>::Matrix(int _n, int _m) {
    n = _n;
    m = _m;
    M.resize(n);
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
    Matrix<T> c(n, m);
    if(a.n != n || a.m != m) throw "Matrix should be same size";
    else{
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                c.M[i][j] = M[i][j] + a.M[i][j];
    }
    return c;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(int k) {
    Matrix<T> b(n, m);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            b.M[i][j] = M[i][j] * k;
    return b;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& a) {
    if(a.m != n) throw "Matrix's width should be same as other's height";
    else{
        Matrix<T> b(n, a.m);
        for(int j = 0;j < m;j++){
            for(int i = 0;i < a.n;i++){
                T sum = 0;
                for(int k = 0;k < n;k++){
                    sum += M[k][j] * a.M[i][k];
                }
                b.M[i][j] = sum;
            }
        }
        return b;
    }
    return Matrix<T>(0, 0);
}

template<typename T>
Matrix<T> Matrix<T>::trans() {
    Matrix<T> at(n, m);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            at.M[j][i] = M[i][j];
    return at;
}

template<typename T>
Matrix<T> Matrix<T>::pow(int) {
    return &this;
}

template<class Type>
std::ostream &operator<<(std::ostream &out, const Matrix<Type> a) {
    for(int i = 0;i < a.n;i++){
        for(int j = 0;j < a.m;j++) out << a.M[i][j] << " ";
        out << std::endl;
    }
    return out;
}

#endif //MATRIX_MATRIX_H
