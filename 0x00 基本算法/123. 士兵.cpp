#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 1000010;

int n;
int x[N], y[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (int i = 1; i <= n; i++) {
		x[i] -= i;
	} 
	sort(x + 1, x + n + 1);
	
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += (abs(x[i] - x[n / 2 + 1]) + abs(y[i] - y[n / 2 + 1]));
	}
	cout << res << endl;
	return 0;
} 
