/* The following code performs heapsort in c++
 * It uses max heap.
*/


#include <bits/stdc++.h>
using namespace std;


int heap_size = 0;
vector<int> a;

int left(int i) {
	return 2 * i + 1;
}

int right(int i) {
	return 2 * i + 2;
}

void max_heapify(int i) {
	int l = left(i);
	int r = right(i);
	int largest = i;

	if (l < heap_size && a[l] > a[i])
		largest = l;
	if (r < heap_size && a[r] > a[largest])
		largest = r;

	if (largest != i) {
		iter_swap(a.begin()+largest, a.begin()+i);
		max_heapify(largest);
	}
}

void build_max_heap() {
	heap_size = a.size();
	for(int i = (a.size()-2)/2; i >= 0; i--) {
		max_heapify(i);
	}
}

int main() {
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	cout << "Enter the elements in the array: ";
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	build_max_heap();
	for (int i = a.size()-1; i >= 1; i--) {
		iter_swap(a.begin(), a.begin()+i);

		heap_size = heap_size - 1;
		max_heapify(0);
	}

	cout << "The sorted array: ";
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}