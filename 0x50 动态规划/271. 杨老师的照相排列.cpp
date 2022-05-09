#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 31;

int n;
ll f[N][N][N][N][N];

int main() {
	while (cin >> n, n) {
		memset(f, 0, sizeof f);
		f[0][0][0][0][0] = 1;
		int s[10] = {0};
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		for (int a = 0; a <= s[0]; a++) {
			for (int b = 0; b <= min(a, s[1]); b++) {
				for (int c = 0; c <= min(b, s[2]); c++) {
					for (int d = 0; d <= min(c, s[3]); d++) {
						for (int e = 0; e <= min(d, s[4]); e++) {
							ll& v = f[a][b][c][d][e];
							if (a && a - 1 >= b) v += f[a - 1][b][c][d][e];
							if (b && b - 1 >= c) v += f[a][b - 1][c][d][e];
							if (c && c - 1 >= d) v += f[a][b][c - 1][d][e];
							if (d && d - 1 >= e) v += f[a][b][c][d - 1][e];
							if (e) v += f[a][b][c][d][e - 1];
						}
					}
				}
			}
		}
		cout << f[s[0]][s[1]][s[2]][s[3]][s[4]] << endl;
	}
	return 0;
}
