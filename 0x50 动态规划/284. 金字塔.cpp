#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 310;
const int P = 1e9;

char str[N];
int f[N][N];

int main() {
	cin >> (str + 1);
	int n = strlen(str + 1);
	if (n % 2 == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int len = 1; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			if (l == r) {
				f[l][r] = 1;
			}
			else if (str[l] == str[r]) {
				for (int k = l; k < r; k += 2) {
					if (str[k] == str[r]) {
						f[l][r] = (1ll * f[l][r] + (ll)f[l][k] * f[k + 1][r - 1]) % P;
					}
				}
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}
