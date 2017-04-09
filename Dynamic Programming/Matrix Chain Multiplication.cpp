#include <bits/stdc++.h>
using namespace std;


int m[1000][1000];
int s[1000][1000];


void matrix_chain_order(int p[], int n) {
	for (int i = 0; i < n; i++)
		m[i][i] = 0;
	for (int l = 1; l < n; l++) {
		for (int i = 0; i < n-l; i++) {
			int j = i + l;
			m[i][j] = 10000000;
			for (int k = i; k < j; k++) {
				int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void print_optimal_parens(int i, int j) {
	if (i == j)
		cout << "A" << i << " ";
	else {
		cout << "( ";
		print_optimal_parens(i, s[i][j]);
		print_optimal_parens(s[i][j] + 1, j);
		cout << ") ";
	}
}

int main() {

	int n;
	cout << "Enter the number of matrices in chain: ";
	cin >> n;

	int p[n + 1];

	cout << "Enter the dimensions of " << n 
	<< " matrices. The dimensions of a matrix should be separated by a space." 
	<< endl;

	int a, b;
	for (int i = 0; i < n; i++) {
		cout << "Matrix " << i+1 << ": ";
		cin >> a >> b;
		p[i] = a;
	}
	p[n] = b;

	matrix_chain_order(p, n);
	cout << "The minimum cost of multiplication: " 
	<< m[0][n-1] << endl;

	cout << "Multiplication sequence: ";
	print_optimal_parens(0, n-1);
	cout << endl;
}