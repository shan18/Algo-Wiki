#include <bits/stdc++.h>
using namespace std;


int kadane(vector<int> a) {
	int current_max = a[0], global_max = a[0];
	for(int i=1; i < a.size(); i++) {
		current_max = max(current_max + a[i], a[i]);
		if(current_max > global_max)
			global_max = current_max;
	}
	return global_max;
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0; i < n; i++)
		cin >> a[i];
	
	int max_sum = kadane(a);
	cout << max_sum << endl;
}
