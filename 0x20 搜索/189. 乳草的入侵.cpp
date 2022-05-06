#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int N = 110;

int n, m;
char g[N][N];
int d[N][N];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int bfs(pii s) {
	memset(d, -1, sizeof d);
	d[s.first][s.second] = 0;
	queue<pair<int, int>> q;
	q.push(s);
	
	int res = 0;
	while (q.size())  {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (g[x][y] == '*') continue;
			if (d[x][y] != -1) continue;
			d[x][y] = d[t.first][t.second] + 1;
			q.push({x, y});
			res = max(res, d[x][y]);
		}
	}
	return res;
}

int main() {
	int x, y;
	cin >> m >> n >> y >> x;
	x = n - x;
	y--;
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}
	cout << bfs({x, y}) << endl;
	return 0;
}
