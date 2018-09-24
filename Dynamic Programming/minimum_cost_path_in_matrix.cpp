/* Minimum cost path
 * Given a matrix, find the minimum cost that is required to traverse from upper left corner to bottom right corner
 * provided that we can move only downwards or towards right.
*/

#include <bits/stdc++.h>
using namespace std;


vector< vector<int> > min_cost_path(vector< vector<int> > a, int n, int m) {
    vector< vector<int> > min_cost_matrix(n, vector<int>(m));

    min_cost_matrix[0][0] = a[0][0];
    for(int j = 1; j < m; j++)
        min_cost_matrix[0][j] = min_cost_matrix[0][j-1] + a[0][j];
    for(int i = 1; i < n; i++)
        min_cost_matrix[i][0] = min_cost_matrix[i-1][0] + a[i][0];
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++)
            min_cost_matrix[i][j] = a[i][j] + min(min_cost_matrix[i-1][j], min_cost_matrix[i][j-1]);
    }

    return min_cost_matrix;
}

int main() {
    int n, m;  // Size of matrix - n x m
    cin >> n >> m;
    
    vector< vector<int> > a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    
    vector< vector<int> > min_cost_matrix = min_cost_path(a, n, m);
    cout << "Cost: " << min_cost_matrix[n-1][m-1] << endl;
}
