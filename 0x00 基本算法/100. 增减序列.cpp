#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100010;

int n;
ll a[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int pos = 0, neg = 0;
	for (int i = n; i >= 2; i--) {
		a[i] = a[i] - a[i - 1];
		if (a[i] < 0) neg += a[i];
		else pos += a[i];
	} 
	cout << max(pos, -neg) << endl << abs(pos + neg) + 1 << endl;
	return 0;
}
