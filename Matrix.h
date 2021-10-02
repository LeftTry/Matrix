#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

template <typename T>
class Matrix{
    int n{}, m{};
public: std::vector<std::vector<T>> M;
public:
    Matrix(int n, int m);
    Matrix(std::vector<std::vector<T>>&);

    int getn() {return n;}
    int getm() {return m;}

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
    if(a.n != n || a.m != m) throw std::string("Matrix should be same size");
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
    Matrix<T> at(m, n);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            at.M[j][i] = M[i][j];
    return at;
}

template<typename T>
Matrix<T> Matrix<T>::pow(int k) {
    if(m != n) throw "Matrix should be square";
    std::vector<std::vector<T>> V(n, std::vector<T>(m));
    for(int i = 0;i  < n;i++)
        for(int j = 0;j < m;j++){
            if(i == j) V[i][j] = 1;
            else V[i][j] = 0;
        }
    Matrix<T> a(V);
    Matrix<T> b(M);
    int i = 0;
    if(k == 1) return a;
    while(k > 0){
        i++;
        if(k % 2 == 1) a = a * b;
        b = b * b;
        k >>= 1;
    }
    return a;
}

template<class Type>
std::ostream &operator<<(std::ostream &out, const Matrix<Type> a) {
    for(int i = 0;i < a.n;i++){
        for(int j = 0;j < a.m;j++) out << a.M[i][j] << " ";
        out << std::endl;
    }
    return out;
}

template<typename T>
T deter(int fn, int _n, Matrix<T>& a) {
    //if(_n != n) _n = n;
    //if(_n != a.getn() || a.getn() != a.getm()) throw "Matrix should be square";
    T det = 0;
    if(_n == 1) return a.M[0][0];
    if(_n == 2) return (a.M[0][0] * a.M[1][1]) - (a.M[0][1] * a.M[1][0]);
    Matrix<T> temp(fn, fn);
    T s = 1;
    for(int i = 0;i < _n;i++){
        int b = 0, j = 0;
        for(int r = 0;r < _n;r++){
            for(int c = 0;c < _n;c++){
                if(r != 0 && c != i){
                    temp.M[b][j++] = a.M[r][c];
                    if(j == _n - 1) {j = 0; b++;}
                }
            }
        }
        det += s * a.M[0][i] * deter(fn, _n - 1, temp);
        std::cout << temp << std::endl;
        s = -s;
    }
    return det;
}

#endif //MATRIX_MATRIX_H
