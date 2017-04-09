// Prime factorization in log(n) after Sieve

#include <bits/stdc++.h>
using namespace std;

long long int sp[10000001];
bool b[10000001];

void sieve() {
    sp[2] = 2;
    for(long long int i=4; i<10000001; i+=2) {
        sp[i] = 2;
        b[i] = true;
    }
    for(long long int i=3; i<10000001; i+=2) {
        if(!b[i]) {
            sp[i] = i;
            for(long long int j=i; (j*i)<10000001; j+=2) {
                if(!b[j*i]) {
                    b[j*i] = true;
                    sp[j*i] = i;
                }
            }
        }
    }
}

vector <int> factorize(int k) {
    vector <int> ans;
    while(k>1) {
        ans.push_back(sp[k]);
        k/=sp[k];
    }
    return ans;
}

int main() {

    sieve();
    
	int n;
	cout << "Enter the number: ";
	cin >> n;
	
	vector<int> ans = factorize(n);

	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<endl;
}
