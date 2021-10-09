#include <iostream>
#include "Matrix.h"
#include <vector>
#include "Gauss.cpp"

using namespace std;

void gauss(Matrix<double> a, vector<double> &b){
    for(int i = 0;i < a.getn();i++){
        int c = a.M[i][i];
        for(int j = 0;j < a.getn();j++){
            a.M[i][j] /= c;
        }
        b[i] /= c;
        for(int j = 0;j < a.getn();j++){
            int x = a.M[j][i];
            for(int k = 0;k < a.getn();k++){
                if(j != i) {
                    a.M[j][k] -= (x / a.M[i][i]) * a.M[i][k];
                }
            }
            if(j != i)
                b[j] -= (x / a.M[i][i]) * b[i];
        }
    }
    for(auto i : b){ if(!isnan(i))cout << i << " "; else{ cout << "System doesn't have the solution" << endl; break;}}
    cout << endl;
}

void non_square_gauss(Matrix<double> a, vector<double> &b){
    //cout << "ok" << endl;
    for(int i = 0;i < a.getn();i++){
        //for(int j = 0;j < a.getn();j++){
            //a.M[i][j] /= a.M[i][i];
        //}
        //b[i] /= a.M[i][i];
        //cout << b[i] << endl;
        if(i >= a.getm()) break;
        for(int j = 0;j < a.getn();j++){
            int x = a.M[j][i];
            for(int k = 0;k < a.getm();k++){
                if(j != i) {
                    a.M[j][k] -= (x / a.M[i][i]) * a.M[i][k];
                    //cout << a.M[j][k]<< endl;
                }
            }
            if(j != i)
                b[j] -= (x / a.M[i][i]) * b[i];
            //cout << b[j] << endl;
        }
    }
    //cout << "ok" << endl;
    for(int i = 0;i < a.getn();i++){
        for(int j = 0;j < a.getm();j++){
            if(a.M[i][j] != 0)
                break;
            //cout << b[i] << endl;
            if(j == a.getm() - 1 && a.M[i][j] == 0 && b[i] != 0) {
                cout << "System is inconsistent" << endl;
                return;
            }
        }
    }
    cout << a;
    for(int i = a.getn() - 1;i >= 0;i--){
        //cout << "ok" << endl;
        cout << "x" << i + 1 << " = " << b[i] / a.M[i][i] << " - ";
        for(int k = i + 1;k < a.getm();k++){
            if(k + 1 != a.getm())
                cout << a.M[i][k] / a.M[i][i] << "x" << k + 1 << " - ";
            else
                cout << a.M[i][k] / a.M[i][i] << "x" << k + 1;
        }
    }
    cout << endl;
}

int main() {
    /*cout << "You need to enter 2 Matrix:" << endl;
    int n, m;
    cin >> n >> m;
    Matrix<int> a(n, m);
    cin >> n >> m;
    vector<vector<int>> V(n, vector<int>(m));
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> V[i][j];
    Matrix<int> b(V);
    int k;
    cin >> k;
    Matrix<int> c(n, m);
    try{
        c = a + b;
        cout << "a + b:" << endl << c << endl;
    }catch(string s){cerr << s << endl;}
    try{
        cout << "(a + b) * b :" << endl << c * b << endl;
    } catch(const char* s) {cerr << s << endl;}
    cout << "k * b:" << endl << b * k << endl;
    cout << "tras(b):" << endl << b.trans() << endl;
    try{
        cout << "pow(b, 2):" << endl << b.pow(2) << endl;
    } catch(const char* s) {cerr << s << endl;}
    try{
        auto d = deter(n, n, b);
        cout << d << endl;
    } catch (const char* s) {cerr << s << endl;}*/
    /*int n, m;
    cin >> n >> m;
    vector<vector<double>> V(n, vector<double>(m));
    vector<double> ans(n);
    for(int i = 0;i < n;i++){ for(int j = 0;j < m;j++) cin >> V[i][j]; cin >> ans[i];}
    Matrix<double> b(V);
    gauss(b, ans);*/
    int n, m;
    cin >> n >> m;
    vector<vector<double>> V(n, vector<double>(m));
    vector<double> ans(n);
    for(int i = 0;i < n;i++){ for(int j = 0;j < m;j++) cin >> V[i][j]; cin >> ans[i];}
    Matrix<double> b(V);
    //Matrix<double> b(n, m);
    //b.M = V;
    non_square_gauss(b, ans);
    return 0;
}
