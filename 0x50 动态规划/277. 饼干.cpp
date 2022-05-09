#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 31, M = 5010;

int n, m;
pair<int, int> g[N];
int s[N];
int f[N][M];
int res[N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> g[i].first;
		g[i].second = i;
	}
	sort(g + 1, g + n + 1, greater<pair<int, int>>());
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + g[i].first;
	}
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j >= i) {
				f[i][j] = f[i][j - i];
			}
			for (int k = 1; k <= i && k <= j; k++) {
				f[i][j] = min(f[i][j], f[i - k][j - k] + (s[i] - s[i - k]) * (i - k));
			} 
		} 
	}
	cout << f[n][m] << endl;
	int i = n, j = m, h = 0;
	while (i && j) {
		if (j >= i && f[i][j] == f[i][j - i]) {
			j -= i, h++;
		} else {
			for (int k = 1; k <= i && k <= j; k++) {
				if (f[i][j] == f[i - k][j - k] + (s[i] - s[i - k]) * (i - k)) {
					for (int u = i; u > i - k; u--) {
						res[g[u].second] = 1 + h;
					}
					i -= k;
					j -= k;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
	} 
	return 0;
}
