#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 210, M = 1010;

int n, m;
int w[N][N];
int p[M];
int f[M][N][N];

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> w[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	memset(f, 0x3f, sizeof f);
	p[0] = 3;
	f[0][1][2] = 0;
	for (int i = 0; i < n; i++) {
		for (int x = 1; x <= m; x++) {
			for (int y = 1; y <= m; y++) {
				int z = p[i], u = p[i + 1], v = f[i][x][y];
				if (x == y || x == z || y == z) continue;
				f[i + 1][y][z] = min(f[i + 1][y][z], v + w[x][u]);
				f[i + 1][x][z] = min(f[i + 1][x][z], v + w[y][u]);
				f[i + 1][x][y] = min(f[i + 1][x][y], v + w[z][u]);
			}
		}
	}
	int res = 0x3f3f3f3f;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			res = min(res, f[n][i][j]);
		}
	}
	cout << res << endl;
	return 0;
}
