#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
const int N = 100010;

int n, m, t;
int row[N], col[N];

ll calc(int a[], int n) {
	ll s[N] = {0};
	for (int i = 1; i <= n; i++) {
		a[i] -= (a[0] / n);
		s[i] = s[i - 1] + a[i];
	}
	sort(s + 1, s + n + 1);
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		res += abs(s[i] - s[(n + 1) / 2]);
	}
	return res;
}

int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		row[x]++;
		col[y]++;
		row[0]++;
		col[0]++;
	} 
	if (row[0] % n == 0 && col[0] % m == 0) {
		cout << "both " << calc(row, n) + calc(col, m) << endl;
	} else if (row[0] % n == 0){
		cout << "row " << calc(row, n) << endl;
	} else if (col[0] % m == 0) {
		cout << "column " << calc(col, m) << endl;
	} else {
		cout << "impossible" << endl;
	}
	return 0;
}
