#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100010;

int n, m;
ll a[N];
ll tr1[N], tr2[N];

int lowbit(int x) {
	return x & -x;
}

void add(ll tr[], int x, ll c) {
	for (int i = x; i <= n; i += lowbit(i)) {
		tr[i] += c;
	}
}

ll sum(ll tr[], int x) {
	ll res = 0;
	for (int i = x; i; i -= lowbit(i)) {
		res += tr[i];
	}
	return res;
}

ll pre_sum(int x) {
	return sum(tr1, x) * (x + 1) - sum(tr2, x); 
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		add(tr1, i, a[i] - a[i - 1]);
		add(tr2, i, i * (a[i] - a[i - 1]));
	}
	while (m--) {
		string op;
		int l, r, d;
		cin >> op >> l >> r;
		if (op[0] == 'C') {
			cin >> d;
			add(tr1, l, d);
			add(tr1, r + 1, -d);
			add(tr2, l, 1ll * l * d);
			add(tr2, r + 1, 1ll * (r + 1) * (-d));
		} else {
			cout << pre_sum(r) - pre_sum(l - 1) << endl;
		}
	}
	return 0;
}

