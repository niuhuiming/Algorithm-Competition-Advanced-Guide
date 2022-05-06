#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 110;

int n;
int path[N];

bool dfs(int u, int k) {
	if (u == k) return path[u - 1] == n;
	bool vis[N] = {false};
	for (int i = u - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			int s = path[i] + path[j];
			if (s > n || s < path[u - 1] || vis[s]) continue;
			path[u] = s;
			vis[s] = true;
			if (dfs(u + 1, k)) return true;
		}
	}
	return false;
}

int main() {
	path[0] = 1;
	while (cin >> n, n) {
		int dep = 1;
		while (dfs(1, dep) == false) {
			dep++;
		}
		for (int i = 0; i < dep; i++) {
			cout << path[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
