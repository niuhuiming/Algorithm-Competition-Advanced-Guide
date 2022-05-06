#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int N = 1010;
const int M = 200010;

int n, m, S, T, K;
int h[N], rh[N], w[M], e[M], ne[M], idx;
int d[N];

void add(int* h, int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
	bool vis[N] = {false};
	memset(d, 0x3f, sizeof d);
	d[T] = 0;
	
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, T});
	while (q.size()) {
		auto t = q.top();
		q.pop();
		int v = t.second;
		if (vis[v]) continue;
		vis[v] = true;
		for (int i = rh[v]; i != -1; i = ne[i]) {
			int j = e[i];
			if (d[j] > d[v] + w[i]) {
				d[j] = d[v] + w[i];
				q.push({d[j], j});
			}
		}
	}
}

int astar() {
	int cnt[N] = {0};
	priority_queue<piii, vector<piii>, greater<piii>> q;
	q.push({d[S], {0, S}});
	while (q.size()) {
		auto t = q.top();
		q.pop();
		int v = t.second.second;
		int dist = t.second.first;
		cnt[v]++;
		if (cnt[T] == K) return dist;
		for (int i = h[v]; i != -1; i = ne[i]) {
			int j = e[i];
			if (cnt[j] < K) {
				q.push({dist + w[i] + d[j], {dist + w[i], j}});
			}
		}
	}
	return -1;
}

int main() {
	memset(h, -1, sizeof h);
	memset(rh, -1, sizeof rh);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(h, a, b, c);
		add(rh, b, a, c);
	}
	cin >> S >> T >> K;
	if (S == T) K++;
	
	dijkstra();
	
	cout << astar() << endl;
	return 0;
}
