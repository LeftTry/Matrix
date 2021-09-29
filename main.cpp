#include <iostream>
#include "Matrix.h"
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    Matrix<int> a(n, m);
    vector<vector<int>> v(n, vector<int> (m));
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> v[i][j];
    Matrix<int> b(v);
    Matrix<int> c(n, m), at(n, m);
    a = a + b;
    at = a.trans();
    c = at * b;
    cout << c;
    return 0;
}
