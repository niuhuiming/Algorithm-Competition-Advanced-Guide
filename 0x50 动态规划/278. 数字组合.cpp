#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 10010;

int n, m;
int a[N];
int f[N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= a[i]; j--) {
			f[j] += f[j - a[i]];
		}
	}
	cout << f[m] << endl;
	return 0;
}
