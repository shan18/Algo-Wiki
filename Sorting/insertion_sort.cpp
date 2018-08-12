#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout << "Enter the size of array: ";
	cin >> n;
	
	int a[n];
	cout << "Enter the array to be sorted: ";
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	for(int i=1; i<n; i++) {
		for(int j=i-1; j>=0; j--) {
			if(a[j]>a[j+1]) {
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}

	cout << "The sorted array is: ";
	for(int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}