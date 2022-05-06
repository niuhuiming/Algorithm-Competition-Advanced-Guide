#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int N = 160;

int n, m;
char g[N][N];
int d[N][N];

int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

int bfs(pii s, pii e) {
	memset(d, -1, sizeof d);
	queue<pii> q;
	q.push(s);
	d[s.first][s.second] = 0;
	while (q.size()) {
		pii t = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (g[x][y] == '*') continue;
			if (d[x][y] != -1) continue;
			d[x][y] = d[t.first][t.second] + 1;
			if (x == e.first && y == e.second) return d[x][y];
			q.push({x, y});
		}
	}
	return -1;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}
	
	pii st, ed;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 'K') st = {i, j};
			else if (g[i][j] == 'H') ed = {i, j};
		}
	}
	cout << bfs(st, ed) << endl;
	return 0;
}
