#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	bool matrix[n];
	memset(matrix, true, sizeof(matrix));
	for(int i=4; i<=n; i+=2)
		matrix[i] = false;
	
	for(int i=3; i<=sqrt(n); i+=2) {
		if(matrix[i]==true) {
			for(int j=2*i; j<=n; j+=i)
				matrix[j] = false;
		}
	}
	for(int i=2; i<=n; i++) {
		if(matrix[i]==true)
			cout << i << endl;
	}
}