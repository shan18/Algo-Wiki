/* The following code uses C++ to implement a priority queue using a min heap.
 * It is a min priority queue which has the element with the smallest key at the front.
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

void min_heapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l < heap_size && a[l] < a[i])
		smallest = l;
	if (r < heap_size && a[r] < a[smallest])
		smallest = r;

	if (smallest != i) {
		iter_swap(a.begin()+smallest, a.begin()+i);
		min_heapify(smallest);
	}
}

int heap_minimum() {
	if (heap_size < 1) {
		return -1;
	}
	return a[0];
}

int heap_extract_min() {
	if (heap_size < 1) {
		cout << "Heap Underflow!" << endl;
		return -1;
	}
	int min = a[0];
	a[0] = a[heap_size - 1];
	heap_size--;
	min_heapify(0);
	return min;
}

void heap_decrease_key(int i, int key) {
	if (key > a[i]) {
		cout << "The new key is greater than the current key!" << endl;
		return;
	}
	a[i] = key;
	while (i > 0 && a[parent(i)] > a[i]) {
		iter_swap(a.begin()+parent(i), a.begin()+i);
		i = parent(i);
	}
}

void min_heap_insert(int key) {
	if (heap_size < 1) {
		a.push_back(key);
		heap_size++;
		return;
	}
	if (++heap_size > a.size())
		a.push_back(key + 10);	// Can be any value greater than the key
	else
		a[heap_size - 1] = key + 10;	// Can be any value greater than the key

	heap_decrease_key(heap_size - 1, key);
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
			 << "2. Minimum key" << endl
			 << "3. Extract the element with minimum key" << endl
			 << "4. Decrease the key value of an element" << endl
			 << "5. Exit" << endl << endl;
		
		int ch;
		cin >> ch;

		if (ch == 1) {
			int key;
			cout << "Enter the key: ";
			cin >> key;
			min_heap_insert(key);
			print_heap();
		} else if (ch == 2) {
			int m = heap_minimum();
			if (m == -1)
				cout << "Queue is empty\n" << endl;
			else
				cout << m << endl << endl;
		} else if (ch == 3) {
			heap_extract_min();
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
			heap_decrease_key(i, key);
			print_heap();
		} else {
			break;
		}
	}
}