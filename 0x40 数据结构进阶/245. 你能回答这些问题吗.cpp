#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 500010;

struct Node {
	int l, r;
	int tmax, lmax, rmax, sum;
};

int n, m;
int w[N];
Node tr[N * 4];

void pushup(Node& r, Node& a, Node& b) {
	r.lmax = max(a.lmax, a.sum + b.lmax);
	r.rmax = max(b.rmax, b.sum + a.rmax);
	r.sum = a.sum + b.sum;
	r.tmax = max({a.tmax, b.tmax, a.rmax + b.lmax});
}

void pushup(int u) {
	pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
	if (l == r) {
		tr[u] = {l, r, w[l], w[l], w[l], w[l]};
		return;
	}
	tr[u] = {l, r};
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

Node query(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) return tr[u];
	int mid = tr[u].l + tr[u].r >> 1;
	if (r <= mid) return query(u << 1, l, r);
	else if (l > mid) return query(u << 1 | 1, l, r);
	else {
		Node a = query(u << 1, l, r);
		Node b = query(u << 1 | 1, l, r);
		Node c;
		pushup(c, a, b);
		return c;
	}
}

void modify(int u, int x, int v) {
	if (tr[u].l == x && tr[u]. r == x) {
		tr[u] = {x, x, v, v, v, v};
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (x <= mid) modify(u << 1, x, v);
	else modify(u << 1 | 1, x, v);
	pushup(u);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	build(1, 1, n);
	
	int op, x, y;
	while (m--) {
		cin >> op >> x >> y;
		if (op == 1) {
			if (x > y) swap(x, y);
			cout << query(1, x, y).tmax << endl;
		} else {
			modify(1, x, y);
		}
	}
	return 0; 
}
