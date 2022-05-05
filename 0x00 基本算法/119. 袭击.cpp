#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 200010;

struct Node {
	double x, y;
	int type;
};

int n;
Node node[N], tmp[N];

bool cmp(Node a, Node b) {
	return a.x < b.x;
}

bool cmp1(Node a, Node b) {
	return a.y < b.y;
}

double dist(Node a, Node b) {
	if (a.type == b.type) return INT_MAX;
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

double merge(int l, int r) {
	if (l >= r) return INT_MAX;
	int mid = l + r >> 1;
	double res = min(merge(l, mid), merge(mid + 1, r));
	
	double mid_x = node[mid].x;
	int k = 0;
	for (int i = l; i <= r; i++) {
		if (mid_x - res < node[i].x && node[i].x < mid_x + res) {
			tmp[k++] = node[i];
		}
	}
	sort(tmp, tmp + k, cmp1);
	for (int i = 0; i < k; i++) {
		for (int j = i - 1; j >= 0 && tmp[i].y - tmp[j].y < res; j--) {
			res= min(res, dist(tmp[i], tmp[j]));
		}
	} 
	return res;
}
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &node[i].x, &node[i].y);
			node[i].type = 0;
		}
		for (int i = n; i < 2 * n; i++) {
			scanf("%lf%lf", &node[i].x, &node[i].y);
			node[i].type = 1;
		}
		sort(node, node + 2 * n, cmp);
		printf("%.3f\n", merge(0, 2 * n - 1));
	}
	return 0;
} 
