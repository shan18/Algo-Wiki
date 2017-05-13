// Time complexity: O(N logN)

#include <bits/stdc++.h>
using namespace std;

// Uses Binary Search
int ceil_index(vector<int> &v, int l, int r, int key) {
    while(r-l>1) {
        int m = l + (r-l)/2;
        if(v[m]>=key)
            r = m;
        else
            l = m;
    }
    return r;
}

// Returns the length of the longest increasing subsequence
int longest_increasing_subsequence(vector<int> &v) {
    vector<int> tail(v.size(), 0);
	  int length = 1;   // Keeps track of the length of the subsequence
    tail[0] = v[0];
    for(int i=1; i<v.size(); i++) {
        if(v[i]<tail[0])
          // New smallest value
    	    tail[0] = v[i];
    	  else if(v[i] > tail[length-1])
          // Extends the subsequence
    	    tail[length++] = v[i];
    	  else
          // Replaces v[i] by its next largest value in tail
    	    tail[ceil_index(tail, -1, length-1, v[i])] = v[i];
    }
    return length;
}

int main() {
  int n;
  cout << "Enter the size: ";
  cin >> n;
    
  cout << "Enter the array: ";
	vector<int> a(n);
	for(int i=0; i<n; i++) {
	    cin >> a[i];
	}
	
  cout << "Length of the longest increasing subsequence is: " << longest_increasing_subsequence(a) << endl;
	return 0;
}