#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 65;

int n, m;
int st[N];
int cnt, len;
bool vis[N];

bool dfs(int now, int cur, int last) {
	if (now > cnt) return true;
	if (cur == len) return dfs(now + 1, 0, 0);
	for (int i = last; i < m; i++) {
		if (vis[i] == true) continue;
		if (cur + st[i] <= len) {
			vis[i] = true;
			if (dfs(now, cur + st[i], i + 1)) return true;
			vis[i] = false;
			if (cur == 0 || cur + st[i] == len) return false;
			int fail = st[i];
			while (i < m && st[i] == fail) i++;
			i--;
		}
	}
	return false;
}

int main() {
	while (cin >> n, n) {
		m = 0;
		int sumlen = 0, maxlen = -1;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x > 50) continue;
			st[m++] = x;
			sumlen += x;
			maxlen = max(maxlen, x);
		}
		sort(st, st + m, greater<int>());
		for (len = maxlen; len <= sumlen; len++) {
			if (sumlen % len != 0) continue;
			cnt = sumlen / len;
			memset(vis, false, sizeof vis);
			if (dfs(1, 0, 0)) {
				cout << len << endl;
				break;
			}
		}
	}
	return 0;
}
