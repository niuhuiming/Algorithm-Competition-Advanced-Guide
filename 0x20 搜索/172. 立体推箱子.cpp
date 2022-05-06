#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
const int N = 510;

struct State {
	int x, y, lie;
};

int n, m;
char g[N][N];
int dist[N][N][3];

int d[3][4][3] = {
	{{-2, 0, 2}, {0, 1, 1}, {1, 0, 2}, {0, -2, 1}},
	{{-1, 0, 1}, {0, 2, 0}, {1, 0, 1}, {0, -1, 0}},
	{{-1, 0, 0}, {0, 1, 2}, {2, 0, 0}, {0, -1, 2}}
};

bool check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return g[x][y] != '#';
}

int bfs(State st, State ed) {
	memset(dist, -1, sizeof dist);
	dist[st.x][st.y][st.lie] = 0;
	
	queue<State> q;
	q.push(st);
	while (q.size()) {
		State now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			State nx = {now.x + d[now.lie][i][0], now.y + d[now.lie][i][1], d[now.lie][i][2]};
			int x = nx.x, y = nx.y, lie = nx.lie;
			if (check(x, y) == false) continue;
			if (dist[x][y][lie] != -1) continue;
			if (lie == 0 && g[x][y] == 'E') continue;
			if (lie == 1 && check(x, y + 1) == false) continue;
			if (lie == 2 && check(x + 1, y) == false) continue;
			
			dist[x][y][lie] = dist[now.x][now.y][now.lie] + 1;
			q.push(nx);
		}
	} 
	return dist[ed.x][ed.y][ed.lie];
}

int main() {
	while (cin >> n >> m, n || m) {
		for (int i = 0; i < n; i++) {
			cin >> g[i];
		}
		State st = {-1}, ed;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == 'X' && st.x == -1) {
					st.x = i, st.y = j;
					if (g[i][j + 1] == 'X') st.lie = 1;
					else if (g[i + 1][j] == 'X') st.lie = 2;
					else st.lie = 0;
				} else if (g[i][j] == 'O') {
					ed = {i, j, 0};
				}
			}
		}
		int res = bfs(st, ed);
		if (res == -1) cout << "Impossible" << endl;
		else cout << res << endl;
	}
	return 0;
}
