#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 5010;

int n, r;
int mp[N][N];

int main() {
	cin >> n >> r;
	r = min(r, 5005);
	for (int i = 0; i < n; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		mp[x + 1][y + 1] += w;
	}
	for (int i = 1; i <= 5005; i++) {
		for (int j = 1; j <= 5005; j++) {
			mp[i][j] += (mp[i][j - 1] + mp[i - 1][j] - mp[i - 1][j - 1]);
		}
	}
	int res = 0;
	for (int i = r; i <= 5005; i++) {
		for (int j = r; j <= 5005; j++) {
			res = max(res, mp[i][j] - mp[i - r][j] - mp[i][j - r] + mp[i - r][j - r]);
		}
	}
	cout << res << endl;
	return 0;
}
