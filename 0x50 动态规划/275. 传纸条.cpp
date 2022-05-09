#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 55;

int n, m;
int w[N][N];
int f[N << 1][N][N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> w[i][j];
		}
	}
	for (int k = 2; k <= n + m; k++) {
		for (int i = 1; i < k; i++) {
			for (int j = 1; j < k; j++) {
				int& v = f[k][i][j];
				int tmp = w[i][k - i];
				if (i != j) tmp += w[j][k - j];
				v = max({v, f[k - 1][i][j], f[k - 1][i - 1][j], f[k - 1][i][j - 1], f[k - 1][i - 1][j - 1]});
				v += tmp;
			}
		}
	}
	cout << f[n + m][n][n] << endl;
	return 0;
}
