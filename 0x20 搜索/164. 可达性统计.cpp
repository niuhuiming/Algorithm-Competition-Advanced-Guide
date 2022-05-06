#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;
const int N = 30010;

int n, m;
int d[N];
int h[N], e[N], ne[N], idx;
int seq[N];
bitset<N> f[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) {
			q.push(i);
		}
	}
	int base = 0;
	while (q.size()) {
		int t = q.front();
		q.pop();
		seq[base++] = t;
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (--d[j] == 0) {
				q.push(j);
			}
		}
	}
}

int main() {
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b]++;
	}
	topsort();
	
	for (int k = n - 1; k >= 0; k--) {
		int t = seq[k];
		f[t][t] = 1;
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			f[t] |= f[j];
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << f[i].count() << endl;
	}
	return 0;
}
