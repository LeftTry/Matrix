#include <iostream>
#include "Matrix.h"
#include <vector>
#include "Gauss.cpp"

using namespace std;

void gauss(Matrix<double>& a, vector<double> &b){
    for(int i = 0;i < a.getn();i++){
        double c = a.M[i][i];
        for(int j = 0;j < a.getn();j++){
            a.M[i][j] /= c;
        }
        b[i] /= c;
        for(int j = 0;j < a.getn();j++){
            double x = a.M[j][i];
            for(int k = 0;k < a.getn();k++){
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
    for(int i = 0;i < a.getn();i++){
        if(i >= a.getm()) break;
        for(int j = 0;j < a.getn();j++){
            double x = a.M[j][i];
            for(int k = 0;k < a.getm();k++){
                if(j != i) {
                    a.M[j][k] -= (x / a.M[i][i]) * a.M[i][k];
                }
            }
            if(j != i)
                b[j] -= (x / a.M[i][i]) * b[i];
        }
    }
    for(int i = 0;i < a.getn();i++){
        for(int j = 0;j < a.getm();j++){
            if(a.M[i][j] != 0)
                break;
            if(j == a.getm() - 1 && a.M[i][j] == 0 && b[i] != 0) {
                cout << "System is inconsistent" << endl;
                return;
            }
        }
    }
    cout << "Free variables: ";
    for(int k = a.getn() - 1 + 1;k < a.getm();k++)
        cout << "x" << k + 1 << " ";
    cout << endl;
    for(int i = a.getn() - 1;i >= 0;i--){
        cout << "x" << i + 1 << " = " << b[i] / a.M[i][i] << " - ";
        for(int k = i + 1;k < a.getm();k++){
            double x = a.M[i][k] / a.M[i][i];
            if(k + 1 != a.getm()) {
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<double>> V(n, vector<double>(m));
    vector<double> ans(n);
    for(int i = 0;i < n;i++){ for(int j = 0;j < m;j++) cin >> V[i][j]; cin >> ans[i];}
    Matrix<double> b(V);
    if(n != m)
        non_square_gauss(b, ans);
    else
        gauss(b, ans);
    return 0;
}
