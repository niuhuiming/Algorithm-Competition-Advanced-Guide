#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 9;

string str;
int row[N], col[N], cell[N / 3][N / 3];
int ones[1 << N], mp[1 << N];

int lowbit(int x) {
	return x & -x;
}

int get(int x, int y) {
	return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
	if (cnt == 0) return true;
	
	// 找到可选分支最少的
	int x, y, minv = 10;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (str[i * N + j] == '.') {
				int v = ones[get(i, j)];
				if (v < minv) {
					minv = v;
					x = i, y = j;
				}
			}
		}
	} 
	
	for (int i = get(x, y); i; i -= lowbit(i)) {
		int k = mp[lowbit(i)];
		row[x] -= (1 << k);
		col[y] -= (1 << k);
		cell[x / 3][y / 3] -= (1 << k);
		str[x * N + y] = k + '1';
		
		if (dfs(cnt - 1)) return true;
		
		row[x] += (1 << k);
		col[y] += (1 << k);
		cell[x / 3][y / 3] += (1 << k);
		str[x * N + y] = '.'; 
	}
	return false;
}

int main() {
	for (int i = 1; i < N; i++) {
		mp[1 << i] = i;
	}
	for (int i = 0; i < (1 << N); i++) {
		for (int j = i; j; j -= lowbit(j)) {
			ones[i]++;
		}
	}
	while (cin >> str, str != "end") {
		for (int i = 0; i < N; i++) {
			row[i] = col[i] = (1 << N) - 1;
		}
		for (int i = 0; i < N / 3; i++) {
			for (int j = 0; j < N / 3; j++) {
				cell[i][j] = (1 << N) - 1;
			}
		}
		
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int k = i * N + j;
				if (str[k] != '.') {
					int x = (str[k] - '1');
					row[i] -= (1 << x);
					col[j] -= (1 << x);
					cell[i / 3][j / 3] -= (1 << x);
				} else cnt++;
			}
		}
		dfs(cnt);
		cout << str << endl;
	}
	return 0;
}
