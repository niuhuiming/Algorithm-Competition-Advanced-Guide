#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 300010;

int n, m;
int a[N];
int l, r;
ll s[N], q[N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	
	ll res = INT_MIN;
	for (int i = 1; i <= n; i++) {
		if (i - q[l] > m) l++;
		res = max(res, s[i] - s[q[l]]);
		while (l <= r && s[q[r]] >= s[i]) {
			r--;
		}
		q[++r] = i;
	}
	cout << res << endl;
	return 0;
} 
