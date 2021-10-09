#include <iostream>
#include "Matrix.h"
#include <vector>
#include "Gauss.cpp"

using namespace std;

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
