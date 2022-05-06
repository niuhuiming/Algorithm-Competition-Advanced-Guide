#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 20;

int n, w;
int c[N], s[N];
int res = 20;

void dfs(int u, int k) {
	if (k >= res) return ;
	if (u == n) {
		res = k;
		return ;
	}
	for (int i = 0; i < k; i++) {
		if (s[i] + c[u] <= w) {
			s[i] += c[u];
			dfs(u + 1, k);
			s[i] -= c[u];
		}
	}
	s[k] = c[u];
	dfs(u + 1, k + 1);
}

int main() {
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c, c + n, greater<int>());
	
	dfs(0, 0);
	cout << res << endl;
	return 0;
}
