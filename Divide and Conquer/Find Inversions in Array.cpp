#include <bits/stdc++.h>
using namespace std;

int merge(int A[], int p, int q, int t) {
	int n1 = q - p + 1;
	int n2 = t - q;
	int l[n1], r[n2];

	int i, j, k, inversions=0;

	for(i=0; i<n1; i++)
		l[i] = A[p+i];
	for(j=0; j<n2; j++)
		r[j] = A[q+1+j];

	for(i = 0, j = 0, k = p; k <= t; k++) {
		if (i == n1) {
            A[k] = r[j++];
        } else if (j == n2) {
            A[k] = l[i++];
        } else if (l[i] <= r[j]) {
            A[k] = l[i++];
        } else {
            A[k] = r[j++];
            inversions += n1 - i;
        }
	}

	return inversions;
}

int merge_sort(int A[], int p, int t) {
	int q;
	if(p < t) {
		int inversions = 0;
		q = (p+t) / 2;
		inversions += merge_sort(A, p, q);
		inversions += merge_sort(A, q+1, t);
		inversions += merge(A, p, q, t);
		return inversions;
	} else
		return 0;
}

int main() {

	int count;
	cout << "Enter size of array: ";
	cin >> count;

	int num[count];
	cout << "Enter the array: ";
	for(int i=0; i<count; i++) {
		cin >> num[i];
	}

	int inversions = merge_sort(num, 0, count-1);
	cout << "Inversions: " << inversions << endl;
}