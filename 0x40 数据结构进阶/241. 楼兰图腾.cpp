#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 200010;

int n;
int a[N];
int tr[N];
int Greater[N], lower[N];

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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int y = a[i];
		add(y, 1);
		Greater[i] = sum(n) - sum(y);
		lower[i] = sum(y - 1);
	}
	memset(tr, 0, sizeof tr);
	ll res1 = 0, res2 = 0;
	for (int i = n; i; i--) {
		int y = a[i];
		add(y, 1);
		res1 += Greater[i] * (ll)(sum(n) - sum(y));
		res2 += lower[i] * (ll)sum(y - 1);
	}
	cout << res1 << ' ' << res2 << endl;
	return 0;
}

