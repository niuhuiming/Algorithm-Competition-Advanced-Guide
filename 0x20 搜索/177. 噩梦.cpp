#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
const int N = 810;

int n, m;
string g[N];
int st[N][N];
pair<int, int> ghost[2];

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

bool check(int x, int y, int step) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	if (g[x][y] == 'X') return false;
	for (int i = 0; i < 2; i++) {
		if (abs(x - ghost[i].first) + abs(y - ghost[i].second) <= 2 * step) {
			return false;
		}
	}
	return true;
}

int bfs() {
	memset(st, 0, sizeof st);
	queue<pair<int, int>> qb, qg;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 'M') qb.push({i, j});
			else if (g[i][j] == 'G') qg.push({i, j});
			else if (g[i][j] == 'Z') ghost[cnt++] = {i, j};
		}
	}
	
	int step = 0;
	while (qb.size() || qg.size()) {
		step++;
		for (int i = 0; i < 3; i++) {
			int len = qb.size();
			for (int j = 0; j < len; j++) {
				auto t = qb.front();
				qb.pop();
				int x = t.first, y = t.second;
				if (check(x, y, step) == false) continue;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (check(nx, ny, step) == false) continue;
					if (st[nx][ny] == 2) return step;
					else if (st[nx][ny] == 0) {
						st[nx][ny] = 1;
						qb.push({nx, ny});
					}
				}
			}
		}
		for (int i = 0; i < 1; i++) {
			int len = qg.size();
			for (int j = 0; j < len; j++) {
				auto t = qg.front();
				qg.pop();
				int x = t.first, y = t.second;
				if (check(x, y, step) == false) continue;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (check(nx, ny, step) == false) continue;
					if (st[nx][ny] == 1) return step;
					else if (st[nx][ny] == 0) {
						st[nx][ny] = 2;
						qg.push({nx, ny});
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> g[i];
		}
		cout << bfs() << endl;
	}
	return 0;
}
