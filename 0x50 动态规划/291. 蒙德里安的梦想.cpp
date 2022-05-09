#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 12;
const int M = 1 << N;

int n, m;
ll f[N][M];
vector<int> state[M];
bool st[M];

int main() {
	while (cin >> n >> m, n || m) {
		for (int i = 0; i < 1 << n; i++) {
			int cnt = 0;
			bool is_vaild = true;
			for (int j = 0; j < n; j++) {
				if (i >> j & 1) {
					if (cnt & 1) {
						is_vaild = false;
						break;
					}
					cnt = 0;
				} else {
					cnt++;
				}
			}
			if (cnt & 1) {
				is_vaild = false;
			}
			st[i] = is_vaild;
		}
		for (int i = 0; i < 1 << n; i++) {
			state[i].clear();
			for (int j = 0; j < 1 << n; j++) {
				if ((i & j) == 0 && st[i | j]) {
					state[i].push_back(j);
				}
			}
		} 
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < 1 << n; j++) {
				for (int k : state[j]) {
					f[i][j] += f[i - 1][k];
				}
			}
		}
		cout << f[m][0] << endl;
	}
	return 0;
}
