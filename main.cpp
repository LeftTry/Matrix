#include <iostream>
#include "Matrix.h"
#include <vector>
#include "Gauss.cpp"
#include "fstream"
#include <string>

using namespace std;

int main() {
    //ifstream fin("input.txt");
    int k, i = 1;
    string s;
    //getline(fin, s);
    //k = atoi( s.c_str() );
    k = 1;
    while(k != 0) {
        int n, m;
        //getline(fin, s);
        cin >> n >> m;
        vector<vector<double>> V(n, vector<double>(m));
        vector<double> ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> V[i][j];
            cin >> ans[i];
        }
        Matrix<double> b(V);
        cout << "Case#" << i << ":" << endl;
        if (n != m)
            non_square_gauss(b, ans);
        else
            gauss(b, ans);
        k--;
        i++;
    }
    return 0;
}
