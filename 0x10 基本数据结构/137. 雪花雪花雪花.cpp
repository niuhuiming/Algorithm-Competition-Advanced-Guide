#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef unsigned long long ull;
const int N = 10010;
const ull BASE = 13331;
const ull P = 1000000009;

int n;
map<ull, bool> mp;

int get_min(int* s) {
	int n = 6;
	for (int i = 1; i <= n; i++) s[n + i] = s[i];
	int i = 1, j = 2, k;
	while (i <= n && j <= n) {
		for (k = 0; k < n && s[i + k] == s[j + k]; k++) {};
		if (k == n) break;
		if (s[i + k] > s[j + k]) {
			i = i + k + 1;
			if (i == j) i++;
		} else {
			j = j + k + 1;
			if (i == j) j++;
		}
	}
	return min(i, j);
}

ull get_hash(int* a, int p) {
	ull hash = 1;
	for (int j = p; j < p + 6; j++) {
		hash = hash * a[j] * BASE;
		hash = hash % P;
	}
	return hash;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a[15] = {0};
		for (int i = 1; i <= 6; i++) {
			cin >> a[i];
		}
		int p = get_min(a);
		ull hash = get_hash(a, p);
		if (mp[hash]) {
			cout << "Twin snowflakes found." << endl;
			return 0;
		} else mp[hash] = true;
		
		reverse(a + 1, a + 7);
		p = get_min(a);
		ull hash2 = get_hash(a, p);
		if (hash != hash2) {
			if (mp[hash2]) {
				cout << "Twin snowflakes found." << endl;
				return 0;
			} else mp[hash2] = true;
		}
	}
	cout << "No two snowflakes are alike." << endl;
	return 0;
} 
