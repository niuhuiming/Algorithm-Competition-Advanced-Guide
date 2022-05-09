#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 310;

int n, m;
int h[N], e[N], ne[N], idx;
int w[N];
int f[N][N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
	for (int i = h[u]; i != -1; i = ne[i]) {
		int son = e[i];
		dfs(son);
		for (int j = m - 1; j >= 0; j--) {
			for (int k = 1; k <= j; k++) {
				f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
			}
		} 
	}
	for (int i = m; i; i--) {
		f[u][i] = f[u][i - 1] + w[u];
	}
	f[u][0] = 0;
}

int main() {
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int fa;
		cin >> fa >> w[i];
		add(fa, i);
	}
	m++;
	dfs(0);
	cout << f[0][m] << endl;
	return 0;
}
