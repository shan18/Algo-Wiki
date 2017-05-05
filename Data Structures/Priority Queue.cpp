/* The following code uses C++ to implement a priority queue using a max heap.
 * It is a max priority queue which has the element with the highest key at the front.
*/


#include <bits/stdc++.h>
using namespace std;


vector<int> a;
int heap_size = 0;

int parent(int i) {
	if (i % 2 == 0)
		return i / 2 - 1;
	else
		return i / 2;
}

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

int heap_maximum() {
	if (heap_size < 1) {
		return -1;
	}
	return a[0];
}

int heap_extract_max() {
	if (heap_size < 1) {
		cout << "Heap Underflow!" << endl;
		return -1;
	}
	int max = a[0];
	a[0] = a[heap_size - 1];
	heap_size--;
	max_heapify(0);
	return max;
}

void heap_increase_key(int i, int key) {
	if (key < a[i]) {
		cout << "The new key is smaller than the current key!" << endl;
		return;
	}
	a[i] = key;
	while (i > 0 && a[parent(i)] < a[i]) {
		iter_swap(a.begin()+parent(i), a.begin()+i);
		i = parent(i);
	}
}

void max_heap_insert(int key) {
	if (heap_size < 1) {
		a.push_back(key);
		heap_size++;
		return;
	}
	if (++heap_size > a.size())
		a.push_back(key - 10);	// Can be any value less than the key
	else
		a[heap_size - 1] = key - 10;	// Can be any value less than the key

	heap_increase_key(heap_size - 1, key);
}

void print_heap() {
	cout << "\nPriority Queue: ";
	for (int i = 0; i < heap_size; i++)
		cout << a[i] << " ";
	cout << endl << endl;
}

int main() {
	while (true) {
		cout << "Enter the number of the operation to be performed: " << endl
			 << "1. Insert" << endl
			 << "2. Maximum key" << endl
			 << "3. Extract the element with maximum key" << endl
			 << "4. Increase the key value of an element" << endl
			 << "5. Exit" << endl << endl;
		
		int ch;
		cin >> ch;

		if (ch == 1) {
			int key;
			cout << "Enter the key: ";
			cin >> key;
			max_heap_insert(key);
			print_heap();
		} else if (ch == 2) {
			int m = heap_maximum();
			if (m == -1)
				cout << "Queue is empty\n" << endl;
			else
				cout << m << endl << endl;
		} else if (ch == 3) {
			heap_extract_max();
			print_heap();
		} else if (ch == 4) {
			int i, key;
			cout << "Enter the index of the element: ";
			cin >> i;
			if (i >= a.size()) {
				cout << "Element does not exist!\n" << endl;
				continue;
			}
			cout << "Enter the new key: ";
			cin >> key;
			heap_increase_key(i, key);
			print_heap();
		} else {
			break;
		}
	}
}