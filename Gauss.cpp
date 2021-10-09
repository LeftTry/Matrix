#include <iostream>
#include "Matrix.h"
#include <vector>
#include <fstream>

using namespace std;

//ofstream fout("output.txt");

void gauss(Matrix<double>& a, vector<double> &b){
    for(int i = 0;i < a.getN(); i++){
        double c = a.M[i][i];
        for(int j = 0;j < a.getN(); j++){
            a.M[i][j] /= c;
        }
        b[i] /= c;
        for(int j = 0;j < a.getN(); j++){
            double x = a.M[j][i];
            for(int k = 0;k < a.getN(); k++){
                if(j != i) {
                    a.M[j][k] -= (x / a.M[i][i]) * a.M[i][k];
                }
            }
            if(j != i)
                b[j] -= (x / a.M[i][i]) * b[i];
        }
    }
    for(auto i : b){ if(!isnan(i))cout << i << " "; else{ cout << "System is inconsistent" << endl; break;}}
    cout << endl;
}

void non_square_gauss(Matrix<double>& a, vector<double> &b){
    for(int i = 0;i < a.getN(); i++){
        if(i >= a.getM()) break;
        for(int j = 0;j < a.getN(); j++){
            double x = a.M[j][i];
            for(int k = 0;k < a.getM(); k++){
                if(j != i) {
                    a.M[j][k] -= (x / a.M[i][i]) * a.M[i][k];
                }
            }
            if(j != i)
                b[j] -= (x / a.M[i][i]) * b[i];
        }
    }
    for(int i = 0;i < a.getN(); i++){
        for(int j = 0;j < a.getM(); j++){
            if(a.M[i][j] != 0)
                break;
            if(j == a.getM() - 1 && a.M[i][j] == 0 && b[i] != 0) {
                cout << "System is inconsistent" << endl;
                return;
            }
        }
    }
    cout << "Free variables: ";
    for(int k = a.getN() - 1 + 1; k < a.getM(); k++)
        cout << "x" << k + 1 << " ";
    cout << endl;
    for(int i = a.getN() - 1; i >= 0; i--){
        cout << "x" << i + 1 << " = " << b[i] / a.M[i][i] << " - ";
        for(int k = i + 1;k < a.getM(); k++){
            double x = a.M[i][k] / a.M[i][i];
            if(k + 1 != a.getM()) {
                if(x != 0 && x != 1)
                    cout << x << "x" << k + 1 << " - ";
                if(x == 1)
                    cout << "x" << k + 1 << " - ";
            }
            else{
                if(x != 0 && x != 1)
                    cout << x << "x" << k + 1;
                if(x == 1)
                    cout << "x" << k + 1;
            }
        }
    }
    cout << endl;
}