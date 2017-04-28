#include <bits/stdc++.h>
using namespace std;


int r[10000000];
int s[10000000];

void bottom_up_cut_rod(int p[], int n) {
	r[0] = 0;
	for(int j = 1; j <= n; j++) {
		int q = -1;
		for(int i = 1; i <= j; i++) {
			if (q < p[i] + r[j-i]) {
				q = p[i] + r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	cout << "Maximum revenue: " << r[n] << endl;
}

void print_cut_rod_solution(int p[], int n) {
	bottom_up_cut_rod(p, n);
	cout << "Rod lengths after cutting: ";
	while(n > 0) {
		cout << s[n] << " ";
		n -= s[n];
	}
	cout << endl;
}

int main() {
	int n;
	cout << "Enter the size of the rod: ";
	cin >> n;

	int p[n + 1];
	p[0] = 0;
	for(int i = 1; i <= n; i++) {
		cout << "Price for rod of length " << i << ": ";
		cin >> p[i];
	}

	print_cut_rod_solution(p, n);

	return 0;
}