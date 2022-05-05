#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int N = 1000010;
const ull base = 13331;

char s[N];
ull h[N], p[N] = {1, 0};

void getHash() {
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i++) {
		h[i] = h[i - 1] * base + (s[i] - 'a' + 1);
		p[i] = p[i - 1] * base;
	}
}

ull query(int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }

int main() {
	cin >> (s + 1);
	getHash();
	int q;
	cin >> q;
	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (query(l1, r1) == query(l2, r2)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
} 
