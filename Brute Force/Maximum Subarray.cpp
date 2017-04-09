#include <bits/stdc++.h>
using namespace std;

struct max_arr {
	int start;
	int end;
	int sum;
};

max_arr find_max_subarray(int arr[], int low, int high) {
	max_arr max_subarray;

	int sum = arr[low];

	for (int i = low; i <= high; i++) {
		int current_sum = 0;
		for (int j = i; j <= high; j++) {
			current_sum += arr[j];
			if (sum < current_sum) {
				sum = current_sum;
				max_subarray.sum = sum;
				max_subarray.start = i;
				max_subarray.end = j;
			}
		}
	}

	return max_subarray;
}


int main() {
	int size;
	cout << "Enter the size of array: ";
	cin >> size;

	int arr[size];
	cout << "Enter the array elements: ";
	for (int i = 0; i < size; ++i)
		cin >> arr[i];

	max_arr max_subarray = find_max_subarray(arr, 0, size - 1);

	cout << "start index = " << max_subarray.start << endl;
	cout << "end index = " << max_subarray.end << endl;
	cout << "sum = " << max_subarray.sum << endl;
}