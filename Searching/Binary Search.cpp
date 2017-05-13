# include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number to be searched: ";
    cin >> n;
    
    int l;
    cout << "Enter l of array: ";
    cin >> l;
    
    cout << "Enter the array: ";
    vector<int> a(l);
    for(int i = 0; i < l; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    
    bool f = false;
    int mid, lo = 0, hi = n - 1;
    while(lo < hi) {

        mid = (lo + hi + 1) / 2;

        if(a[mid] == n) {
            f = true;
            break;
        }

        if (a[mid] < n)
            hi = mid;
        else if (a[mid] > n)
            lo = mid + 1;
    }

    if (f)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
}