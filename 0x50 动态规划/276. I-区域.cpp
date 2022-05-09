#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 20;

struct State {
	int i, j, l, r, x, y;
};

int n, m, k;
int w[N][N];
int f[N][N * N][N][N][2][2];
State g[N][N * N][N][N][2][2];

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> w[i][j];
		}
	}
	memset(f, -0x3f3f3f3f, sizeof f);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int l = 1; l <= m; l++) {
				for (int r = l; r <= m; r++) {
					if (j < r - l + 1) continue;
					// ×óÀ©ÕÅÓÒÀ©ÕÅ
					{
						int& vf = f[i][j][l][r][1][0];
						State& vg = g[i][j][l][r][1][0];
						if (j == r - l + 1) vf = 0;
						for (int p = l; p <= r; p++) {
							for (int q = p; q <= r; q++) {
								int val = f[i - 1][j - (r - l + 1)][p][q][1][0];
								if (vf < val) {
									vf = val;
									vg = {i - 1, j - (r - l + 1), p, q, 1, 0};
								}
							}
						}
						for (int u = l; u <= r; u++) {
							vf += w[i][u];
						}
					} 
					// ×óÀ©ÕÅÓÒÊÕËõ 
					{
						int& vf = f[i][j][l][r][1][1];
						State& vg = g[i][j][l][r][1][1];
						for (int p = l; p <= r; p++) {
							for (int q = r; q <= m; q++) {
								for (int y = 0; y <= 1; y++) {
									int val = f[i - 1][j - (r - l + 1)][p][q][1][y];
									if (vf < val) {
										vf = val;
										vg = {i - 1, j - (r - l + 1), p, q, 1, y};
									}
								}
							}
						}
						for (int u = l; u <= r; u++) {
							vf += w[i][u];
						}
					} 
					// ×óÊÕËõÓÒÀ©ÕÅ 
					{
						int& vf = f[i][j][l][r][0][0];
						State& vg = g[i][j][l][r][0][0];
						for (int p = 1; p <= l; p++) {
							for (int q = l; q <= r; q++) {
								for (int x = 0; x <= 1; x++) {
									int val = f[i - 1][j - (r - l + 1)][p][q][x][0];
									if (vf < val) {
										vf = val;
										vg = {i - 1, j - (r - l + 1), p, q, x, 0};
									}
								}
							}
						}
						for (int u = l; u <= r; u++) {
							vf += w[i][u];
						}
					} 
					// ×óÊÕËõÓÒÊÕËõ 
					{
						int& vf = f[i][j][l][r][0][1];
						State& vg = g[i][j][l][r][0][1];
						for (int p = 1; p <= l; p++) {
							for (int q = r; q <= m; q++) {
								for (int x = 0; x <= 1; x++) {
									for (int y = 0; y <= 1; y++) {
										int val = f[i - 1][j - (r - l + 1)][p][q][x][y];
										if (vf < val) {
											vf = val;
											vg = {i - 1, j - (r - l + 1), p, q, x, y};
										}
									}
								}
							}
						}
						for (int u = l; u <= r; u++) {
							vf += w[i][u];
						}
					} 
				}
			}
		}
	}
	
	int res = 0;
	State state;
	for (int i = 1; i <= n; i++) {
		for (int l = 1; l <= m; l++) {
			for (int r = 1; r <= m; r++) {
				for (int x = 0; x <= 1; x++) {
					for (int y = 0; y <= 1; y++) {
						int val = f[i][k][l][r][x][y];
						if (val > res) {
							res = val;
							state = {i, k, l, r, x, y};
						}
					}
				}
			}
		}
	}
	cout << "Oil : " << res << endl;
	while (state.j) {
		for (int i = state.l; i <= state.r; i++) {
			cout << state.i << ' ' << i << endl;
		} 
		state = g[state.i][state.j][state.l][state.r][state.x][state.y];
	}
	return 0;
}
