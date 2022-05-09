#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110, M = 100010;

int n, m;
int v[N], s[N];
int f[M], g[M];

int main() {
	while (cin >> n >> m, n || m) {
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
		}
		memset(f, 0, sizeof f);
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			memset(g, 0, sizeof g);
			for (int j = v[i]; j <= m; j++) {
				if (!f[j] && f[j - v[i]] && g[j - v[i]] < s[i]) {
					f[j] = 1;
					g[j] = g[j - v[i]] + 1;
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= m; i++) {
			res += f[i];
		}
		cout << res << endl;
	}
	return 0;
}

