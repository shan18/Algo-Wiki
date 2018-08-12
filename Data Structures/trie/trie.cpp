/* Implementation of trie with build and search method.
 *
 * Note:
 * You can assume that all inputs consist of lowercase letters a-z.
*/


#include <bits/stdc++.h>
using namespace std;

#define FOR(start, finish) for (int i = start; i < finish; i++)


int trie[1000006][27];
bool leaf[1000006];
int next_value = 1;

void build(string s) {
    int v = 0;
    FOR(0, s.length()) {
        int key = s[i] - 'a';
        if (trie[v][key] == -1)
            trie[v][key] = next_value++;
        v = trie[v][key];
    }
    leaf[v] = true;
}

bool search(string s) {
    int v = 0;
    FOR(0, s.length()) {
        int key = s[i] - 'a';
        if (trie[v][key] == -1) {
            return false;
        }
        v = trie[v][key];
    }
    return leaf[v];
}

int main() {
    
	int n;
	string s;
    memset(trie, -1, sizeof(trie));
    cout << "Enter the number of strings to insert into trie: ";
	cin >> n;
	
	cout << "Enter the strings to insert:" << endl;
	FOR(0, n) {
	    cin >> s;
	    build(s);
	}

	int m;
	cout << "Enter the number of strings to search in trie: ";
	cin >> m;
	
	cout << "Enter the strings to be searched:" << endl;
	FOR(0, m) {
	    cin >> s;
	    cout << search(s) << endl;
	}

	return 0;
}