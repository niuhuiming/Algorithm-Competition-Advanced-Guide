#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1010;
const int M = 20010;
const int C = 110;

struct Node {
	int d, u, c;
	bool operator < (const Node& a) const {
		return d > a.d;
	}
};

int n, m;
int p[N];
int h[N], e[M], w[M], ne[M], idx;
int d[N][C];
bool vis[N][C];

void add(int a, int b, int  c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(int st, int ed, int cap) {
	memset(d, 0x3f, sizeof d);
	memset(vis, false, sizeof vis);
	
	priority_queue<Node> q;
	q.push({0, st, 0});
	d[st][0] = 0;
	while (q.size()) {
		auto t = q.top();
		q.pop();
		if (t.u == ed) return t.d;
		if (vis[t.u][t.c]) continue;
		vis[t.u][t.c] = true;
		if (t.c < cap) {
			if (d[t.u][t.c + 1] > t.d + p[t.u]) {
				d[t.u][t.c + 1] = t.d + p[t.u];
				q.push({d[t.u][t.c + 1], t.u, t.c + 1}); 
			}
		}
		for (int i = h[t.u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (t.c >= w[i]) {
				if (d[j][t.c - w[i]] > t.d) {
					d[j][t.c - w[i]] = t.d;
					q.push({d[j][t.c - w[i]], j, t.c - w[i]});
				}
			}
		}
	}
	return -1;
}

int main() {
	memset(h, -1, sizeof h);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	} 
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int c, s, e;
		scanf("%d%d%d", &c, &s, &e);
		int res = dijkstra(s, e, c);
		if (res == -1) printf("impossible\n");
		else printf("%d\n", res);
	}
	return 0;
}
