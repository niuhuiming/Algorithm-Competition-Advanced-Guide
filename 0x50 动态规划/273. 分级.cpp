#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2010;

int n;
int a[N], b[N];
int f[N][N];

int solve() {
	for (int i = 1; i <= n; i++) {
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		int minv = 0x3f3f3f3f;
		for (int j = 1; j <= n; j++) {
			minv = min(minv, f[i - 1][j]);
			f[i][j] = minv + abs(a[i] - b[j]);
		}
	}
	int res = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		res = min(res, f[n][i]);
	}
	return res;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int res = solve();
	reverse(a + 1, a + n + 1);
	res = min(res, solve());
	cout << res << endl;
	return 0;
}
