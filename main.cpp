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
                    //cout << a.M[j][k]<< endl;
                }
            }
            if(j != i)
                b[j] -= (x / a.M[i][i]) * b[i];
            //cout << b[j] << endl;
        }
    }
    //cout << a;
    for(auto i : b){ if(!isnan(i))cout << i << " "; else{ cout << "System doesn't have the solution" return 0;}}
    cout << endl;
    //return b;
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
    int n, m;
    cin >> n >> m;
    vector<vector<double>> V(n, vector<double>(m));
    vector<double> ans(n);
    for(int i = 0;i < n;i++){ for(int j = 0;j < m;j++) cin >> V[i][j]; cin >> ans[i];}
    Matrix<double> b(V);
    gauss(b, ans);
    return 0;
}
