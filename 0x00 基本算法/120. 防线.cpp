#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 200010;

struct Node {
	ll s, e, d;
};

int n;
Node node[N];

ll getSum(ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (node[i].s <= x) {
			res += ((min(x, node[i].e) - node[i].s) / node[i].d + 1);
		}
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		ll l = INT_MAX, r = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> node[i].s >> node[i].e >> node[i].d;
			l = min(l, node[i].s);
			r = max(r, node[i].e);
		}
		if (!(getSum(r) & 1)) {
			cout << "There's no weakness." << endl;
		} else {
			while (l < r) {
				int mid = l + r >> 1;
				if (getSum(mid) & 1) r = mid;
				else l = mid + 1;
			}
			cout << l << ' ' << getSum(l) - getSum(l - 1) << endl;
		}
	}
	return 0;
} 
