#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 1000010;

int n;
ll total;
ll a[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		total += a[i];
	}
	for (int i = 1; i <= n; i++) {
		a[i] -= total / n;
		a[i] += a[i - 1];
	}
	sort(a + 1, a + n + 1);
	
	ll res = 0;
	for (int i = 1; i <= n; i++ ){
		res += abs(a[i] - a[n / 2 + 1]);
	}
	cout << res << endl;
	return 0;
} 
