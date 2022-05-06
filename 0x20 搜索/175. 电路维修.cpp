#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
const int N = 510;

int n, m;
string g[N];
int d[N][N];
bool vis[N][N];

int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
int ix[] = {-1, -1, 0, 0}, iy[] = {-1, 0, 0, -1};
char cs[] = "\\/\\/"; 

int bfs() {
	memset(d, 0x3f, sizeof d);
	memset(vis, false, sizeof vis);
	
	deque<pair<int, int>> dq;
	dq.push_back({0, 0});
	d[0][0] = 0;
	while (dq.size()) {
		auto t = dq.front();
		dq.pop_front();
		int x = t.first, y = t.second;
		if (vis[x][y]) continue;
		vis[x][y] = true;
		
		for (int i = 0; i < 4; i++) {
			int a = x + dx[i], b = y + dy[i];
			int j = x + ix[i], k = y + iy[i];
			if (a < 0 || b < 0 || a > n || b > m) continue;
			int w = 0;
			if (g[j][k] != cs[i]) w = 1;
			if (d[a][b] > d[x][y] + w) {
				d[a][b] = d[x][y] + w;
				if (w == 0) dq.push_front({a, b});
				else dq.push_back({a, b});
			}
		}
	}
	if (d[n][m] == 0x3f3f3f3f) return -1;
	return d[n][m];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> g[i];
		}
		int res = bfs();
		if (res == -1) cout << "NO SOLUTION" << endl;
		else cout << res << endl;
	}
	return 0;
}
