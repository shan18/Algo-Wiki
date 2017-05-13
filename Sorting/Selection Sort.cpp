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
	
	for(int i=1; i<n-1; i++) {
		int min = a[i];
		int index = i;
		for(int j=i+1; j<n; j++) {
			if(a[j] < min) {
				min = a[j];
				index = j;
			}
		}
		if(a[i-1]>min) {
			int t = a[i-1];
			a[i-1] = a[index];
			a[index] = t;
		}
	}

	cout << "The sorted array is: ";
	for(int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}