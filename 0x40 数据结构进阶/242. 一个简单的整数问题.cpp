#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100010;

int n, m;
int a[N];
ll tr[N];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int c) {
	for (int i = x; i <= n; i += lowbit(i)) {
		tr[i] += c;
	}
}

ll sum(int x) {
	ll res = 0;
	for (int i = x; i; i -= lowbit(i)) {
		res += tr[i];
	}
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		add(i, a[i] - a[i - 1]);
	}
	while (m--) {
		string s;
		int l, r, d, x;
		cin >> s;
		if (s[0] == 'C') {
			cin >> l >> r >> d;
			add(l, d);
			add(r + 1, -d);
		} else {
			cin >> x;
			cout << sum(x) << endl;
		}
	}
	return 0;
}

