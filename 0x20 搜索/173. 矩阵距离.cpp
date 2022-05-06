#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const int N = 1010;

int n, m;
char g[N][N];
int res[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

bool check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;
}

void dfs() {
	memset(res, -1, sizeof res);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '1') {
				res[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	
	while (q.size()) {
		auto t = q.front();
		q.pop();
		int x = t.first, y = t.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (check(nx, ny) && res[nx][ny] == -1) {
				res[nx][ny] = res[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}
	dfs();
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
