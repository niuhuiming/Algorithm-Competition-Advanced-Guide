#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 25;

int op[8][7] = {{0, 2, 6, 11, 15, 20, 22},    {1, 3, 8, 12, 17, 21, 23},
                {10, 9, 8, 7, 6, 5, 4},       {19, 18, 17, 16, 15, 14, 13},
                {23, 21, 17, 12, 8, 3, 1},    {22, 20, 15, 11, 6, 2, 0},
                {13, 14, 15, 16, 17, 18, 19}, {4, 5, 6, 7, 8, 9, 10}};
int center[] = {6, 7, 8, 11, 12, 15, 16, 17};
int opposite[] = {5, 4, 7, 6, 1, 0, 3, 2};

int q[N];
int path[110];

bool check() {
	for (int i = 1; i < 8; i++) {
		if (q[center[i]] != q[center[0]]) {
			return false;
		}
	}
	return true;
}

int f() {
	int sum[4] = {0};
	for (int i = 0; i < 8; i++) {
		sum[q[center[i]]]++;
	}
	int s = 0;
	for (int i = 1; i <= 3; i++) {
		s = max(s, sum[i]);
	}
	return 8 - s;
}

void operate(int x) {
	int t = q[op[x][0]];
	for (int i = 0; i < 6; i++) {
		q[op[x][i]] = q[op[x][i + 1]];
	}
	q[op[x][6]] = t;
}

bool dfs(int dep, int max_dep, int last) {
	if (dep + f() > max_dep) return false;
	if (check()) return true;
	for (int i = 0; i < 8; i++) {
		if (last == opposite[i]) continue;
		operate(i);
		path[dep] = i;
		if (dfs(dep + 1, max_dep, i)) return true;
		operate(opposite[i]);
	}
	return false;
}

int main() {
	while (cin >> q[0], q[0]) {
		for (int i = 1; i < 24; i++) {
			cin >> q[i];
		}
		int dep = 0;
		while (dfs(0, dep, -1) == false) {
			dep++;
		}
		if (dep == 0) cout << "No moves needed";
		else {
			for (int i = 0; i < dep; i++) {
				cout << (char)('A' + path[i]);
			}
		}
		cout << endl << q[6] << endl;
	}
	return 0;
}
