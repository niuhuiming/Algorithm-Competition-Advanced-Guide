#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
typedef long long ll;
const int N = 100010;

int n;
int h[N];
int l[N], r[N];

void get(int* last) {
	stack<int> s;
	s.push(0);
	for (int i = 1; i <= n; i++) {
		while (h[s.top()] >= h[i]) s.pop();
		last[i] = s.top();
		s.push(i);
	} 
}

int main() {
	h[0] = -1;
	while (cin >> n, n) {
		for (int i = 1; i <= n; i++) {
			cin >> h[i];
		}
		get(l);
		reverse(h + 1, h + n + 1);
		get(r);
		reverse(h + 1, h + n + 1);
		 
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			res = max(res, (ll)h[i] * (n - r[n - i + 1] - l[i]));
		}
		cout << res << endl;
	}
	return 0;
} 
