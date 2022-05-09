#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100010;

int n;
int h[N];
int a[N], tr[N];
int res[N]; 

int lowbit(int x) {
	return x & -x;
}

void add(int x, int c) {
	for (int i = x; i <= n; i += lowbit(i)) {
		tr[i] += c;
	}
}

int sum(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) {
		res += tr[i];
	}
	return res;
}

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		add(i, 1);
	}
	for (int i = n; i; i--) {
		int l = 1, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (sum(mid) >= h[i] + 1) r = mid;
			else l = mid + 1;
		}
		add(l, -1);
		res[i] = l;
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << endl;
	}
	return 0;
}

