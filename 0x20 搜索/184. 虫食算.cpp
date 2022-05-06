#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 30;

int n;
char eq[3][N];

int q[N], path[N];
bool st[N];

bool check() {
	int t = 0;
	for (int i = n - 1; i >= 0; i--) {
		int a = path[eq[0][i] - 'A'];
		int b = path[eq[1][i] - 'A'];
		int c = path[eq[2][i] - 'A'];
		if (a != -1 && b != -1 && c != -1) {
			if (t == -1) {
				if ((a + b) % n != c && (a + b + 1) % n != c) return false;
				if (i == 0 && a + b >= n) return false;
			} else {
				if ((a + b + t) % n != c) return false;
				if (i == 0 && a + b + t >= n) return false;
				t = (a + b + t) / n;
			}
		} else {
			t = -1;
		}
	}
	return true;
}

bool dfs(int u) {
	if (u == n) return true;
	for (int i = 0; i < n; i++) {
		if (st[i] == false) {
			st[i] = true;
			path[q[u]] = i;
			if (check() && dfs(u + 1)) return true;
			path[q[u]] = -1;
			st[i] = false;
		}
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < 3; i++) {
		cin >> eq[i];
	}
	int k = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			int c = eq[j][i] - 'A';
			if (st[c] == false) {
				st[c] = true;
				q[k++] = c;
			}
		}
	}
	
	memset(st, false, sizeof st);
	memset(path, -1, sizeof path);
	
	dfs(0);
	
	for (int i = 0; i < n; i++) {
		cout << path[i] << ' ';
	}
	return 0;
}
