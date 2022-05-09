#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110;
const int INF = 32768;

int n;
char c[N];
int w[N];
int g[N][N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> c[i] >> w[i];
    	c[i + n] = c[i];
    	w[i + n] = w[i];
	}
	for (int len = 1; len <= n; len++) {
		for (int l = 1; l + len - 1 <= 2 * n; l++) {
			int r = l + len - 1;
			if (len == 1) {
				f[l][r] = g[l][r] = w[l];
			} else {
				f[l][r] = -INF, g[l][r] = INF;
				for (int k = l; k < r; k++) {
					char op = c[k + 1];
					int minl = g[l][k], minr = g[k + 1][r], maxl = f[l][k], maxr = f[k + 1][r];
					if (op == 't') {
						f[l][r] = max(f[l][r], maxl + maxr);
						g[l][r] = min(g[l][r], minl + minr);
					} else {
						int x1 = minl * minr, x2 = maxl * minr, x3 = minl * maxr, x4 = maxl * maxr;
						f[l][r] = max({f[l][r], x1, x2, x3, x4});
						g[l][r] = min({g[l][r], x1, x2, x3, x4});
					}
				}
			}
		}
	}
	int res = -INF;
	for (int i = 1; i <= n; i++) {
		res = max(res, f[i][i + n - 1]);
	}
	cout << res << endl;
	for (int i = 1; i <= n; i++) {
		if (res == f[i][i + n - 1]) {
			cout << i << ' ';
		} 
	}
    return 0;
}
