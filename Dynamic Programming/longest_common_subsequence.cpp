#include <bits/stdc++.h>
using namespace std;

int c[1000][1000];
char b[1000][1000];

void print_lcs(string X, int i, int j) {
    if (i == -1 || j == -1)
        return;
    if (b[i][j] == 'd') {
        print_lcs(X, i-1, j-1);
        cout << X[i];
    } else if (b[i][j] == 'u')
        print_lcs(X, i-1, j);
    else
        print_lcs(X, i, j-1);
}

void lcs_length(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    for (int i = 1; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= n; j++)
        c[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i-1][j-1] = 'd';
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i-1][j-1] = 'u';
            } else {
                c[i][j] = c[i][j-1];
                b[i-1][j-1] = 'l';
            }
        }
    }

    cout << "LCS length: " << c[m][n] << endl;
    cout << "LCS: ";
    print_lcs(X, m-1, n-1);
    cout << endl;
}

int main() {
    string X, Y;
    cout << "Enter first sequence: ";
    cin >> X;
    cout << "Enter second sequence: ";
    cin >> Y;

    lcs_length(X, Y);
}
