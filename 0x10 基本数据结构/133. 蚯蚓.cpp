#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100010, M = 7000010;

int n, m, q, u, v, t;
int delta;
int l1, r1, l2, r2, l3, r3;
int q1[N], q2[M], q3[M];

int getMAX() {
	if (q1[l1] >= q2[l2] && q1[l1] >= q3[l3]) {
		return q1[l1++];
	} else if (q2[l2] >= q1[l1] && q2[l2] >= q3[l3]) {
		return q2[l2++];
	} else {
		return q3[l3++];
	}
}

int main() {
	memset(q1, -0x3f, sizeof q1);
	memset(q2, -0x3f, sizeof q2);
	memset(q3, -0x3f, sizeof q3);
	cin >> n >> m >> q >> u >> v >> t;
	r1 = n;
	for (int i = 0; i < n; i++) {
		cin >> q1[i];
	}
	sort(q1, q1 + n, greater<int>());
	
	for (int i = 1; i <= m; i++) {
		int tt = getMAX();
		tt += delta;
		delta += q;
		q2[r2++] = 1ll * tt * u / v - delta;
		q3[r3++] = 1ll * tt - q2[r2 - 1] - 2 * delta;
		if (i % t == 0) {
			cout << tt << ' ';
		} 
	}
	cout << endl;
	for (int i = 1; i <= n + m; i++) {
		int tt = getMAX();
		if (i % t == 0) {
			cout << tt + delta << ' ';
		}
	}
	return 0;
} 
