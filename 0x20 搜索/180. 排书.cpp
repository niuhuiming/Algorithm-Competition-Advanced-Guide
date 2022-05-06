#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 20;

int n;
int q[N], w[5][N];

int f() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (q[i] != q[i - 1] + 1) {
			res++;
		}
	}
	return (res + 2) / 3;
}

bool check() {
	for (int i = 0; i < n; i++) {
		if (q[i] != i + 1) {
			return false;
		}
	}
	return true;
}

bool dfs(int dep, int max_dep) {
	if (dep + f() > max_dep) return false;
	if (check()) return true;
	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) {
			for (int k = r + 1; k < n; k++) {
				memcpy(w[dep], q, sizeof q);
				int x, y;
				for (x = r + 1, y = l; x <= k; x++, y++) q[y] = w[dep][x];
				for (x = l; x <= r; x++, y++) q[y] = w[dep][x];
				if(dfs(dep + 1, max_dep)) return true;
				memcpy(q, w[dep], sizeof q);
			}
		} 
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> q[i];
		}
		int dep = 0;
		while (dep < 5 && dfs(0, dep) == false) {
			dep++;
		}
		if (dep >= 5) cout << "5 or more" << endl;
		else cout << dep << endl;
	}
	return 0;
}
