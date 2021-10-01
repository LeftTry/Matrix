#include <iostream>
#include "Matrix.h"
#include <vector>

using namespace std;

int main() {
    cout << "You need to enter 2 Matrix:" << endl;
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
    return 0;
}
