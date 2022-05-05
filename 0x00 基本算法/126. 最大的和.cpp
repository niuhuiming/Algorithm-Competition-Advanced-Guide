#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 110;

int n;
int a[N][N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			a[i][j] += a[i - 1][j];
		} 
	}
	int res = INT_MIN;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int last = 0;
			for (int k = 1; k <= n; k++) {
				last = max(last, 0) + a[j][k] - a[i - 1][k];
				res = max(res, last);
			}
		}
	}
	cout << res << endl;
	return 0;
} 
