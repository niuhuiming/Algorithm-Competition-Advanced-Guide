#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 210;
const int M = 810;
const int base = 400;

int n, m;
int p[N], d[N];
int f[N][21][M];
int res[N];

int main() {
	int T = 1;
	while (cin >> n >> m, n || m) {
		for (int i = 1; i <= n; i++) {
			cin >> p[i] >> d[i];
		}
		memset(f, -0x3f, sizeof f);
		f[0][0][base] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				for (int k = 0; k < M; k++) {
					f[i][j][k] = f[i - 1][j][k];
					int t = k - (p[i] - d[i]);
					if (t < 0 || t >= M) continue;
					if (j < 1) continue;
					f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][t] + p[i] + d[i]);
				}
			}
		}
		
		int v = 0;
		while (f[n][m][base - v] < 0 && f[n][m][base + v] < 0) {
			v++;
		}
		if (f[n][m][base - v] > f[n][m][base + v]) {
			v = base - v;
		} else {
			v = base + v;
		}
		
		int cnt = 0;
		int i = n, j = m, k = v;
		while (j) {
			if (f[i][j][k] == f[i - 1][j][k]) {
				i--;
			} else {
				res[cnt++] = i;
				k -= (p[i] - d[i]);
				i--;
				j--;
			}
		}
		
		int sp = 0, sd = 0;
		for (int i = 0; i < cnt; i++) {
			sp += p[res[i]];
			sd += d[res[i]];
		}
		 printf("Jury #%d\n", T ++ );
         printf("Best jury has value %d for prosecution and value %d for defence:\n", sp, sd);
         sort(res, res + cnt);
         for (int i = 0; i < cnt; i ++ ) 
             printf(" %d", res[i]);
         puts("\n");
	}
	return 0;
}
