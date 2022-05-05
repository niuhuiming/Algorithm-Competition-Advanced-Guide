#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100010;

int n, m;
string op[N];
int t[N];

int calc(int p, int now) {
	for (int i = 0; i < n; i++) {
		int x = t[i] >> p & 1;
		if (op[i][0] == 'A') now &= x;
		else if (op[i][0] == 'O') now |= x;
		else now ^= x; 
	} 
	return now;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> op[i] >> t[i];
	}
	int res = 0, val = 0;
	for (int i = 30; i >= 0; i--) {
		int res0 = calc(i, 0);
		int res1 = calc(i, 1);
		if (res0 < res1 && val + (1 << i) <= m) {
			val += (1 << i), res += (res1 << i);
		} else res += (res0 << i);
	} 
	cout << res << endl;
	return 0;
} 
